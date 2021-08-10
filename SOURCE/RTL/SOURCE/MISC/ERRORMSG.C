/*-----------------------------------------------------------------------*
 * filename - errormsg.c
 *
 * function(s)
 *        _ErrorMessage - print an error message to console
 *        _ErrorExit    - print an error message to console, then exit
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $        */

#define INCL_USER
#include <ntbc.h>

#include <string.h>
#include <stdlib.h>
#if defined(_MBCS)
#include <tchar.h>
#endif

/* _messagefunc: is used by the RTL Test Suites as a hook to be called when
   ErrorExit is called.  If the _messagefunc is NULL, it won't be called.
   Set it to -1 to prevent anything from being displayed at all (just like
   _messagefile).  The parameter 'msg' is the string that would normally be
   displayed. Currently the return value is not used.
*/
int (_RTLENTRY * _EXPDATA _messagefunc) (char *msg) = NULL;


/* _messagefile: is used to determine if error messages are to be sent to
   MessageBox/stderr or directed to this file name.  Set _messagefile to -1
   to prevent anything from being displayed. Or set it to filespec to have
   the message written to that file.
*/
char * _RTLENTRY _EXPDATA _messagefile = NULL;

extern int _isWindows; /* from startup/globals.c */

void _ErrorMessageHelper (const char *, const char *);

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
   if (_messagefile == NULL && _messagefunc == NULL)
   {
       if(_isWindows)
       {
        char filename[128];
        char *progname;

        GetModuleFileName(NULL, (PSTR)&filename, sizeof(filename));
#if defined(_MBCS)
        if ((progname = _tcsrchr(filename,_TEXT('\\'))) == NULL &&
            (progname = _tcsrchr(filename,_TEXT( ':'))) == NULL)
#else
        if ((progname = strrchr(filename,'\\')) == NULL &&
            (progname = strrchr(filename, ':')) == NULL)
#endif
            progname = filename;
        else
            progname++;
        MessageBox(NULL, (LPSTR)s, (LPSTR)progname, mbModalFlag() | MB_ICONSTOP | MB_SETFOREGROUND);
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
    else
    {
        if (_messagefunc != NULL)
        {
            if ((long)_messagefunc == -1L)
                return;

            _messagefunc(s);
        }

        if (_messagefile != NULL)
        {
            if ((long)_messagefile == -1L)
                return;

            if (!_messagefile[0]) /* check for null string */
                return;

            /* _messagefile points to a file, attempt to write to it. */
            _ErrorMessageHelper(_messagefile, s);
        }
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
