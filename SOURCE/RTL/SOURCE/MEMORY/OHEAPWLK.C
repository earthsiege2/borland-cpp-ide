/*-----------------------------------------------------------------------*
 * filename - heapwalk.c
 *
 * function(s)
 *      heapwalk - walk through the heap node by node
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <malloc.h>

/*---------------------------------------------------------------------*

Name            heapwalk - walk through the heap node by node

Usage           int heapwalk(struct heapinfo *__entry);

Prototype in    malloc.h

Related
functions usage int heapcheck(void);
                int heapfillfree (unsigned int __fill);

Description     heapwalk receives a pointer to a structure of type
                struct heapinfo (declared in malloc.h). For the first
                call to heapwalk, set the _pentry field to NULL.
                heapwalk returns with the _pentry field containing
                the address of the next block in the heap.  The _size
                field holds the size of the block in bytes.  The _useflag
                field is a flag that is set if the block is currently
                in use.

                heapwalk assumes the heap is correct.  Use heapcheck to
                verify the heap before using heapwalk.

Return value    One of the following constants is returned (values
                are defined in malloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         the struct heapinfo block contains valid
                                information about the next heap block
                _HEAPEND        the end of the heap has been reached
                _HEAPCORRUPT    a corrupted heap block has been found

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC heapwalk(struct heapinfo *entry)
{
    int rc;
    struct _heapinfo msc_entry;

    /* Call the MSC-compatible function to do all the work.
     */
    msc_entry._pentry  = entry->ptr;
    msc_entry.__pentry = entry->ptr2;
    rc = _rtl_heapwalk(&msc_entry);

    /* Convert the _heapinfo to a heapinfo, and convert the return code.
     */
    entry->ptr    = msc_entry._pentry;
    entry->ptr2   = msc_entry.__pentry;
    entry->size   = msc_entry._size;
    entry->in_use = msc_entry._useflag == _USEDENTRY;
    return rc == _HEAPOK || rc == _HEAPEMPTY || rc == _HEAPEND ? rc : _HEAPCORRUPT;
}
