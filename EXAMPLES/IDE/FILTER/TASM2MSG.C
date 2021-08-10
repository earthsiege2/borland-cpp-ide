/*
   Tasm2Msg.C      copyright (c) 1993 Borland International
*/

#include "ToolApi.H"  // Borland IDE tool dll interface

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

/* Turbo Assembler text for conversion */
char TasmWarningTxt[] = "*Warning* ";
char TasmErrorTxt[]   = "**Error** ";
char TasmFatalTxt[]   = "**Fatal** ";

/* Microsoft Assembler and OPTASM text for conversion */
char MasmWarningText[] = "warning";
char MasmErrorText[]   = "error";

char     CurFile[MAXPATH];       /* Current file in message window */

FileHandle Pipefh;

HMEM       hBuffer;
LPSTR      Buffer;
WORD       curpos;
WORD       bufLen;

char       inLine[133];
LPSTR      lineptr;

int      (*processor)(char *);   /* function pointer used to call the
				    appropriate conversion routine */

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

/************************************************************************
Function  : ProcessNonTasmLine
Parameters: Line  a pointer to the current line of characters to process
Returns   : 1 if line is Microsoft Assembler line
            0 if line is not

Analyze line to determine if it is output from a MASM or OPTASM compatible
assembler. In the case of a recognizable line, output relevant information
to the message window indicating message and line number.
-*----------------------------------------------------------------------*-
Microsoft assembler lines which are in need of conversion are of the form:

   source-file(LINE #): message-kind message-num : message text

where message-kind is one of:  warning, error
-*----------------------------------------------------------------------*-
OPTASM assembler lines which are in need of conversion are of the form:

   source-file(LINE #) : message-kind message-num : message text

where message-kind is one of: Warning, Error
-*----------------------------------------------------------------------*-
Masm and Optasm lines differ from Tasm lines in that half the line must be
scanned in order to determine if the line is valid.  For this reason all
output information is stored and sent at the end when the determination of
a valid line is made.
************************************************************************/
int ProcessNonTasmLine(char *Line)
{
   unsigned i;
   char     *s;
   char     fn[MAXPATH];
   Msg M;

   if (Line[0] == 0)                         /* Empty line, no action */
      return 0;

   s = strchr(Line,'(');                     /* find ( */
   if (s != NULL)                            /* if no (, invalid line */
   {
      memmove(fn,Line,(unsigned)(s-Line));    /* store filename */
      fn[(unsigned)(s-Line)] = 0;             /* null terminate name */
      memmove(Line,++s,strlen(Line));         /* shift line left */
      if (strcmp(fn,CurFile) != 0)            /* if new filename */
      {
         strcpy(CurFile,fn);                  /* store new name */
      }
      s = strchr(Line,')');                   /* find the close paren */
      if (s != NULL)                          /* if no ) invalid line */
      {
         *s = 0;                               /* isolate the line number */
         i = atoi(Line);                       /* if number is found convert
                                                  string to integer */
         if (i != 0)
         {
            s++;
            while (*s == ' ')                  /* optasm has space here */
               s++;
            if (*s != ':')                     /* strip : from line */
               return 0;                       /* no :, not MASM line */
            s++;
            memmove(Line,s,strlen(s)+1);        /* shift line */
            while (Line[0] == ' ' && Line[0] != 0)  /* strip spaces from line */
               memmove(Line,&Line[1],strlen(Line));
            Line[0] = tolower(Line[0]);        /* optasm uses upper case */
            /* check for warning or error text from MASM, shift line if
               needed. */
	    if (strncmp(Line, MasmWarningText, strlen(MasmWarningText)) != 0)
	    {
	       if (strncmp(Line, MasmErrorText, strlen(MasmErrorText)) != 0)
	       {
		 return 0; /* not error or warning, not MASM line */
	       }
	       else
	       {
		 numErrors++;  // increase number of numErrors posted
	       }
	    }
            else
            {
              numWarnings++;
            }

            /* strip spaces from beginning of line */
            while (Line[0] == ' ' && Line[0] != 0)  /* strip spaces from line */
               memmove(Line,&Line[1],strlen(Line));
         }
         else return 0;                   /* no line number, not MASM line */
      }
      else return 0;                      /* no ), not MASM line */

	   M.message = Line;
	   M.filename = CurFile;
	   M.column = 1;
	   M.line = i;

	   IDE_PostMessage( CUR_MSG_GROUP, &M );
   }
   else return 0;                         /* no ( on line, not MASM line */

   return 1;                              /* MASM line */
}

/*************************************************************************
Function  : ProcessTasmLine
Parameters: Line  a pointer to the current line of characters to process
Returns   : 1 if line is a Turbo Assembler line
            0 if line is not

Process through a line of input to determine if it is a Turbo Assembler
output line and convert it to information for the Turbo C++ message window.

Turbo Assembler lines which are in need of conversion are of the form:

    message-type source-file(LINE #) message-text

where type is one of: *Warning*, **Error**, **Fatal**

TASM lines are identified by the first portion of text.  If warning,
error or fatal is determined at the outset, text is output from there
as it is scanned.  Any incorrect configuration will simply abort the
scanning of the rest of the line.
*************************************************************************/
int ProcessTasmLine(char *Line)
{
   unsigned   i;
   char       *s;
   char       fn[MAXPATH];
   Msg        M;
   int        lineHasErrorText = FALSE;

   /* don't try to process a NULL line */
   if (Line[0] == 0)
      return 0;

   /* check for tasm type tags */
   if (strncmp(Line,TasmFatalTxt,  strlen(TasmFatalTxt)) == 0)
   {
     lineHasErrorText = TRUE;
     numFatals++;
   }
   
   if (strncmp(Line,TasmErrorTxt,  strlen(TasmErrorTxt)) == 0)
   {
     lineHasErrorText = TRUE;
     numErrors++;
   }

   if (strncmp(Line,TasmWarningTxt,strlen(TasmWarningTxt)) == 0)
   {
     numWarnings++;
     lineHasErrorText = TRUE;
   }
     
   if ( lineHasErrorText )
   {
      /* set fn to something */
      fn[0] = '\0';

      /* skip over type by moving string left */
      memmove(Line,&Line[strlen(TasmFatalTxt)],strlen(Line));

      /* locate the first open paren '(' filename will be characters to
	 to the left, line number will be characters to the right up to the
	 close paren ')' */
      s = strchr(Line,'(');                      /* find ( */
      if (s != NULL)                             /* if no (, invalid line */
      {
	 memmove(fn,Line,(unsigned)(s-Line));    /* save filename */
	 fn[(unsigned)(s-Line)] = 0;             /* null terminate name */
	 memmove(Line,++s,strlen(Line));         /* shift line left */
	 if (strcmp(fn,CurFile) != 0)            /* if new filename */
	 {
	    strcpy(CurFile,fn);
	 }
	 s = strchr(Line,')');                   /* find the close paren */
	 if (s != NULL)
	 {
	    *s = 0;                              /* isolate number in string */
	    i = atoi(Line);                      /* if number is found convert
						    string to integer */
	    if (i != 0)
	    {
	       s++;
	       memmove(Line,s,strlen(s)+1);        /* shift line */
	       while (Line[0] == ' ' && Line[0] != 0)  /* strip spaces from line */
		      memmove(Line,&Line[1],strlen(Line));
	       M.message = Line;
	       M.filename = CurFile;
	       M.column = 1;
	       M.line = i;

	       IDE_PostMessage( CUR_MSG_GROUP, &M );
	       return 1;              /* TASM line */
	    }
	    return 0;                 /* invalid line number, not TASM line */
	 }
	 return 0;                    /* no ) in line, not TASM line */
      }
      else                            /* Fatal error, no line # or filename */
      {
		  CurFile[0] = '\0';
	while (Line[0] == ' ' && Line[0] != 0)
	  memmove(Line,&Line[1],strlen(Line));
	M.message = Line;
	M.filename = CurFile;
	M.column = 1;
	M.line = 1;

	IDE_PostMessage( CUR_MSG_GROUP, &M );
	return 1;
      }
   }
   else return 0;                     /* no line start message, not TASM line */
}

/*
  ProcessLine - dissect line of input and post it as a message to the IDE

  Input:  LPSTR line    the line to dissect and post
*/
void ProcessLine( LPSTR Line )
{
    if (processor == NULL)
    {
       if (ProcessTasmLine(Line))            /* check for TASM line */
	  processor = ProcessTasmLine;
       else
	  if (ProcessNonTasmLine(Line))      /* check MASM or OPTASM style */
             processor = ProcessNonTasmLine;
    }
    else
       processor(Line);                      /* type already determined */
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
    IDE_ErrorBox( "Tasm2Msg.DLL: Cannot filter output pipe." );
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
  return 1;
}

#pragma argsused
int FAR PASCAL WEP ( int bSystemExit )
{
    return 1;
}

