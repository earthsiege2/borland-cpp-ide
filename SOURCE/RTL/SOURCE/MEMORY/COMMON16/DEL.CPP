/*-----------------------------------------------------------------------*
 * filename - del.cpp
 * C++ delete
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stddef.h>
#include <stdlib.h>

void operator delete(void *ptr)
{
    free(ptr);
}
