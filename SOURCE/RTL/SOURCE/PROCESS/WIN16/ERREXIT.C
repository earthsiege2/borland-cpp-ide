/*------------------------------------------------------------------------
 * filename - errexit.c
 *
 * function(s)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif  // __STDLIB_H

#if !defined( ___WIN_H )
#include <_win.h>
#endif  // ___WIN_H

#if !defined( __WINDOWS_H )
#include <windows.h>
#endif  // __WINDOWS_H

#if !defined( __STRING_H )
#include <string.h>
#endif  // __STRING_H

#if !defined( __IO_H )
#include <io.h>
#endif  // __IO_H

#include <dos.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <time.h>
#include <stdio.h>

extern char *_Cdecl _argv0;
extern HWND _hInstance;

char * _messagefile = NULL; /* used to determine if error messages are
                               sent to MessageBox/stderr or directed to
                               this file name

                               Set _messagefile to -1 to prevent
                               anything from being displayed. Or set to
                               filespec to have the message written to
                               that file.

                            */


#if !defined(__DPMI16__)

#if defined(__DLL__)
/* This gets exported from the RTL DLL to set the pointer */
char * __export __set_messagefile (char *s)
{
  char *p = _messagefile;
  _messagefile = s;
  return p;
}
#endif

/* --------------------------------------------------------------------------*/
static char *DateTime (void)
{
    static char buf[24];
    struct time tm;
    struct date da;

    getdate (&da);
    gettime (&tm);

    sprintf(buf,"%02d/%02d/%04d %2d:%02d:%02d.%02d ",
            da.da_mon, da.da_day, da.da_year,
            tm.ti_hour, tm.ti_min, tm.ti_sec, tm.ti_hund);
    return buf;
}
/* --------------------------------------------------------------------------*/

void _ErrorMessageHelper (const char *msgfile, const char *msg)
{
    int fd;
    char *date;

    if ((fd=open(msgfile,O_TEXT|O_RDWR|O_CREAT|O_APPEND|O_DENYNONE,S_IREAD|S_IWRITE))==-1)
        return;

    date = DateTime ();
    lseek (fd, 0, SEEK_END);
    _rtl_write (fd, date, strlen (date));
    _rtl_write (fd, msg, strlen (msg));
    _rtl_write (fd, "\n", 1);
    _rtl_close (fd);
}

/* --------------------------------------------------------------------------*/


#pragma argsused
static BOOL CALLBACK taskHasWnd(HWND h, BOOL far* has) { *has = TRUE; return FALSE; }

static unsigned mbModalFlag(void)
{
  BOOL has = FALSE;
  EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)taskHasWnd,
                    (LPARAM)(BOOL far*)&has);
  return has ? MB_TASKMODAL : MB_SYSTEMMODAL;
}

void
#if defined(__DLL__)
__export
#endif
_errorBox(const char *msg)
{
    char _FAR *progName = strrchr(_argv0, '\\');
    if (progName == NULL)
        progName = _argv0;
    else
        progName++;     // skip backslash in front of name

    if (_messagefile == NULL)
        MessageBox(NULL, msg, progName, mbModalFlag() | MB_ICONSTOP);
    else  /* _messagefile points to a file, attempt to write to it. */
    {
        if ((long)_messagefile == -1L)
            return;

        if (!_messagefile || !_messagefile[0])
            return;
        _ErrorMessageHelper(_messagefile, msg);
    }
}

#else

void _errorBox(const char *msg)
{
    _rtl_write(2, msg, strlen(msg));
}

#endif

void
#if defined(__DLL__)
__export
#endif
_errorExitBox(const char *msg, int code)
{
    _errorBox(msg);
    _exit(code);
}
