/*------------------------------------------------------------------------
 * filename - errexit.c
 *
 * function(s)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
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

extern char *_Cdecl _argv0;
extern HWND _hInstance;

#if !defined(__DPMI16__)

#pragma argsused
static BOOL CALLBACK taskHasWnd(HWND h, BOOL far* has) { *has = TRUE; return FALSE; }

static unsigned mbModalFlag(void)
{
  BOOL has = FALSE;
  EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)taskHasWnd,
                    (LPARAM)(BOOL far*)&has);
  return has ? MB_TASKMODAL : MB_SYSTEMMODAL;
}

void _errorBox(const char *msg)
{
    char _FAR *progName = strrchr(_argv0, '\\');
    if (progName == NULL)
        progName = _argv0;
    else
        progName++;     // skip backslash in front of name

    MessageBox(NULL, msg, progName, mbModalFlag() | MB_ICONSTOP);
}

#else

void _errorBox(const char *msg)
{
    _rtl_write(2, msg, strlen(msg));
}

#endif

void _errorExitBox(const char *msg, int code)
{
    _errorBox(msg);
    _exit(code);
}
