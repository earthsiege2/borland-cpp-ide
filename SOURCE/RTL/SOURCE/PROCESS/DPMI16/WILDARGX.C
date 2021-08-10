/*-----------------------------------------------------------------------*
 * filename - wildargs.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

/* Cause _setargv to expand wildcard filenames on the command line.
 * Link this object file BEFORE the C runtime library.
 */

#include <_defs.h>

/*----------------------------------------------------------------------
 * Variables from setargv.c
 */
extern void (_FAR *_expandptr)(char _FAR *);  /* pointer to wildcard expand function */

/*----------------------------------------------------------------------
 * Functions from wild.c
 */
extern void _RTLENTRY _EXPFUNC _expand_wild(char _FAR *arg);

/*----------------------------------------------------------------------
 * _initwild - set the pointer to the argument expander
 *
 * This function will be called directly by the startup code for EXEs.
 * It modifies a pointer in setargv.c to point to the _expand_wild() function
 * in wild.c, so that wildcard arguments will be expanded.
 */
void _initwild(void)
{
#pragma startup _initwild 9
    _expandptr = _expand_wild;
}
