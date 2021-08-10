/*-----------------------------------------------------------------------*
 * filename - newfpl.cpp
 * C++ far placement new
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1994, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <new.h>

void __far * _EXPFUNC operator new(unsigned long, void __far *ptr)
{
    return ptr;
}
