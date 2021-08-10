/*-----------------------------------------------------------------------*
 * filename - heapmin.c
 *
 * function(s)
 *      _heapmin - return unused portion of heap to OS
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <malloc.h>
#include <_heapdbg.h>
#include <_malloc.h>
#include <_thread.h>
#include <_io.h>        /* RETURN macro */

/* Variables from heap.c and getmem.c.
 */
extern PBLOCK _free_list;                   /* first block on free list */
extern struct _heap_rec _heaps[MAXHEAPS];   /* all non-contiguous heap areas */
extern int    _nheaps;                      /* no. of heaps in _heaps */
extern ULONG  _heap_brk;                    /* top of committed part of heap */
extern ULONG  _heap_top;                    /* top of uncommitted part of heap */

/*---------------------------------------------------------------------*

Name            _heapmin - return unused portion of heap to OS

Usage           int _heapmin(void);

Prototype in    malloc.h

Related
functions usage int _heapchk(void);p
                int _heapset (unsigned int __fill);
                int _heapmin(_HEAPINFO *entry);

Description     _heapmin minimizes heap usage by releasing unused portions
                of the heap to the OS.

Return value    If _heapmin is successful, it returns 0; otherwise it
                returns -1.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _heapmin(void)
{
    int i, rc;

    PBLOCK p, bound, next, prev, base_heap, end_heap;
    size_t size, psize;

    _lock_heap();

    for (i = 0; i < _nheaps; i++)
    {
        /* Get the heap's start and ending addresses.
         * If the heap doesn't end on a 64K boundary, skip it.
         */
        end_heap = (base_heap = _heaps[i].base) + (int)_heaps[i].len;
        if ((((ULONG)end_heap) & (SEG_SIZE-1)) != 0)
            continue;

        /* Point to the last block in the heap, always guaranteed
         * to be a dummy zero-length block.
         */
        p = (PBLOCK)end_heap;

        /* Check if the previous block (i.e. the last REAL block in the heap)
         * is free.  If not, there's nothing we can do with this heap.
         */
        psize = PSIZE(p);
        if (psize & 1)
            continue;

        /* Get a pointer to the last block on the heap, which is free.
         * Then get a pointer to the next 64K boundary above that.
         * If the 64K boundary lies within the heap, then we can
         * free everything in the heap after that point.
         */ 
        p -= psize;
        bound = (PBLOCK)ROUND_UP((ULONG)p,SEG_SIZE);
        if (bound >= end_heap)
            continue;

        /* Save the free list links of the last block in case we
         * have to unlink it later.
         */
        next = NEXT(p);
        prev = PREV(p);

        /* Return the memory between bound and end_heap to the OS.
         * Reduce the heap size accordingly, and reset _heap_brk
         * if it falls in the memory being freed.
         */
        if (_virt_decommit(bound, end_heap - bound) == 0)
            RETURN (-1);        
        _heaps[i].len = bound - base_heap;
        if ((ULONG)bound < _heap_brk && _heap_brk <= (ULONG)end_heap)
            _heap_brk = (ULONG)bound;

        /* Shrink the last block and construct a new dummy end-of-heap block.
         * If there isn't enough room for the dummy block, unlink the last
         * block and merge it into the previous block before constructing
         * the dummy block.
         */
        if ((size = bound - p) >= MINBLOCK)
        {
            SIZE(p) = PSIZE(bound) = size;
            SIZE(bound) = 1;
        }
        else
        {
            PREV(next) = prev;      /* unlink the block from free list */
            NEXT(prev) = next;
            prev = p - SIZE(p);     /* point to previous physical block */
            size = bound - prev;    /* new size of previous block */
            PSIZE(bound) = SIZE(prev) = (SIZE(prev) & 1) | size;
            SIZE(bound) = 1;
        }
    }

    rc = 0;

exit:
    _unlock_heap();
    return (rc);
}
