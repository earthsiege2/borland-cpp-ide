/*-----------------------------------------------------------------------*
 * filename - delfarry.cpp
 * C++ far delete[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stddef.h>

#if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
void operator delete[](void far *ptr)
{
    ::operator delete(ptr);
}
#endif
