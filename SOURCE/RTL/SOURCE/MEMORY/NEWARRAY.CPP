/*-----------------------------------------------------------------------*
 * filename - newarray.cpp
 * C++ new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1990, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */


#include <new>

void * _RTLENTRY _EXPFUNC operator new[]( size_t size )
{
    return ::operator new(size);
}
