/*-----------------------------------------------------------------------*
 * filename - delarray.cpp
 * C++ delete[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1990, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stddef.h>

void _RTLENTRY _EXPFUNC operator delete[]( void *ptr )
{
    ::operator delete(ptr);
}

