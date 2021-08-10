/*-----------------------------------------------------------------------*
 * filename - nowild.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_defs.h>

/* Cause _setargv to NOT expand wildcard filenames on the command line.
 * This file will not be linked if wildargs.obj is linked.
 */

/*----------------------------------------------------------------------
 * Variables from setargv.c
 */
extern void (_FAR *_expandptr)(char _FAR *);  /* pointer to wildcard expand function */

/*----------------------------------------------------------------------
 * Functions from wild.c
 */
extern void _RTLENTRY _EXPFUNC expand(char _FAR *arg);

/*----------------------------------------------------------------------
 * _initwild - dummy wildcard expansion initializer
 *
 * This function is a dummy that does nothing, See wildargx.c for a real
 * version that actually does something.
 */
void _initwild(void)
{
#pragma startup _initwild 9
    _expandptr = expand;
}
