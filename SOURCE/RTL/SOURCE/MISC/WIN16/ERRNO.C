/*------------------------------------------------------------------------
 * filename - errno.c
 *
 * Function to return the address of errno (static library version only)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1995, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <errno.h>

int * _RTLENTRY __getErrno(void)
{
	return &errno;
}
