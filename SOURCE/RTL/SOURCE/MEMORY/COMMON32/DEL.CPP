/*-----------------------------------------------------------------------*
 * filename - del.cpp
 * C++ DELETE
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stddef.h>
#include <stdlib.h>

void _RTLENTRY _EXPFUNC operator delete( void *ptr )
{
    free(ptr);
}


