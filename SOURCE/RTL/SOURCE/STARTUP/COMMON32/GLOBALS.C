/*-----------------------------------------------------------------------*
 * filename - globals.c
 *
 * This file contains the following startup function global variables:
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#include <ntbc.h>
#include <_thread.h>
#include <_startup.h>
/*----------------------------------------------------------------------
 * _ExcRegPtr contains the address of an exception registration
 * record in the startup code's local stack area.
 */
PEXCEPTIONREGISTRATIONRECORD  _ExcRegPtr;

/*----------------------------------------------------------------------
 * The following two variables are pointers into the environment data
 * passed to us by the loader.
 */
char    * _EXPDATA _osenv;             /* pointer to raw OS environment data */
wchar_t * _EXPDATA _wosenv;            /* pointer to raw OS environment data */
char    * _EXPDATA _oscmd;             /* pointer to raw OS command line */
wchar_t * _EXPDATA _woscmd;            /* pointer to raw OS command line */

/*----------------------------------------------------------------------
 * Mutex Semaphore to lock access to the atexit table.
 */
#ifdef _MT
lock_t __exit_lock;
#endif


/*----------------------------------------------------------------------
 * The following variable is set up by the argument initialization
 * function setargv().
 */
int       _argc;        /* number of arguments */

/*----------------------------------------------------------------------
 * The following variables are set up by the environment initialization
 * function setenvp() and the argument initialization function setargv(),
 * and are passed to main.
 */
int    _C0argc;               /* argument count */
char **_C0argv;               /* array of arguments */
char **_C0environ;            /* array of environment strings */
char **_wC0argv;              /* array of arguments */
char **_wC0environ;           /* array of environment strings */

/*----------------------------------------------------------------------
 * The following tables each contain a pointer to the module table
 * for this program (either an EXE or DLL).  See _startup.h and c02.asm
 * for the table layout.
 */
       MULTI_INIT _dll_table;       /* DLL's init table */
       MULTI_INIT _exe_table;       /* EXE's init table */

/*----------------------------------------------------------------------
 * The following variable gives the starting address of stack.
 * It is used by alloca() to check for stack overflow.
 */
ULONG _EXPDATA _stkbase;

/*----------------------------------------------------------------------
 * The following variable is non-zero if this is a Windows application
 */
#ifndef __OS2__
int _isWindows;
#endif


