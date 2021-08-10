/*-----------------------------------------------------------------------*
 * filename - newfarry.cpp
 * C++ far new[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <new.h>

void far * _EXPFUNC operator new[](unsigned long size)
{
    return ::operator new(size);
}

