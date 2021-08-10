/*-----------------------------------------------------------------------*
 * filename - oheapchk.c
 *
 * function(s)
 *       heapcheck - check and verify heap
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

Name            heapcheck - check and verify heap

Usage           int heapcheck(void);

Prototype in    malloc.h

Related
functions usage int heapwalk(struct heapinfo *__entry);

Description     heapcheck walks through the heap and examines each block
                checking its pointers, size, and other critical
                attributes.

Return value    One of the following constants is returned (values
                are defined in alloc.h or malloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         heap is consistent
                _HEAPCORRUPT    a corrupted heap block has been found

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC heapcheck(void)
{
    int rc;

    if ((rc = _heapchk()) != _HEAPOK && rc != _HEAPEMPTY)
        return (_HEAPCORRUPT);      /* translate MSC code to Borland code */
    else
        return (rc);
}
