/*-----------------------------------------------------------------------*
 * filename - newfpl.cpp
 * C++ far placement new
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

void __far * _EXPFUNC operator new(unsigned long, void __far *ptr)
{
    return ptr;
}
