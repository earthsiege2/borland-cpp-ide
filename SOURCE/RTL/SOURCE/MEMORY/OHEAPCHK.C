/*-----------------------------------------------------------------------*
 * filename - oheapchk.c
 *
 * function(s)
 *       heapcheck - check and verify heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1995, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

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
