/*-----------------------------------------------------------------------*
 * filename - nowild.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1992, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

/* Cause _setargv to NOT expand wildcard filenames on the command line.
 * This file will not be linked if wildargs.obj is linked.
 */

/*----------------------------------------------------------------------
 * _initwild - dummy wildcard expansion initializer
 *
 * This function is a dummy that does nothing, and is called by the
 * startup code directly.  See wildargs.c for a real version that
 * actually does something.
 */
void _initwild(void)
{
}
