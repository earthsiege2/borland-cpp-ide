/*-----------------------------------------------------------------------*
 * filename - delarray.cpp
 * C++ delete[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stddef.h>

void _RTLENTRY _EXPFUNC operator delete[]( void *ptr )
{
    ::operator delete(ptr);
}

