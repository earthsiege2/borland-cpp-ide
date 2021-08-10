/*-----------------------------------------------------------------------*
 * filename - newfarry.cpp
 * C++ far new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <new.h>

void far * _EXPFUNC operator new[](unsigned long size)
{
    return ::operator new(size);
}

