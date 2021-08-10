/*-----------------------------------------------------------------------*
 * filename - newpl.cpp
 * C++ placement new
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1994, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <new.h>

void *operator new(size_t, void *ptr)
{
    return ptr;
}
