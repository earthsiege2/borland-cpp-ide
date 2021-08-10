/*-----------------------------------------------------------------------*
 * filename - setargv2.c
 *
 * function(s)
 *        _setargv2 - set up argv[]
 *        _wsetargv2 - set up wide-character _wargv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.7  $        */

#include <_defs.h>
#include <tchar.h>
#include <_tchar.h>

#if defined(_BUILDRTLDLL)
/*----------------------------------------------------------------------
 * BCC generates an external reference to __setargv__/__wsetargv__when it
 * compiles a main() function that takes argc and argv parameters.  The following
 * declaration satisfies that reference and forces this module to be linked.
 */
int _tsetargv__ = 0;

#if defined(__WIN32__)
extern int       __import _argc;         /* number of arguments */
extern _TCHAR ** __import _targv;        /* argument vector */
#else
extern int                _argc;         /* number of arguments */
extern _TCHAR **          _targv;        /* argument vector */
#endif

int       _RTLENTRY __dll_argc;          /* Used to force setup of _argc */
_TCHAR ** _RTLENTRY __dll_targv;         /* Used to force setup of _argv */
extern  unsigned char __isDLL;           /* 1 if we are in a DLL, 0 for EXE */

void _tsetargv( void );

static void _tsetargv2( void )
{
    _tsetargv();
    __dll_argc = _argc;
    __dll_targv = _targv;
}

#ifndef _UNICODE
#pragma startup _setargv2 3       /* force _setargv2 to be called at startup */
#else
#pragma startup _wsetargv2 3      /* force _setargv2 to be called at startup */
#endif

void _texitargv(void);

static void _texitargv2 ( void )
{
    _texitargv();
}
#ifndef _UNICODE
#pragma exit _exitargv2 3         /* force _exitargv2 to be called at exit */
#else
#pragma exit _wexitargv2 3        /* force _exitargv2 to be called at exit */
#endif


#endif
