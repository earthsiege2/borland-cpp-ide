/*-----------------------------------------------------------------------*
 * filename - newfplar.cpp
 * C++ far placement new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <new.h>

void __far *operator new[](unsigned long, void __far *ptr)
{
    return ptr;
}
