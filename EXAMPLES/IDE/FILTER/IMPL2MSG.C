/*
   Impl2Msg.C      copyright (c) 1993 Borland International
*/

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

char NewFileText[] = "File ";

int WarnCount = 0;
int ErrorCount = 0;
int FatalCount = 0;

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
  ProcessLine - dissect line of input and post it as a message to the IDE

  Input:  LPSTR line    the line to dissect and post
*/
char CurFile[MAXPATH];

void ProcessLine( LPSTR Line )
{
  static int  HavePutFile = FALSE;
  unsigned    HasFileAndLineNumber = FALSE;
  char       *s;
  unsigned    i;
  Msg         M;

  if (Line[0] == '\0')                            /* ignore blank line */
    return;

  if (Line[0] == '\x0A')
    return;

  if( strncmp( Line, "Warning", 7 ) == 0 )      
  {                                             /* we have a warning line */
    Line += 7;                                  /* flush "Warning" */
    if( *Line != ':' )                          /* ':' doesn't follow */
      HasFileAndLineNumber = TRUE;              /* so file, line present */
    
    WarnCount++;
  }
  else if( strncmp( Line, "Error", 5 ) == 0 )   
  {                                             /* we have an error line */
    Line += 5;                                  /* flush "Error" */
    if( *Line != ':' )                          /* ':' doesn't follow */
      HasFileAndLineNumber = TRUE;              /* so file, line present */
    
    ErrorCount++;
  }
  else if( strncmp( Line, "Fatal error", 11 ) == 0 )   
  {                                             /* we have a fatal line */
    Line += 11;                                 /* just post */
    M.message = Line;
    M.filename = NULL;
    M.column = 1;
    M.line = 1;
    IDE_PostMessage( CUR_MSG_GROUP, &M );
    FatalCount++;
    return;    
  }
  else                                          /* not an error line */
    return;

  if( HasFileAndLineNumber )
  {                                      /* need to process them */
    while( *Line == ' ' )                /* flush white-space until */
      Line++;                            /*  Line points to the filename */

    s = Line;                            
    while( *s != ' ' )                   /* s points to space after */
      s++;                               /*  filename */
    *s = '\0';                           /* Replace space with null */

    if (strcmp(Line,CurFile) != 0)       /* if new filename */
    {
       strcpy(CurFile,Line);
       HavePutFile = TRUE;
    }

     s++;                                 /* flush white space until */
     while( *s == ' ' )                   /*  s points to line number */
       s++;
     Line = s;                            /* Line points to line number too */
     while( *s != ':' )                   /* position s at ':' after */
       s++;                               /*  line number */
     *s = '\0';                           /* replace ':' with null */
     i = atoi(Line);                      /* convert line number to int */

     s++;                                 /* bump past null */
     while( *s == ' ' )                   /* flush white space until */
       s++;                               /*  s points to message */

	  M.message = s;
	  M.filename = CurFile;
	  M.column = 1;
	  M.line = i;
	  IDE_PostMessage( CUR_MSG_GROUP, &M );
	  posted++;
   }
   else                                   /* no file or line number */
   {
     Line++;                              /* position Line past ':' */
     while( *Line == ' ' )                /* and at start of message */
       Line++;

     if( !HavePutFile )
     {
	/* IDE expects the first message to
	   be preceded by a filename.  Since
	   we don't have one, fake it by
	   sending a NULL file before the
	   message.
	*/
		    CurFile[0] = '\0';
     }

     M.message = Line;
     M.filename = CurFile;
     M.column = 1;
     M.line = 1;
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
  if (FatalCount)
  {
    return toolFatalError;
  }
  if (ErrorCount)
  {
    return toolErrors;
  }
  if (WarnCount)
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

#if 0
#pragma argsused
int FAR PASCAL WEP ( int bSystemExit )
{
    return 1;
}
#endif
