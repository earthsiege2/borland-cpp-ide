/*
   HC312Msg.C      copyright (c) 1993 Borland International
*/

#include "ToolApi.H"  // Borland IDE tool dll interface
#include "filtrc.h"

#include <stdlib.h>
#include <ctype.h>
#include <mem.h>
#include <dos.h>
#include <dir.h>
#include <string.h>

#include <windows.h>

// Name the intermediate "PIPE" through which output will be captured
#define PIPEID "C:\\$$PIPE$$.TC$"

/* Declare an array of function pointers to store the IDE tool API */
IDE_ToolAPIFunc IDE_ToolAPI[IDE_NumFunctions];

/* Global variables use to parse program output */
HINSTANCE globInst;

char WarningText[] = "Warning";
char ErrorText[]   = "Error";

char     CurFile[MAXPATH];       /* Current file in message window */

FileHandle Pipefh;

HMEM       hBuffer;
LPSTR      Buffer;
WORD       curpos;
WORD       bufLen;

char       inLine[150];
LPSTR      lineptr;

int numFatals   = 0;
int numErrors   = 0;
int numWarnings = 0;

/*
  InitBuffer - allocate memory for filtering the piped output to the IDE
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
  IDE_memunlock( hBuffer );
  IDE_memfree( hBuffer );
  IDE_Close( Pipefh );
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
	 strcpy( &inLine[125], "......" );
  }
  if ((lineptr == inLine) && (ch == 0))
  {
    return NULL;
  }
  *lineptr = '\0';
  return inLine;
}

/*
HC31 error and warning lines are of the form:

  Warning: ####: line...## of file.nam : Message text

*/
void ProcessLine( LPSTR Line )
{
  char *s;
  char *p;
  int havePost = 0;
  long lineno;
  Msg M;
  
  // first trick is that the output is garbled due to conio type output
  // being captured.  Problems can be fixed if null terminate at the text
  // "Microsoft"
  if ((s = strstr(Line, "Microsoft")) != NULL)
  {
    *s='\0';
  }
  if (strncmp( Line, ErrorText, strlen(ErrorText)) == 0)
  {
    // it is an error
    numErrors++;
    havePost = 1;
  }
  if (strncmp( Line, WarningText, strlen(WarningText)) == 0)
  {
    // it is a warning
    
    numWarnings++;
    havePost = 1;
  }  
  if (havePost)
  {
    // have a line to parse
    if ((s = strchr(Line, ':')) != NULL)
    {
      s++;
      // located : following error number
      if (!strncmp( s, " line", 5 ))
      {
        // found the " line " text
        s+=5;
        while (*s == '.')
        {
          // get past any .'s
          s++;
        }
        if ((p = strstr(s, " of")) != NULL)
        {
          // found the " of" text, now s points to line number text
          *p = '\0';
          // convert to long
          lineno = atol( s );
          p+=4;
          s = strstr(p, " : ");
          *s = '\0';
          s+=2;
        }
      }
      else
      {
        // error or warning, but no line and fname
        p = NULL;    // set fname ptr to NULL
        lineno = 0;  // line to 0
      }
      // OK, now lineno == line
      // p == filename
      // s == error
      M.message  = s;
      M.filename = p;
      M.column = 1;
      M.line = (unsigned)lineno;
      IDE_PostMessage(CUR_MSG_GROUP, &M);
    }
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
   Run  -  exported entry point to the filter DLL

   Input:  pTransferBlock TransBlock    contains information about the program to
					be run, its command line, and the IDE tool API
*/
int far pascal _export Run( pTransferBlock TransBlock )
{
  // Store the IDE tool API
  memcpy( IDE_ToolAPI, TransBlock->IDE_ToolAPI, sizeof(IDE_ToolAPI) );

  // Try to run program capturing output to an intermediate file
  IDE_CaptureToPipe( TransBlock->program,
		     TransBlock->cmdline,
		     PIPEID );

  // post the captured output to the IDE
  FilterToIDE();

  // return appropriate code for 
  if (numFatals)
  {
    return toolFatalError;
  }
  if (numErrors)
  {
    return toolErrors;
  }
  if (numWarnings)
  {
    return toolWarnings;
  }
  return toolSuccess;
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

