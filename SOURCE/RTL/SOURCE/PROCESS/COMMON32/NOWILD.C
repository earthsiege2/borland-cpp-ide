/*-----------------------------------------------------------------------*
 * filename - nowild.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

/* Cause _setargv to NOT expand wildcard filenames on the command line.
 * This file will not be linked if wildargs.obj is linked.
 */

#include <_tchar.h>

/*----------------------------------------------------------------------
 * _initwild, _winitwild - dummy wildcard expansion initializer
 *
 * This function is a dummy that does nothing, and is called by the
 * startup code directly.  See wildargs.c for a real version that
 * actually does something.
 */
void _tinitwild(void)
{
}
