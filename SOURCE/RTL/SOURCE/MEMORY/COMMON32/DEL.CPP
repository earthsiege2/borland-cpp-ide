/*-----------------------------------------------------------------------*
 * filename - del.cpp
 * C++ DELETE
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stddef.h>
#include <stdlib.h>

void _RTLENTRY _EXPFUNC operator delete( void *ptr )
{
    free(ptr);
}


