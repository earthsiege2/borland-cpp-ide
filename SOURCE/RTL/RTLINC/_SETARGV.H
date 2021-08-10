/*------------------------------------------------------------------------
 * filename - _setargv.h
 *
 *  Definitions for routines that manipulate the argv[] parameters
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $ */


#ifndef ___SETARGV_H
#define ___SETARGV_H

#include <_tchar.h>
#include <wildargs.h>

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------
 * The startup code passes the following variables to main().
 * They contain copies of _argc and _argv.
 */
extern int                _C0argc;
extern _TCHAR **          _tC0argv;
extern _TCHAR *           _targv0;
extern _TCHAR **          _tC0environ;   /* array of environment strings */

/*----------------------------------------------------------------------
 * The following variables points to the command line, and is
 * set up by the startup code.
 */
extern _TCHAR * _EXPDATA  _toscmd;
extern _TCHAR * _EXPDATA  _tosenv;             /* pointer to raw OS environment data */

/*----------------------------------------------------------------------
 * Argument vector and count.  Argument count (_argc) is located in globals.c
 */
extern int       _EXPDATA _argc;         /* number of arguments */
extern _TCHAR ** _EXPDATA _targv;        /* argument vector */

/*----------------------------------------------------------------------
 * Function Prototypes:
 */

/* Pointer to cmdline handler replacement.  Normally it points to a
   function that performs the standard cmdline argv handling
*/
extern int _RTLENTRY (* _RTLENTRY _EXPDATA _setargv_ptr) (char * _argv0, char *_cmdline, _PFN_ADDARG _pfn_addarg);
extern int _RTLENTRY (* _RTLENTRY _EXPDATA _wsetargv_ptr) (wchar_t * _argv0, wchar_t *_cmdline, _PFN_ADDARG _pfn_addarg);

/* Pointer to cmdline cleanup replacement.  Normally it points to a
   function that performs cleanup on the allocated memory.
*/
extern void _RTLENTRY (* _RTLENTRY _EXPDATA _exitargv_ptr) (void);
extern void _RTLENTRY (* _RTLENTRY _EXPDATA _wexitargv_ptr) (void);

/* Built-in handler for not expanding wild cards
*/
void _RTLENTRY _EXPFUNC _argv_default_expand(char *_arg, _PFN_ADDARG _pfn_addarg);
void _RTLENTRY _EXPFUNC _wargv_default_expand(wchar_t *_arg, _PFN_ADDARG _pfn_addarg);


void _RTLENTRY _init_wild_handlers(void (**wild_func)(char *, _PFN_ADDARG), void (**wwild_func)(wchar_t *, _PFN_ADDARG));
void _RTLENTRY _init_setargv_handlers(
    int (*setargv_func)(char *, char *, _PFN_ADDARG),
    void (*exitargv_func)(void),
    int (*wsetargv_func)(wchar_t *, wchar_t *, _PFN_ADDARG),
    void (*wexitargv_func)(void)
);

#ifdef __cplusplus
} // "C"
#endif

#endif /* ___SETARGV_H */