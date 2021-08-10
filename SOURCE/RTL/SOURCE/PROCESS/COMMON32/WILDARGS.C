/*-----------------------------------------------------------------------*
 * filename - wildargs.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

/* Cause _setargv to expand wildcard filenames on the command line.
 * Link this object file BEFORE the C runtime library.
 */

#include <_defs.h>
#include <tchar.h>
#include <_tchar.h>

/*----------------------------------------------------------------------
 * Variables from setargv.c
 */
extern void (*_texpandptr)(_TCHAR *);  /* pointer to wildcard expand function */

/*----------------------------------------------------------------------
 * Functions from wild.c
 */
extern void _RTLENTRY _EXPFUNC _texpand_wild(_TCHAR *arg);

/*----------------------------------------------------------------------
 * _initwild - set the pointer to the argument expander
 *
 * This function will be called directly by the startup code for EXEs.
 * It modifies a pointer in setargv.c to point to the _expand_wild() function
 * in wild.c, so that wildcard arguments will be expanded.
 */
void _tinitwild(void)
{
    _texpandptr = _texpand_wild;
}
