/*-----------------------------------------------------------------------*
 * filename - setargv2.c
 *
 * function(s)
 *        _setargv2 - set up argv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_defs.h>

#if defined(_BUILDRTLDLL)
/*----------------------------------------------------------------------
 * BCC generates an external reference to __setargv__ when it compiles
 * a main() function that takes argc and argv parameters.  The following
 * declaration satisfies that reference and forces this module to be linked.
 */
int _setargv__ = 0;

#if defined(__WIN32__)
extern int     __import _argc;        /* number of arguments */
extern char ** __import _argv;        /* argument vector */
#else
extern int              _argc;        /* number of arguments */
extern char **          _argv;        /* argument vector */
#endif

int     _RTLENTRY __dll_argc;         /* Used to force setup of _argc */
char ** _RTLENTRY __dll_argv;         /* Used to force setup of _argv */

void _setargv( void );

static void _setargv2( void )
{
    _setargv();
    __dll_argc = _argc;
    __dll_argv = _argv;
}

#pragma startup _setargv2 3      /* force _setargv2 to be called at startup */

void _exitargv(void);

static void _exitargv2 ( void )
{
    _exitargv();
}
#pragma exit _exitargv2 3        /* force _exitargv2 to be called at exit */


#endif
