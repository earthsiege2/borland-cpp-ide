/*-----------------------------------------------------------------------*
 * filename - del.cpp
 * C++ delete
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stddef.h>
#include <stdlib.h>

void operator delete(void *ptr)
{
    free(ptr);
}
