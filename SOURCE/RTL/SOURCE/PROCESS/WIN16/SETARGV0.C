/*------------------------------------------------------------------------
 * filename - setargv0.c
 *
 * function(s)
 *        _setargv0 - set argv[0] to program name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <windows.h>
#include <alloc.h>
#include <_win.h>

#pragma warn -use

#define MAXFNAMELEN 80

extern unsigned _hInstance;

/*****************************************************************************
  Startup code helper variables:
  _argv0
  _argc0
  _environ0

  These are use as place holders for the Windows and DPMI16 startup
  code, when the parameters to WinMain or _main are pushed.  Only if they
  are needed are the real values calculated and assigned to them.

 *****************************************************************************/

#if defined(__DPMI16__)
char _FAR **_C0environ = NULL;
int         _C0argc    = 1;
char _FAR **_C0argv   = NULL;
#endif

char _FAR *_argv0    = NULL;

static void _setargv0(void)
{
    _argv0 = malloc(MAXFNAMELEN+1);
    if (_argv0 == NULL)
        _errorExitBox("Out of memory in _setargv0", 3);
    GetModuleFileName(_hInstance, _argv0, MAXFNAMELEN);
}

#pragma startup _setargv0 9


/*
 *  Release _argv0
 */
static void _rlsargv0(void)
{
    if (_argv0)
	free(_argv0);
}

/* Note: check priority */
#pragma exit _rlsargv0 2
