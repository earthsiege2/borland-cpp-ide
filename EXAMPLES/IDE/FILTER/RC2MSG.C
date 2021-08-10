/*
   rc2Msg.C      copyright (c) 1993 Borland International
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

int posted = 0;

/* Declare an array of function pointers to store the IDE tool API */
IDE_ToolAPIFunc IDE_ToolAPI[IDE_NumFunctions];

/* Global variables use to parse program output */
HINSTANCE globInst;

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
  static int HavePutFile = FALSE;
  int        HasLineNumber;
//  char       Type;
  unsigned   i;
  char       *s, *LeftParen, *Colon;
  Msg M;

   /* if blank line, return */
   while( *Line && ( (*Line == '\r') || (*Line == '\n') ) )
     Line++;
   if( *Line == '\0' )
     return;

   /* if line starts with "Microsoft" or "Copyright", it's not
      an error line */
   
   /* also include "RLINK32" */

   if( strncmp( Line, "Microsoft", 9 ) == 0 ||
       strncmp( Line, "Copyright", 9 ) == 0  )
   {
     return;
   }


   HasLineNumber = FALSE;
   LeftParen = strchr( Line, '(' );       /* if '(' in the line */
   if( LeftParen != NULL )                /* Line may contain line number */
     HasLineNumber = TRUE;

   if( HasLineNumber ) {
     Colon = strchr(LeftParen, ':' );     /* if no ':' following the '(' */
     if( Colon == NULL )                  /* Line doesn't contain line number */
       HasLineNumber = FALSE;
   }

   if( HasLineNumber ) {
     s = LeftParen-1;                       /* position s after last char */
     while( *s == ' ' )                     /* in filename */
       s--;
     s++;
     *s = 0;                                /* and null-terminate */

     if( strcmp(Line,CurFile) != 0 )        /* if new filename */
     {
       strcpy(CurFile,Line);
       HavePutFile = TRUE;
     }

     s = strchr(LeftParen+1,')');                   /* find the right paren */
     *s = 0;                                 /* and null-terminate line# */
     i = atoi(LeftParen+1);                  /* line# starts after ( */
					     /* convert line# to integer */

     s = Colon+1;                            /* position s at first */
     while( *s == ' ' )                      /* non-blank char after : */
       s++;                                  /* Rest of line is message */
	  
	  M.message = s;
	  M.filename = CurFile;
	  M.column = 1;
	  M.line = i;

	  IDE_PostMessage( CUR_MSG_GROUP, &M );
	  posted++;
   }
   else {                                    /* no line number */
     if( !HavePutFile )
     {
	/* IDE expects the first message to
	   be preceded by a filename.  Since
	   we don't have one, fake it by
	   sending a NULL file before the
	   message.
	*/
       CurFile[0] = '\0';
       HavePutFile = TRUE;
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

