/*-----------------------------------------------------------------------*
 * filename - errormsg.c
 *
 * function(s)
 *        _ErrorMessage - print an error message to console
 *        _ErrorExit    - print an error message to console, then exit
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_USER
#include <ntbc.h>

#include <string.h>
#include <stdlib.h>

extern unsigned char __isGUI;   /* defined in c0nt.asm, to determine at runtime
                                   if we're a GUI or Console mode application */

#pragma argsused
static BOOL CALLBACK threadHasWnd(HWND h, BOOL* has) { *has = TRUE; return FALSE; }

static unsigned mbModalFlag(void)
{
  BOOL has = FALSE;
  if (!(HIWORD(GetVersion()) & 0x8000))   // NT can always open task modal
	  return MB_TASKMODAL;
  EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)threadHasWnd,
                    (LPARAM)&has);
  return has ? MB_TASKMODAL : MB_SYSTEMMODAL;
}

/*-----------------------------------------------------------------------*

Name            _ErrorMessage - print an error message to console

Usage           void _ErrorMessage(const char *s);

Prototype in    _io.h

Description     _ErrorMessage writes the specified string to the
                console device.  If the program is running on
                a windowing system, a pop-up message box is displayed.
                Otherwise, the message is displayed on the screen,
                preceded and followed by newlines.

Return value    None.

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _ErrorMessage(const char *s)
{
   if(__isGUI)
   {
    char filename[80];
    char *progname;

    GetModuleFileName(NULL, (PSTR)&filename, sizeof(filename));
    if ((progname = strrchr(filename,'\\')) == NULL &&
        (progname = strrchr(filename, ':')) == NULL)
        progname = filename;
    else
        progname++;
    MessageBox(NULL, (LPSTR)s, (LPSTR)progname, mbModalFlag() | MB_ICONSTOP);
   }
   else /* console mode */
   {
    DWORD nwritten;
    HANDLE herr;

    herr = GetStdHandle(STD_ERROR_HANDLE);

    WriteFile(herr, "\r\n", 2, &nwritten, NULL);
    WriteFile(herr, (PVOID)s, strlen(s), &nwritten, NULL);
    WriteFile(herr, "\r\n", 2, &nwritten, NULL);
   }
}

/* The following function is present only for compatibility with CLASSLIBS.
 */
void _RTLENTRY _EXPFUNC __ErrorMessage(const char *s)
{
    _ErrorMessage(s);
}


/*-----------------------------------------------------------------------*

Name            _ErrorExit - print an error message to console

Usage           void _ErrorExit(const char *s);

Prototype in    _io.h

Description     _ErrorExit writes the specified string to the
                console device.  If the program is running on
                a windowing system, a pop-up message box is displayed.
                Otherwise, the message is displayed on the screen,
                preceded and followed by newlines.

Return value    None.

*------------------------------------------------------------------------*/

void _EXPFUNC _ErrorExit(const char *s)
{
    _ErrorMessage(s);
    _exit(1);
}
