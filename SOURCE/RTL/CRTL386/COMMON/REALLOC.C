/*-----------------------------------------------------------------------*
 * filename - realloc.c
 *
 * function(s)
 *      _expand         - grow or shrink a block in place
 *      realloc         - change size of block, copy contents
 *      _msize          - return size of a heap block
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <_heapdbg.h>
#include <_malloc.h>
#include <_thread.h>

extern PBLOCK _rover;               /* roving pointer into the free list */

#ifdef _DEBUG
extern PBLOCK _alloc_list;          /* list of allocated blocks */
#endif

/*---------------------------------------------------------------------*

Name            _expand - grow or shrink a block in place

Usage           void * _expand(void *block, size_t size);

Prototype in    malloc.h

Description     This function attempts to changes the size of an
                allocated block without moving the block.  The contents
                of the block, up to the shorter of the old and new size,
                are not changed.

                For information about the heap data structures,
                see the comments in heap.c.

Return value    If the block can be succesfully resized, the
                address of the block is returned; otherwise NULL
                is returned.

*---------------------------------------------------------------------*/

#ifdef _DEBUG
void * _RTLENTRY _EXPFUNC __expand(void * block, size_t size, int hook)
#else
void * _RTLENTRY _EXPFUNC _expand(void * block, size_t size)
#endif
{
    size_t cursize, nsize, realsize;
    PBLOCK p, newb, next, prev;

    p = (PBLOCK)block;      /* type conversion */

#ifdef _DEBUG
    if (_malloc_debug == 2)
        if (_heapchk() != _HEAPOK)
            _heap_error(NULL, _heap_corrupt);

    /* Make sure the block is on the allocated list and not on
     * the free list.
     */
    if (_malloc_debug != 0)
    {
        if (!_is_allocated(p))
            _heap_error(p, _heap_notallocated);
        if (_is_free(p))
            _heap_error(p, _heap_free);
    }
#endif


    /* Adjust the real size of the block to be a multiple of 4,
     * and add the overhead for the boundary tags.  Disallow
     * negative or zero sizes.
     */
    if (size < MINBLOCK - OVERHEAD)
        realsize = MINBLOCK;
    else
        realsize = (size_t)ROUND_UP(size,WORD_SIZE) + OVERHEAD;
    if ((int)realsize < MINBLOCK || size == 0)
        return (NULL);

    _lock_heap();

    /* If the current size is the same as requested, do nothing.
     */
    cursize = SIZE(p) & ~1;
    if (cursize == realsize)
    {
        _unlock_heap();
#ifdef _DEBUG
        USIZE(p) = size;
        AFTER(p) = ALLOC_SENTINEL;      /* rewrite the overrun sentinel */
        if (hook)
            _expand_hook(block, size);
#endif
        return (block);
    }

    /* Check for block overrun, underrun by seeing if the longwords
     * just before and after the block have been modified.
     */
#ifdef _DEBUG
    if (_malloc_debug != 0)
    {
        if (BEFORE(p) != ALLOC_SENTINEL)
            _heap_error(p, _heap_underrun);
        if (AFTER(p) != ALLOC_SENTINEL)
            _heap_error(p, _heap_overrun);
        next = p + cursize;
        if (SIZE(p) != PSIZE(next))
            _heap_error(p, _heap_sizemismatch);
    }
#endif

    /* If the block is being shrunk, convert the remainder of the
     * block into a new free block.
     */
    if (realsize <= cursize)
    {
        nsize = cursize - realsize;     /* size of new remainder block */
        if (nsize >= MINBLOCK)
        {
            /* Set boundary tags for the resized block and the new block.
             */
            newb = p + realsize;
            next = newb + nsize;
            SIZE(p) = PSIZE(newb) = realsize | 1;
            SIZE(newb) = PSIZE(next) = nsize | 1;

#ifdef _DEBUG
            /* Set the sentinels before and after the new block.
             */
            USIZE(newb) = nsize - OVERHEAD;
            BEFORE(newb) = AFTER(newb) = ALLOC_SENTINEL; /* sentinels for newb */

            if (_malloc_debug != 0)
            {
                /* Add block to the allocated list so free() won't complain.
                 */
                ALINK(newb) = _alloc_list;
                _alloc_list = newb;
            }
#endif

            /* Add the new block to the free list.
             */
            _free(newb);
        }

        _unlock_heap();

#ifdef _DEBUG
        /* Set the sentinels before and after the block being returned.
         */
        USIZE(p) = size;
        BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;    /* sentinels for p */
        if (hook)
            _expand_hook(block, size);
#endif
        return (block);
    }

    /* The block is being grown.  See if the next block is free, and
     * is big enough to satisfy the request, and that the reallocated
     * block won't cross a 64K boundary.
     */
    if (_same_seg(p,size))
    {
        next = p + cursize;
        nsize = SIZE(next);

        /* Check the next block for consistency.
         */
#ifdef _DEBUG
        if (_malloc_debug != 0)
        {
            PBLOCK q;

            if (BEFORE(next) != ((nsize & 1) ? ALLOC_SENTINEL : FREE_SENTINEL))
                _heap_error(next, _heap_underrun);
            if (AFTER(next) != BEFORE(next))
                _heap_error(next, _heap_overrun);
            q = next + (nsize & ~1);        /* point to block after next */
            if (PSIZE(q) != SIZE(next))
                _heap_error(next, _heap_sizemismatch);
        }
#endif

        if ((nsize & 1) == 0 && (nsize + cursize) >= realsize)
        {
            /* The next block is free and big enough.  Add the part
             * that's needed to our block, and split the remainder
             * off into a new block.
             */
            prev = PREV(next);
            if (_rover == next)
                _rover = next = NEXT(next);
            else
                next = NEXT(next);

            nsize = nsize + cursize - realsize;     /* size of remainder */
            if (nsize < MINBLOCK)
            {
                /* The block to be split off is too small. Unlink the
                 * entire block and add it to the current block.
                 */
                NEXT(prev) = next;
                PREV(next) = prev;
                realsize += nsize;
                next = p + realsize;
                SIZE(p) = PSIZE(next) = realsize | 1;

                /* Set the overrun/underrun sentinels for the resized block.
                 */
#ifdef _DEBUG
                USIZE(p) = size;
                BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;
#endif
            }
            else
            {
                /* Split off the unused portion of the next block and
                 * link it into the free list in place of the next block.
                 */
                newb = p + realsize;
                NEXT(prev) = newb;
                PREV(next) = newb;
                NEXT(newb) = next;
                PREV(newb) = prev;

                /* Set boundary tags for the resized block and the new block.
                 */
                next = newb + nsize;
                SIZE(p) = PSIZE(newb) = realsize | 1;
                SIZE(newb) = PSIZE(next) = nsize;

                /* Set the overrun/underrun sentinels for both blocks.
                 */
#ifdef _DEBUG
                USIZE(p) = size;
                BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;
                USIZE(newb) = nsize - OVERHEAD;
                BEFORE(newb) = AFTER(newb) = FREE_SENTINEL;
#endif
            }
            _unlock_heap();
#ifdef _DEBUG
            if (hook)
                _expand_hook(block, size);
#endif
            return (block);
        }
    }
    _unlock_heap();
    return ((void *)NULL);
}

#ifdef _DEBUG

void * _RTLENTRY _EXPFUNC _expand(void *block, size_t size)
{
    return (__expand(block, size, 1));      /* call user hook */
}

#endif

/*---------------------------------------------------------------------*

Name            realloc - change size of block, copy contents

Usage           void * realloc(void *block, size_t size);

Prototype in    malloc.h

Description     This function changes the size of an allocated block
                by allocating a new block of the requested size,
                and then copying the contents of the old block to the
                new.  The number of bytes copied is the smaller
                of the new and old block sizes.  If a new block
                is allocated, the old block is freed; otherwise
                the old block is left unchanged.

Return value    If the new block can be succesfully reallocated, the
                address of the new block is returned; otherwise NULL
                is returned.

*---------------------------------------------------------------------*/

#ifdef _DEBUG
void * _RTLENTRY _EXPFUNC __realloc(void * block, size_t size, int hook)
#else
void * _RTLENTRY _EXPFUNC realloc(void * block, size_t size)
#endif
{
    size_t cursize, psize, realsize, rem;
    PBLOCK p, newb, next, prev;

    /* If size is zero, free the block.
     */
    if (size == 0)
    {
        free(block);
        return (NULL);
    }

    /* If block pointer is NULL, do a malloc().
     */
    if (block == NULL)
        return (malloc(size));

    /* Try to grow or shrink the block in place.
     */
#ifdef _DEBUG
    if (__expand(block,size,hook) != NULL)
#else
    if (_expand(block,size) != NULL)
#endif
        return (block);

    /* Adjust the real size of the block to be a multiple of 4,
     * and add the overhead for the boundary tags.  Disallow
     * negative or zero sizes.
     */
    if (size < MINBLOCK - OVERHEAD)
        realsize = MINBLOCK;
    else
        realsize = (size_t)ROUND_UP(size,WORD_SIZE) + OVERHEAD;
    if ((int)realsize < MINBLOCK || size == 0)
        return (NULL);

    _lock_heap();

    /* See if the previous block is free, and is big enough to cover
     * the new size if merged with the current block.
     */
    p = (PBLOCK)block;
    cursize = SIZE(p) & ~1;
    psize = PSIZE(p);
    prev = p - (psize & ~1);
    if ((psize & 1) == 0 && psize + cursize >= realsize && _same_seg(prev,size))
    {
        /* Unlink the previous block from the free list.
         */
        newb = p - psize;
        next = NEXT(newb);
        prev = PREV(newb);
        NEXT(prev) = next;
        PREV(next) = prev;
        if (_rover == newb)
            _rover = next;

        /* Unlink the old block from the allocated list, and
         * add the previous block to the allocated list.
         */
#ifdef _DEBUG
        if (_malloc_debug != 0)
        {
            _unlink_alloc(p);
            ALINK(newb) = _alloc_list;
            _alloc_list = newb;
        }
#endif

        /* Copy contents of old block to new location, make it
         * the current block.
         */
#ifdef _DEBUG
        if (hook)
            _move_hook(newb, size, p);
#endif
        memmove(newb,p,cursize);
        p = newb;
        cursize += psize;           /* combine sizes */

        if ((rem = cursize - realsize) < MINBLOCK)
        {
            /* The remainder is too small to make into a separate
             * block.  Use the entire combined block.  Set the
             * the boundary tags to mark it as allocated.
             */
            next = p + cursize;
            SIZE(p) = PSIZE(next) = cursize | 1;

            /* Set the overrun/underrun sentinels for the combined block.
             */
#ifdef _DEBUG
            USIZE(p) = size;
            BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;
#endif
        }
        else
        {
            /* The remainder is big enough to split off into a new block.
             * Set boundary tags for the resized block and the new block.
             */
            newb = p + realsize;
            next = newb + rem;
            SIZE(p) = PSIZE(newb) = realsize | 1;
            SIZE(newb) = PSIZE(next) = rem | 1;

            /* Set the overrun/underrun sentinels for the resized block
             * and the new block.
             */
#ifdef _DEBUG
            USIZE(p) = size;
            BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;      /* resized block */
            USIZE(newb) = rem - OVERHEAD;
            BEFORE(newb) = AFTER(newb) = ALLOC_SENTINEL;   /* new block */
            if (_malloc_debug != 0)
            {
                /* Add block to the allocated list so free() won't complain.
                 */
                ALINK(newb) = _alloc_list;
                _alloc_list = newb;
            }
#endif

            /* Add the new block to the free list.
             */
            _free(newb);
        }
        _unlock_heap();
        return ((void *)p);
    }

    /* We must allocate a new block, copy the old to the new,
     * and free the old.
     */
    if ((newb = malloc(size)) != NULL)
    {
        memmove(newb,block,cursize-OVERHEAD);
        free(block);
    }
    _unlock_heap();
    return ((void *)newb);
}

#ifdef _DEBUG

void * _RTLENTRY _EXPFUNC realloc(void *block, size_t size)
{
    return (__realloc(block, size, 1));     /* call user hook */
}

void * _RTLENTRY _EXPFUNC _realloc(void *block, size_t size)
{
    return (__realloc(block, size, 0));     /* DON'T call user hook */
}

#endif

/*---------------------------------------------------------------------*

Name            _msize - return size of a heap block

Usage           size_t _msize(void *block);

Prototype in    malloc.h

Description     This function returns the actual size of an allocated
                block, in bytes.

Return value    The size of the allocated block.

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC _msize(void * block)
{
    PBLOCK p = (PBLOCK)block;

    if (block == NULL)
        return (0);
    return ((SIZE(p) & ~1) - OVERHEAD);
}
