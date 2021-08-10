/*-----------------------------------------------------------------------*
 * filename - newplarr.cpp
 * C++ placement new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1994, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <new>

void *operator new[](size_t, void *ptr)
{
    return ptr;
}
