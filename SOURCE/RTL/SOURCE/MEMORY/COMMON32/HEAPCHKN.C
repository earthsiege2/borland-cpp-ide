/*-----------------------------------------------------------------------*
 * filename - heapchkn.c
 *
 * function(s)
 *      heapchecknode - check and verify a single node on the heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <malloc.h>
#include <_heapdbg.h>
#include <_malloc.h>
#include <_thread.h>
#include <_io.h>        /* RETURN macro */

/* Variables from heap.c
 */
extern PBLOCK _free_list;                   /* first block on free list */
extern PBLOCK _rover;                       /* roving pointer into the free list */
extern struct _heap_rec _heaps[MAXHEAPS];   /* all non-contiguous heap areas */
extern int    _nheaps;                      /* no. of heaps in _heaps */

/*---------------------------------------------------------------------*

Name            heapchecknode - check and verify a single node on the heap

Usage           int heapchecknode(void *node);

Prototype in    alloc.h

Related
functions usage int _heapchk (void);
                int _rtl_heapwalk(_HEAPINFO *__entry);

Description     If a node has been freed and heapchecknode is called
                with a pointer to the freed block, heapchecknode can
                return _BADNODE rather than the expected _FREEENTRY.
                This is because adjacent free blocks on the heap are
                merged, and the block in question no longer exists.

Return value    One of the following constants is returned (values
                are defined in alloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPCORRUPT    heap has been corrupted
                _BADNODE        node could not be found
                _FREEENTRY      node is a free block
                _USEDENTRY      node is a used block

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC heapchecknode(void *node)
{
    int i, rc, roverfound;
    PBLOCK p, next, prev, base_heap, end_heap;
    size_t size, psize;

    _lock_heap();

    if (_nheaps == 0)            /* no heaps allocated yet */
        RETURN (_HEAPEMPTY)

    p = (PBLOCK)node;           /* type conversion */

    /* Find the heap area that contains this block before trying to access it.
     */
    for (i = 0; i < _nheaps; i++)
    {
        end_heap = (base_heap = _heaps[i].base) + (int)_heaps[i].len;
        if (p >= base_heap && p <= end_heap)
            break;
    }
    if (i == _nheaps)
        RETURN (_BADNODE);

    /* Verify that that the PSIZE field of this block
     * matches SIZE of the previous block.  If this is the
     * first real block in a heap area, the previous block
     * is a dummy that has a size of 1.
     */
    size = SIZE(p);
    psize = PSIZE(p);
    prev = p - (psize & ~1);
    if (p == base_heap + OVERHEAD)
    {
        if (psize != 1)
            RETURN (_HEAPCORRUPT);
    }
    else
    {
        if (prev < base_heap || prev >= end_heap)
            RETURN (_BADNODE);
        if (SIZE(prev) != psize)
            RETURN (_BADNODE);
    }

    /* Check that the PSIZE field of the next block matches the SIZE
     * field of this block.  If this is the last dummy block in
     * a heap area, there is no next block, and the size is 1.
     */
    if (p == end_heap)
    {
        if (size != 1)
            RETURN (_HEAPCORRUPT);
    }
    else
    {
        next = p + (size & ~1);
        if (next <= p || next > end_heap)
            RETURN (_BADNODE);
        if (PSIZE(next) != size)
            RETURN (_BADNODE);

        /* Verify the overrun/underrun sentinels of this block.
         */
#ifdef _DEBUG
        if (BEFORE(p) != ((size & 1) ? ALLOC_SENTINEL : FREE_SENTINEL))
            RETURN (_HEAPBADNODE);
        if (BEFORE(p) != AFTER(p))
            RETURN (_HEAPBADNODE);
#endif
    }

    /* p seems to point to a good block, as far as we can tell.
     * Return value saying whether block is used or free.
     * If the block is free, verify that it is on the free list.
     */
    if ((size & 1) == 0)
    {
        for (next = NEXT(prev = _free_list), roverfound = 0; prev != p;
             next = NEXT(prev = next))
        {
            /* Find the heap area that contains next.
             */
            for (i = 0; i < _nheaps; i++)
                if (next >= _heaps[i].base &&
                    next <= _heaps[i].base + (int)_heaps[i].len)
                break;

            /* If next is an invalid pointer, or the prev link is corrupted,
             * or the block is not marked as free, return an error.
             */
            if (i == _nheaps || PREV(next) != prev || (SIZE(next) & 1) != 0)
                RETURN (_HEAPCORRUPT);

            /* See if this block is the one rover points to.
             */
            if (next == _rover)
                if (++roverfound > 1)   /* rover found more than once? */
                    return (_HEAPCORRUPT);

            /* If we reached the end of the free list without
             * finding p return an error.
             */
            if (next == _free_list)
                RETURN (_BADNODE);
        }
        rc = _FREEENTRY;
    }
    else
        rc = _USEDENTRY;        /* block is used, don't check free list */

exit:
    _unlock_heap();
    return (rc);
}
