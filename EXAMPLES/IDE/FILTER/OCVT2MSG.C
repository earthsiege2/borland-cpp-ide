/*
   ovct2Msg.C      copyright (c) 1992 Borland International
*/

#include "StdTypes.H"
#include "TranType.H"
#include "ToolApi.H"
#include "filtrc.h"

#include <stdlib.h>
#include <mem.h>
#include <dos.h>
#include <dir.h>
#include <string.h>

#include <windows.h>

// Name the intermediate "PIPE" through which output will be captured
#define PIPEID "c:\\$$PIPE$$.TC$"

int posted = 0;

/* Declare an array of function pointers to store the IDE tool API */
IDE_ToolAPIFunc IDE_ToolAPI[IDE_NumFunctions];

/* Global variables use to parse program output */
HINSTANCE  globInst;

FileHandle Pipefh;

HMEM       hBuffer;
LPSTR      Buffer;
WORD       curpos;
WORD       bufLen;

char       inLine[133];
LPSTR      lineptr;

/*
  InitBuffer - allocate memory for filtering the piped output from ovct to the IDE
*/
void InitBuffer( void )
{
  hBuffer = IDE_memalloc( MEM_MOVEABLE, 8192 );
  Buffer = IDE_memlock( hBuffer );
  bufLen = 0;
  curpos = 0;
}

/*
  ReleaseBuffer - cleanup allocated buffers and open file handles
*/
void ReleaseBuffer( void )
{
  /* cleanup allocated buffers */
  IDE_memunlock( hBuffer );
  IDE_memfree( hBuffer );
  IDE_Close( Pipefh );

  /* delete the pipe */
  IDE_Delete( PIPEID );
}

/*
   nextchar - returns the next character from the pipe input

   returns: next character from the pipe associated with handle Pipefh
*/
char nextchar( void )
{
  if (curpos < bufLen)
  {
    return Buffer[curpos++];
  }
  Buffer[0] = '\0';
  bufLen = IDE_Read( Pipefh, Buffer, 7000 );
  if (bufLen == 0)
    return 0;
  curpos = 0;
  return nextchar();
}

/*
  GetLine - get the next line of text from the pipe

  returns: far pointer to string containing next line of text from the current opened
	   pipe file
*/
LPSTR GetLine( void )
{
  char ch;
  int  count;

  lineptr = inLine;
  count = 0;
  while (((ch = nextchar()) != '\x0D') && (ch != '\x0A') && (ch != 0) && (count<133))
  {
    *lineptr = ch;
    lineptr++;
	 count++;
  }
  if (count == 133)
  {
	 strcpy( &inLine[129], "......" );
  }
  if ((lineptr == inLine) && (ch == 0))
  {
    return NULL;
  }
  *lineptr = '\0';
  return inLine;
}

/*
  ProcessLine - dissect line of input and post it as a message to the IDE

  Input:  LPSTR line    the line to dissect and post
*/
char CurFile[MAXPATH];

void ProcessLine( LPSTR Line )
{
  unsigned   i;
  char       *s, *file, *lineno;
  
  Msg M;

  /* if blank line, return */
  while( *Line && ( (*Line == '\r') || (*Line == '\n') ) )\
  {
    Line++;
  }
  
  if( *Line == '\0' )
  {
    return;
  }

  // If line begins with Error or Warning or Fatal we want it
  if (!strncmp( Line, "Error", 5 ) ||      
      !strncmp( Line, "Fatal", 5 ) ||
      !strncmp( Line, "Warning", 7 ))
  {
    // get by the beginning
    s = Line;
    while ((*s != '\0') && 
           (*s != ' '))
           {
             s++;
           }
    if (!*s)
    {
      return;  // no file name
    }
    s++;
    // should be pointing at a filename
    file = s;
  
    // get to next space
    while ((*s != '\0') && 
           (*s != ' '))
           {
             s++;
           }
    if (*s==' ')
    {
      // found end of name
      *s = '\0';  // delimit filename 
      s++;
    
      // should be line number
      lineno = s;
    
      // find end of number
      while ((*s != '\0') && 
             (*s != ':'))
             {
               s++;
             }
      if (*s == ':')
      {
        // found end of number
        *s='\0';  // delimit line number
        s++;
        // set the line number
        i = atoi( lineno );
      }
      else
      {
        // didn't find a number, send 0
        i=0;
      }
    }
    
    // whatever is left must be the error
    M.message = s;
    M.filename = file;
    M.column = 1;
    M.line = i;

    IDE_PostMessage( CUR_MSG_GROUP, &M );
    posted++;
  }
}

/*
  FilterToIDE - Open the pipe output from the program, read and post each line
		to the IDE
*/
void FilterToIDE( void )
{
  LPSTR line;

  Pipefh = IDE_Open( PIPEID, READ_WRITE );
  if (Pipefh < 0)
  {
    char error[100];
    LoadString( globInst, IDS_CANNOTFILTER, error, sizeof(error));
    IDE_ErrorBox( error );
    return;
  }

  InitBuffer();

  while ((line = GetLine()) != NULL)
  {
    ProcessLine( line );
  }

  ReleaseBuffer();
}

/*
  CheckVersion - Check IDE version
*/
BOOL CheckVersion( void )
{
  // If the DLL is specific to a particular version of the IDE
  // or if it only works for DOS platform or Windows Platform
  // this is the place to check.

  return 1;
}

/*
   Run  -  exported entry point to the filter DLL

   Input:  pTransferBlock TransBlock    contains information about the program to
					be run, its command line, and the IDE tool API
*/
int far pascal _export Run( pTransferBlock TransBlock )
{
  // Store the IDE tool API
  memcpy( IDE_ToolAPI, TransBlock->IDE_ToolAPI, sizeof(IDE_ToolAPI) );

  if (!CheckVersion())
  {
    return NO_TASK;
  }

  // Try to run ovct.COM capturing output to an intermediate file
  IDE_CaptureToPipe( TransBlock->program,
		     TransBlock->cmdline,
		     PIPEID );

  // post the captured output to the IDE
  FilterToIDE();

  return posted;
}

#pragma argsused
int far pascal LibMain( HINSTANCE hInstance, WORD wDataSegment,
			WORD wHeapSize, LPSTR lpszCmdLine )
{
  globInst = hInstance;
  return 1;
}

#pragma argsused
int FAR PASCAL WEP ( int bSystemExit )
{
    return 1;
}

