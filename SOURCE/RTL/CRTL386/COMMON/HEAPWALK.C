/*-----------------------------------------------------------------------*
 * filename - heapwalk.c
 *
 * function(s)
 *      _rtl_heapwalk - walk through the heap node by node
 *      _heapwalk - walk through the heap node by node (obsolete)
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

/* Variables from heap.c
 */
extern PBLOCK _free_list;                   /* first block on free list */
extern struct _heap_rec _heaps[MAXHEAPS];   /* all non-contiguous heap areas */
extern int    _nheaps;                      /* no. of heaps in _heaps */

/*---------------------------------------------------------------------*

Name            _rtl_heapwalk - walk through the heap node by node

Usage           int _rtl_heapwalk(_HEAPINFO *__entry);

Prototype in    malloc.h

Related
functions usage int _heapchk(void);p
                int _heapset (unsigned int __fill);

Description     _rtl_heapwalk receives a pointer to a structure of type
                _heapinfo (declared in malloc.h). For the first
                call to _heapwalk, set the _pentry field to NULL.
                _heapwalk returns with the _pentry field containing
                the address of the next block in the heap.  The _size
                field holds the size of the block in bytes.  The _useflag
                field is a flag that is set if the block is currently
                in use.

                _rtl_heapwalk assumes the heap is correct.  Use _heapchk to
                verify the heap before using _rtl_heapwalk.

Return value    One of the following constants is returned (values
                are defined in malloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         the _heapinfo block contains valid
                                information about the next heap block
                _HEAPBADNODE    a corrupted heap block has been found
                _HEAPBADPTR     The _pentry field does not point to
                                a valid heap block
                _HEAPEND        the end of the heap has been reached

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _rtl_heapwalk(_HEAPINFO *entry)
{
    int i, rc;
    PBLOCK p, next, prev, base_heap, end_heap;
    size_t size, psize;

    _lock_heap();

    if (_nheaps == 0)               /* no heaps allocated yet */
        RETURN (_HEAPEMPTY)

    /* Stay in the loop until we come across a non-zero-length block.
     */
    do
    {
        p = (PBLOCK)(entry->_pentry);   /* type conversion */

        if (p == NULL)
        {
            /* If _pentry is NULL, point to the first block in the
             * first heap area.
             */
            end_heap = (base_heap = _heaps[0].base) + (int)_heaps[0].len;
            p = base_heap + OVERHEAD;
        }
        else
        {
            /* If _pentry is not NULL, find the heap area that contains
             * this block before trying to access it.
             */
            for (i = 0; i < _nheaps; i++)
            {
                end_heap = (base_heap = _heaps[i].base) + (int)_heaps[i].len;
                if (p >= base_heap && p <= end_heap)
                    break;
            }
            if (i == _nheaps)
                RETURN (_HEAPBADPTR);

            /* If _pentry points to the end of a heap area, get the
             * first block of the next heap area (if any).  If this
             * is the last heap area, return _HEAPEND.
             */
            if (p == end_heap)
            {
                if (++i == _nheaps)
                    RETURN (_HEAPEND);
                end_heap = (base_heap = _heaps[i].base) + (int)_heaps[i].len;
                p = base_heap + OVERHEAD;
            }
            else
            {
                /* _pentry is in the middle of a heap area.  Point to
                 * the next physical block in the heap.
                 */
                p += SIZE(p) & ~1;
            }
        }

        /* Now p points to the block to examine.  Verify that that its PSIZE
         * field matches SIZE of the previous block.  If this is the
         * first real block in a heap area, the previous block is a dummy
         * that has a size of 1.
         */
        size = SIZE(p);
        psize = PSIZE(p);
        prev = p - (psize & ~1);
        if (p == base_heap + OVERHEAD)      /* dummy first block? */
        {
            if (psize != 1)                 /* size must be 1 */
                RETURN (_HEAPBADNODE);
        }
        else                                /* normal block */
        {
            if (prev < base_heap || prev >= end_heap)
                RETURN (_HEAPBADNODE);      /* out of bounds */
            if (SIZE(prev) != psize)
                RETURN (_HEAPBADNODE);      /* size field corrupt */
        }

        /* Check that the PSIZE field of the next block matches the SIZE
         * field of this block.  If this is the last dummy block in
         * a heap area, there is no next block, and the size is 1.
         */
        if (p == end_heap)                  /* dummy last block? */
        {
            if (size != 1)                  /* size must be 1 */
                RETURN (_HEAPBADNODE);
        }
        else                                /* normal block */
        {
            next = p + (size & ~1);
            if (next <= p || next > end_heap)
                RETURN (_HEAPBADNODE);      /* out of bounds */
            if (PSIZE(next) != size)
                RETURN (_HEAPBADNODE);      /* size field corrupt */

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
         * Return information about it.
         */ 
        entry->_pentry = (int *)p;
        entry->_size = size >= OVERHEAD ? (size & ~1) - OVERHEAD : 0;
    } while (entry->_size == 0);

    entry->_useflag = (size & 1) ? _USEDENTRY : _FREEENTRY;
    rc = _HEAPOK;

exit:
    _unlock_heap();
    return (rc);
}

/* wrapper for obsolete function */

int _RTLENTRY _EXPFUNC _heapwalk(_HEAPINFO *entry)
{
   return(_rtl_heapwalk(entry));
}

