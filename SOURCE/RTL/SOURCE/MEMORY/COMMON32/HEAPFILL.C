/*-----------------------------------------------------------------------*
 * filename - heapfill.c
 *
 * function(s)
 *       heapfillfree - fill free blocks with constant
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1995, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <malloc.h>

/*---------------------------------------------------------------------*

Name            heapfillfree - fill free blocks with constant value

Usage           int heapfillfree (unsigned int fill);

Prototype in    malloc.h

Related
functions usage int heapcheckfree(unsigned int fill)

Description     heapfillfree checks the heap for consistency in the same manner
                as heapcheck.  It then fill every free block in the heap
                with the specified fill value.

Return value    One of the following constants is returned (values
                are defined in alloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         heap is consistent
                _HEAPBADNODE    a corrupted heap block has been found

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC heapfillfree(unsigned int fill)
{
    int rc;

    if ((rc = _heapset(fill)) != _HEAPOK && rc != _HEAPEMPTY)
        return (_HEAPCORRUPT);      /* translate MSC code to Borland code */
    else
        return (rc);
}
