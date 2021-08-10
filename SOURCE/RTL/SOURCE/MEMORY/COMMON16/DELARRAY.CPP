/*-----------------------------------------------------------------------*
 * filename - delarray.cpp
 * C++ delete[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stddef.h>

void _EXPFUNC operator delete[](void *ptr)
{
    ::operator delete(ptr);
}

