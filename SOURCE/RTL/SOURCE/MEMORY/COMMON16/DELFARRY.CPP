/*-----------------------------------------------------------------------*
 * filename - delfarry.cpp
 * C++ far delete[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stddef.h>

#if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
void operator delete[](void far *ptr)
{
    ::operator delete(ptr);
}
#endif
