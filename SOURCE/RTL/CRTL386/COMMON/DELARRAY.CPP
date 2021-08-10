/*-----------------------------------------------------------------------*
 * filename - delarray.cpp
 * C++ delete[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stddef.h>

void _RTLENTRY _EXPFUNC operator delete[]( void *ptr )
{
    ::operator delete(ptr);
}

