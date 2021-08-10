/*-----------------------------------------------------------------------*
 * filename - getmem.c
 *
 * function(s)
 *      _getmem         - allocate new memory for the heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <_malloc.h>
#include <malloc.h>

/* Public variables.
 */
ULONG  _heap_brk = 0;           /* top of committed part of heap */
ULONG  _heap_top = 0;           /* top of uncommitted part of heap */

/*---------------------------------------------------------------------*

Name            _getmem - allocate new memory for the heap

Usage           int _getmem(size_t size);

Prototype in    _malloc.h

Description     This function allocates a new memory block from OS/2,
                then adds it to the heap.  The allocation is performed
                by committing pages that have been previously allocated
                from the virtual address space but not committed.
                The block size is rounded up to the next multiple of
                64K.  Virtual address space is allocated in multiples
                of 4 Meg, and committed in multiples of 64K.

Return value    If the memory can be succesfully allocated and added
                to the heap, 0 is returned; otherwise -1.

*---------------------------------------------------------------------*/

int _getmem(size_t size)
{
    void *p;
    unsigned long rem, vsize;

    /* Round up size to next multiple of 64K.
     */
    size = (size_t)ROUND_UP(size,SEG_SIZE);

    /* Commit some available remaining uncommitted 64K chunks in the
     * current heap area, if any.
     */
    if ((rem = _heap_top - _heap_brk) != 0)
    {
        if (rem > size )
            rem = size;
        if (_virt_commit((void *)_heap_brk, rem) == 0)
            return (-1);
        _heapadd((PBLOCK)_heap_brk,(size_t)rem);
        _heap_brk += rem;
    }

    /* If we didn't add enough chunks to the heap to cover
     * the requested size, allocate a new 4 Meg virtual address
     * space for a new heap area.
     */
    if (rem < size)
    {
        if (_virt_reserve((unsigned long)size, &p, &vsize) == 0)
            return (-1);

        /* Commit some of the chunks from the new heap area.
         * If the new heap area is contiguous with the end of the old area,
         * we can also use chunks from the old area to help cover the request.
         */
        if ((ULONG)p == _heap_top)
            size -= (size_t)rem;
        if (_virt_commit(p, size) == 0)
        {
            _virt_release(p);
            return (-1);
        }
        _heapadd(p,size);
        _heap_brk = (ULONG)p + size;
        _heap_top = (ULONG)p + vsize;
    }
    return (0);
}
