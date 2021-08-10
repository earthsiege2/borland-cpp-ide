/*------------------------------------------------------------------------
 * filename - calloc.c
 *
 * function(s)
 *        calloc - allocates main memory
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------*

Name            calloc - allocates main memory

Usage           void *calloc(size_t nelem, size_t elsize);

Prototype in    stdlib.h and alloc.h

Description     calloc allocates a  block like malloc, except the  block is
                of size nelem times elsize. The block is cleared to 0.

Return value    calloc returns a  pointer to the newly allocated  block, or
                NULL if not  enough space exists for the new  block or, the
                requested size is equal to 0.

*-------------------------------------------------------------------------*/

void * _RTLENTRY _EXPFUNC calloc(size_t nelem, size_t elsize)
{
    register char   *cp;
    size_t msize;

    if ((cp = malloc((msize = nelem * elsize))) != NULL)
        memset(cp, 0, msize);
    return(cp);
}
