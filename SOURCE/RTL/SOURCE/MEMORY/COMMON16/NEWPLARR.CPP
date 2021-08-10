/*-----------------------------------------------------------------------*
 * filename - newplarr.cpp
 * C++ placement new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <new.h>

void *operator new[](size_t, void *ptr)
{
    return ptr;
}
