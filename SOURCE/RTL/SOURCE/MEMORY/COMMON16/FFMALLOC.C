/*-----------------------------------------------------------------------*
 * filename - ffmalloc.c
 *
 * function(s)
 *        __ffarmalloc  - helper function for _fstrdup
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <alloc.h>

/*
   Helper function for _fstrdup.  It's a far function that makes a near or
   far call to farmalloc depending on the memory model.
*/

void far * far _ffarmalloc(unsigned long __nbytes)
{
        return farmalloc(__nbytes);
}
