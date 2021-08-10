/*-----------------------------------------------------------------------*
 * filename - newarray.cpp
 * C++ new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <new.h>

void *operator new[]( size_t size )
{
    return ::operator new(size);
}
