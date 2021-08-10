/*-----------------------------------------------------------------------*
 * filename - newfarry.cpp
 * C++ far new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <new.h>

void far * operator new[](unsigned long size)
{
    return ::operator new(size);
}

