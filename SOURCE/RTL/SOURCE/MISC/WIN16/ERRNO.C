/*------------------------------------------------------------------------
 * filename - errno.c
 *
 * Function to return the address of errno (static library version only)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <errno.h>

int * _RTLENTRY __getErrno(void)
{
	return &errno;
}
