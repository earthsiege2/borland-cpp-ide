/*------------------------------------------------------------------------
 * filename - setargv0.c
 *
 * function(s)
 *        _setargv0 - set argv[0] to program name
 *        _wsetarg0 - set _wargv[0] to wide-character program name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1995, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6.2.1 $        */

#include <ntbc.h>
#include <windows.h>
#include <alloc.h>
#include <_io.h>
#include <tchar.h>
#include <_tchar.h>
#include <winbase.h>

#define MAXFNAMELEN 255

_TCHAR *_targv0    = NULL;

// Note that _exitargv0 handles freeing _argv0
static void _tsetargv0(void)
{
#ifndef _UNICODE
#pragma startup _setargv0 2 /* Early argv processing, must be sooner that of _setargv in setargv.c */
#else
#pragma startup _wsetargv0 2 /* Early wide argv processing, must be sooner that of _setargv in setargv.c */
#endif
    _targv0 = malloc((MAXFNAMELEN+1)*sizeof(_TCHAR));
    if (_targv0 == NULL)
        _ErrorExit("Out of memory in _setargv0");
    GetModuleFileName(NULL, _targv0, MAXFNAMELEN);
}

static void _texitargv0(void)
{
#ifndef _UNICODE
#pragma exit _exitargv0 2 /* Finalization of early argv processing */
#else
#pragma exit _wexitargv0 2 /* Finalization of early wide argv processing */
#endif
    free(_targv0);
}
