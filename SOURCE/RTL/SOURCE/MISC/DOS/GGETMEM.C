/*-----------------------------------------------------------------------*
 * filename - ggetmem.c
 *
 * function(s)
 *   _graphgetmem - allocate memory for graphics library
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <graphics.h>
#include <alloc.h>

/*-----------------------------------------------------------------------*

Name            _graphgetmem - allocate memory for graphics library

Usage           void far * far _graphgetmem(unsigned size)

Prototype in    graphics.h

Description     allocates memory used for graphic buffers, fonts, etc.

Return value    returns a pointer to the allocated memory block on success;
                NULL on failure.

*------------------------------------------------------------------------*/

void far * far _graphgetmem(unsigned size)
{
        return(malloc(size));
}
