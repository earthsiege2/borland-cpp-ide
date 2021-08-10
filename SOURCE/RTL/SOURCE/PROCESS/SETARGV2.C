/*-----------------------------------------------------------------------*
 * filename - setargv2.c
 *
 * function(s)
 *        _setargv2 - set up argv[]
 *        _wsetargv2 - set up wide-character _wargv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.10.2.1 $        */

#include <_defs.h>
#include <tchar.h>
#include <_tchar.h>

#if defined(_BUILDRTLDLL)

/* This file gets built and added as code to the RTLDLL import library to be
   linked directly into the EXE.  _setargv2() is hooked in as an INIT proc in
   the EXE which then calls _setargv() which is in the RTLDLL.
*/

/*----------------------------------------------------------------------
 * The startup code generates an external reference to either __setargv__
 * or __wsetargv__ (depending on whether or not it's a UNICODE program).
 * The following declaration satisfies that reference and forces this
 * module to be linked.
 */
int _tsetargv__ = 0;

extern int       __import _argc;           /* number of arguments */
extern _TCHAR ** __import _targv;          /* argument vector */

#ifndef _UNICODE
int       _RTLENTRY __dll_argc;   /* Used to force setup of _argc */
#else
extern int _RTLENTRY __dll_argc;
#endif
_TCHAR ** _RTLENTRY __dll_targv;  /* Used to force setup of _argv */
extern  unsigned char __isDLL;             /* 1 if we're a DLL, 0 for EXE */

void _tsetargv( void );

static void _tsetargv2( void )
{
    _tsetargv();
    __dll_argc = _argc;
    __dll_targv = _targv;
}

#ifndef _UNICODE
#pragma startup _setargv2 3  /* Initialization of additional argv routines */
#else
#pragma startup _wsetargv2 3 /* Initialization of additional wide argv routines */
#endif

void _texitargv(void);

static void _texitargv2 ( void )
{
    _texitargv();
}
#ifndef _UNICODE
#pragma exit _exitargv2 3         /* Finalization of additional argv routines */
#else
#pragma exit _wexitargv2 3        /* Finalization of additional wide argv routines */
#endif


#endif
