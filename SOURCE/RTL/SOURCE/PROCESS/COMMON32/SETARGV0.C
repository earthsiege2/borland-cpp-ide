/*------------------------------------------------------------------------
 * filename - setargv0.c
 *
 * function(s)
 *        _setargv0 - set argv[0] to program name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1995, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <windows.h>
#include <alloc.h>
#include <_io.h>

#define MAXFNAMELEN 255

char *_argv0    = NULL;

// Note that _exitargv0 handles freeing _argv0
static void _setargv0(void)
{
#pragma startup _setargv0 2  // NOTE: priority must be < that of _setargv in
                             //       setargv.c (currently set to 3)
    _argv0 = malloc(MAXFNAMELEN+1);
    if (_argv0 == NULL)
        _ErrorExit("Out of memory in _setargv0");
    GetModuleFileName(NULL, _argv0, MAXFNAMELEN);
}

static void _exitargv0(void)
{
#pragma exit _exitargv0 2
    free(_argv0);
}
