/*-----------------------------------------------------------------------*
 * filename - newarray.cpp
 * C++ new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <new.h>

void * _EXPFUNC operator new[]( size_t size )
{
    return ::operator new(size);
}
