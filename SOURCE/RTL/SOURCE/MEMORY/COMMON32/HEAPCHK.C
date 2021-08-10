/*-----------------------------------------------------------------------*
 * filename - heapchk.c
 *
 * function(s)
 *      _heapchk - check and verify heap
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
#ifdef _DEBUG
extern int    _malloc_debug;
extern PBLOCK _alloc_list;                  /* list of allocated blocks */
#endif

/*---------------------------------------------------------------------*

Name            _heapchk - check and verify heap

Usage           int _heapchk(void);

Prototype in    malloc.h

Related
functions usage int _heapset (unsigned int __fill);
                int _rtl_heapwalk(_HEAPINFO *__entry);

Description     _heapchk walks through the heap and examines each block
                checking its pointers, size, and other critical
                attributes.

Return value    One of the following constants is returned (values
                are defined in malloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         heap is consistent
                _HEAPBADNODE    a corrupted heap block has been found

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _heapchk(void)
{
    int i, rc, roverfound;
    PBLOCK p, next, prev, base_heap, end_heap;
    size_t size, psize;

    _lock_heap();

    if (_nheaps == 0)           /* no heaps allocated yet */
        RETURN (_HEAPEMPTY)

    /* Perform a validity check on the free list.
     */
    for (next = NEXT(prev = _free_list), roverfound = 0; next != _free_list;
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
            RETURN (_HEAPBADNODE);

        /* See if this block is the one rover points to.
         */
        if (next == _rover)
            if (++roverfound > 1)   /* rover found more than once? */
                return (_HEAPBADNODE);
    }

    /* Rover must be in the free list exactly once.
     */
    if (_rover == _free_list)       /* Sometimes rover is the dummy block */
        roverfound++;
    if (roverfound != 1)
        return (_HEAPBADNODE);

    /* Run through all heap areas, looking at physically consective blocks,
     * both free and allocated.
     */
    for (i = 0; i < _nheaps; i++)
    {
        /* Calculate min and max boundaries of this heap area.
         */
        end_heap = (base_heap = _heaps[i].base) + (int)_heaps[i].len;

        /* Look at physically consecutive blocks in this area.
         */
        p = base_heap + OVERHEAD;
        psize = 1;
        for (;;)
        {
            /* Make sure that the block lies within the heap area.
             */
            if (p < base_heap || p > end_heap)
                RETURN (_HEAPBADNODE);

            /* Check that PSIZE field matches size of previous block.
             */
            if (PSIZE(p) != psize)
                RETURN (_HEAPBADNODE);

            /* Exit the loop if this is the end-of-heap marker block.
             * The marker should always have a size field of 1.
             */
            size = SIZE(p);
            if (size == 1 || p == end_heap)
            {
                if (size != 1 || p != end_heap)
                    RETURN (_HEAPBADNODE);
                break;
            }

            /* Check for two adjacent free blocks.  Should never happen
             * because free() merges free blocks.
             */
            if ((size & 1) == 0 && (psize & 1) == 0)
                RETURN (_HEAPBADNODE);

            /* If the block is free, search for it on the free list.
             */
            if ((size & 1) == 0)
            {
                for (next = NEXT(prev = _free_list); next != p;
                     next = NEXT(prev = next))
                {
                    /* If we reached the end of the free list without
                     * finding p return an error.
                     */
                    if (next == _free_list)
                        RETURN (_HEAPBADNODE);
                }
            }
#ifdef _DEBUG
            else if (_malloc_debug != 0)
            {
                /* The block is allocated, so search for it on
                 * the allocated list.
                 */
                for (next = _alloc_list; next != NULL && next != p;
                     next = ALINK(next))
                    ;
                if (next == NULL)
                    RETURN (_HEAPBADNODE);
            }

            /* Check the underrun sentinel field for this block.
             */
            if (BEFORE(p) != ((size & 1) ? ALLOC_SENTINEL : FREE_SENTINEL))
                RETURN (_HEAPBADNODE);
            if (AFTER(p) != BEFORE(p))
                RETURN (_HEAPBADNODE);
#endif

            /* Save the size of this block, then move p to the
             * next physical block.
             */
            psize = size;
            p += (size & ~1);

            /* Check for block outside of heap area.
             */
            if (p >= end_heap || p < base_heap)
                if (p != end_heap || SIZE(p) != 1)
                    RETURN (_HEAPBADNODE);
        }
    }

    rc = _HEAPOK;

exit:
    _unlock_heap();
    return (rc);
}
