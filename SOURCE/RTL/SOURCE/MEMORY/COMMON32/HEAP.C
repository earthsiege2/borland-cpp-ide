/*-----------------------------------------------------------------------*
 * filename - heap.c
 *
 * function(s)
 *      _lock_heap      - lock the global heap lock
 *      _unlock_heap    - unlock the global heap lock
 *      _init_heap      - set up the heap variables
 *      free            - free an allocated block
 *      _same_seg        - check if a block lies within a 64K segment
 *      _heapadd        - add a block to the heap
 *      malloc          - allocate a block from the heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <_malloc.h>
#include <_thread.h>

//#ifdef _DEBUG
#include <_heapdbg.h>
//#endif

/*----------------------------------------------------------------------
 * Knuth's "boundary tag" algorithm is used to manage the heap.
 * Each block in the heap has tag words before and after it, which
 * contain the size of the block:
 *  SIZE
 *  block ...
 *  SIZE
 * The size is stored as a long word, and includes the 8 bytes of
 * overhead that the boundary tags consume.  Blocks are allocated
 * on LONG word boundaries, so the size is always even.  When the
 * block is allocated, bit 0 of the size is set to 1.  When a block is
 * freed, it is merged with adjacent free blocks, and bit 0 of the
 * size is set to 0.
 *
 * When a block is on the free list, the first two LONG words of the block
 * contain double links.  These links are not used when the block is
 * allocated, but space needs to be reserved for them.  Thus, the minimum
 * block size (not counting the tags) is 8 bytes.
 *
 * The free list is not ordered by address.  The list is searched using
 * a roving pointer and first-fit.
 *
 * On OS/2, blocks less than 64K bytes are guaranteed to not cross 64K
 * boundaries.
 *
 * See <_malloc.h> for the definition and description of the macros
 * and structures used to access heap blocks.
 */

/*----------------------------------------------------------------------
 * The following variables are located in the C02x startup module.
 * They are provided for the benefit of the debugger, and contain
 * the addresses of the _nheaps and _heaps variables.
 */
#ifdef __OS2__
extern struct _heap_rec *_c0_heaps; /* pointer to _heaps */
extern int    *_c0_nheaps;          /* pointer to _nheaps */
#endif

/*----------------------------------------------------------------------
 * Internal public variables.
 */
char   _free_dummy[MINBLOCK];       /* dummy free block */
PBLOCK _free_list;                  /* pointer to first block on free list */
PBLOCK _rover;                      /* roving pointer into the free list */

#ifdef _MT
lock_t _heap_lock;                  /* heap semaphore */
#endif

struct _heap_rec _heaps[MAXHEAPS];  /* list of all non-contiguous heap areas */
int    _nheaps;                     /* no. of heaps in _heaps */

/*----------------------------------------------------------------------
 * The debug level has the following possible values:
 *  0 - no debugging checks performed
 *  1 - abort with an error message if a bad block or bad argument
 *      is detected.
 *  2 - all level 1 checks, plus the entire heap is checked by
 *      each call to a heap function
 */
#ifdef _DEBUG
int    _malloc_debug = 1;
PBLOCK _alloc_list = NULL;          /* list of allocated blocks */
int    _heap_searches;              /* no. of blocks examined by malloc */
int    _heap_allocations;           /* no. of allocations by malloc */
#endif

/*----------------------------------------------------------------------
 * hooks -
 *
 * This are pointers to functions that the debugging versions of
 * malloc and realloc will call just before they return, and free
 * calls before it performs any processing.
 */
#ifdef _DEBUG

#pragma argsused
static void default_malloc_hook(void *block, size_t size) {}
#pragma argsused
static void default_free_hook  (void *block) {}
#pragma argsused
static void default_expand_hook(void *block, size_t newsize) {}
#pragma argsused
static void default_move_hook  (void *block, size_t newsize, void *oldblock) {}

void (*_malloc_hook)(void *block, size_t size) = default_malloc_hook;
void (*_free_hook)  (void *block) = default_free_hook;
void (*_expand_hook)(void *block, size_t newsize) = default_expand_hook;
void (*_move_hook)  (void *block, size_t newsize, void *oldblock) = default_move_hook;

#else

/* Calls to the hooks are no-ops in the non-debugging library.
 */
#define _malloc_hook(block,size)
#define _free_hook(block)
#define _expand_hook(block,newsize)
#define _move_hook(block,newsize,oldblock)

#endif


#ifdef _MT

/*---------------------------------------------------------------------*

Name            _lock_heap - lock the global heap lock

Usage           void _lock_heap(void);

Prototype in    _stdio.h

Related
functions usage void _unlock_heap(void);

Description     This function locks the global lock that governs
                access to the heap.

Return value    None.

*---------------------------------------------------------------------*/

void _lock_heap(void)
{
    _lock(_heap_lock,"locking heap");
}

/*---------------------------------------------------------------------*

Name            _unlock_heap - unlock the global heap lock

Usage           void _unlock_heap(void);

Prototype in    _stdio.h

Related
functions usage void _unlock_heap(void);

Description     This function unlocks the global lock that governs
                access to the heap.

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_heap(void)
{
    _unlock(_heap_lock,"unlocking heap");
}

#endif  /* _MT */

/*---------------------------------------------------------------------*

Name            _init_heap - set up the heap variables

Usage           void _init_heap(void);

Prototype in

Description     Create a dummy allocated block to act as the the
                head of the heap free list.  Point the head and
                the roving free list pointer at this dummy block.

Return value    None.

*---------------------------------------------------------------------*/

static void _RTLENTRY _init_heap()
{
#pragma startup _init_heap 2

    /* Initialize the free list by placing a dummy zero-length block on
     * it.  Set the number of non-contiguous heaps to zero.
     */
    _free_list = _rover = (PBLOCK)(&_free_dummy[OVERHEAD]);
    PSIZE(_free_list) = SIZE(_free_list) = 0;
    PREV(_free_list) = NEXT(_free_list) = _free_list;

#ifdef _DEBUG
    /* Store overrun/underrun sentinel values.
     */
    PAFTER(_free_list) = BEFORE(_free_list) = FREE_SENTINEL;
#endif

    _nheaps = 0;

    /* Create the lock used to govern access to the heap.
     */
    _create_lock(&_heap_lock,"creating heap lock");

    /* Fill in the magic words in the startup module for the debugger.
     */
#ifdef __OS2__
    _c0_heaps = _heaps;
    _c0_nheaps = &_nheaps;
#endif
}

#ifndef __OS2__
void _RTLENTRY _release_heap()
{
// Explicitly called by exit.  Workaround for flushing file buffers
//#pragma exit _release_heap 0

    while(_nheaps-- > 0)
        {
        _virt_decommit(_heaps[_nheaps].base, _heaps[_nheaps].len);
        _virt_release(_heaps[_nheaps].base);
        }
}
#endif

/*---------------------------------------------------------------------*

Name            _is_free - check that a block is on the free list

Usage           int _is_free(PBLOCK block);

Prototype in    local

Description     Search the free list for the specified block.  If
                it is found, return 1; otherwise return 0.

Return value    If block is found, 1; otherwise 0.

*---------------------------------------------------------------------*/

#ifdef _DEBUG

int _is_free(PBLOCK p)
{
    PBLOCK next;

    for (next = NEXT(_free_list); next != _free_list && next != p;
         next = NEXT(next))
        ;
    return (next != _free_list);
}

#endif

/*---------------------------------------------------------------------*

Name            _is_allocated - check that a block is on the allocated list

Usage           int _is_allocated(PBLOCK block);

Prototype in    local

Description     Search the allocated list for the specified block.  If
                it is found, return 1; otherwise return 0.

Return value    If block is found, 1; otherwise 0.

*---------------------------------------------------------------------*/

#ifdef _DEBUG

int _is_allocated(PBLOCK p)
{
    PBLOCK next;

    for (next = _alloc_list; next != NULL && next != p;
         next = ALINK(next))
        ;
    return (next == p);
}

#endif

/*---------------------------------------------------------------------*

Name            _unlink_alloc - remove a block from the allocated list

Usage           void _unlink_alloc(PBLOCK block);

Prototype in    local

Description     Unlink the specified block from the allocated list.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _DEBUG

void _unlink_alloc(PBLOCK p)
{
    PBLOCK prev;

    if (_alloc_list == p)
        _alloc_list = ALINK(p);
    else
    {
        for (prev = _alloc_list; prev != NULL && ALINK(prev) != p;
             prev = ALINK(prev))
            ;
        if (prev == NULL)
            _heap_error(p, _heap_notallocated);
        else
            ALINK(prev) = ALINK(p);
    }
}

#endif

/*---------------------------------------------------------------------*

Name            free - free an allocated block

Usage           void free(void *block);

Prototype in

Description     Return a block to the heap.  The block must have
                previously allocated with malloc, realloc, or calloc.
                If the block pointer is NULL, no action is performed.

                There is an internal routine called _free which is
                identical, except that it does not call the _free_hook
                routine.  This should be used for internal calls to
                free that do not refer to user-specified blocks.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _DEBUG
void _RTLENTRY _EXPFUNC free(void *ptr)
{
    if (_malloc_debug == 2)
        if (_heapchk() != _HEAPOK)
            _heap_error(NULL, _heap_corrupt);
    _free_hook(ptr);
    _free(ptr);
}

void _RTLENTRY _free(void *ptr)
#else
void _RTLENTRY _EXPFUNC free(void *ptr)
#endif
{
    size_t size, psize, nsize;
    PBLOCK p, q, prev, next;
    int linked;

    /* Ignore null pointer.
     */
    if (ptr == NULL)
    {
#ifdef _DEBUG
        if (_malloc_debug != 0)
            _heap_error(NULL, _heap_freenull);
#endif
        return;
    }
    p = (PBLOCK)ptr;        /* type conversion */

#ifdef _DEBUG
    /* Make sure the block is on the allocated list and not on
     * the free list.  Then remove it from the allocated list.
     */
    if (_malloc_debug != 0)
    {
        if (_is_free(p))
            _heap_error(p, _heap_free);
        _unlink_alloc(p);

    }
#endif

    /* Check for attempt to free a block that's already free.
     */
    if (((size = SIZE(p)) & 1) == 0)
    {
#ifdef _DEBUG
        if (_malloc_debug != 0)
            _heap_error(p, _heap_badsize);
#endif
        return;         /* ignore in non-debugging library */
    }
    size &= ~1;         /* remove allocated flag bit */

#ifdef _DEBUG
    /* Check for block overrun and underrun by seeing if the longwords
     * just before and after the block have been modified.
     */
    if (_malloc_debug != 0)
    {
        if (BEFORE(p) != ALLOC_SENTINEL)
            _heap_error(p, _heap_underrun);
        if (AFTER(p) != ALLOC_SENTINEL)
            _heap_error(p, _heap_overrun);
        next = p + size;
        if (SIZE(p) != PSIZE(next))
            _heap_error(p, _heap_sizemismatch);
        memset(p, 0xbf, size - OVERHEAD);   /* destroy contents of block */
    }
#endif

    _lock_heap();

    /* If previous block is free, add the new block to it.
     */
    linked = 0;
    if (((psize = PSIZE(p)) & 1) == 0)
    {
        p -= psize;     /* point to previous block */
#ifdef _DEBUG
        /* Check the previous block for consistency.
         */
        if (_malloc_debug != 0)
        {
            if (SIZE(p) != psize)
                _heap_error(p, _heap_sizemismatch);
            if (BEFORE(p) != FREE_SENTINEL)
                _heap_error(p - psize, _heap_underrun);
            if (AFTER(p) != FREE_SENTINEL)
                _heap_error(p, _heap_overrun);
        }
#endif

        size += psize;      /* merge the sizes of the two blocks */
        linked = 1;         /* it's already on the free list */
    }

    /* If the next physical block is free, merge it with this block.
     */
    q = p + size;                       /* point to next phys. block */
    if (((nsize = SIZE(q)) & 1) == 0)   /* is it free? */
    {
#ifdef _DEBUG
        /* Check the next block for consistency.
         */
        if (_malloc_debug != 0)
        {
            if (BEFORE(q) != FREE_SENTINEL)
                _heap_error(q, _heap_underrun);
            if (AFTER(q) != FREE_SENTINEL)
                _heap_error(q, _heap_overrun);
            next = q + nsize;
            if (PSIZE(next) != nsize)
                _heap_error(p, _heap_sizemismatch);
        }
#endif

        /* Unlink the next block from the free list.  If the rover
         * was pointing to this block, move the rover.
         */
        next = NEXT(q);
        prev = PREV(q);
        PREV(next) = PREV(q);
        NEXT(prev) = NEXT(q);
        if (_rover == q)
            _rover = next;

        /* Merge the sizes of this block and the next block.
         */
        size += nsize;
    }

    /* Set the boundary tags for the block; these are words just
     * before and after the block that contain the block's size.
     */
    next = p + size;
    SIZE(p) = PSIZE(next) = size;
#ifdef _DEBUG
    USIZE(p) = size - OVERHEAD;
    BEFORE(p) = AFTER(p) = FREE_SENTINEL;
#endif

    /* Link the block to the head of the free list.
     */
    if (!linked)
    {
        next = NEXT(_free_list);
        NEXT(_free_list) = p;
        NEXT(p) = next;
        PREV(p) = _free_list;
        PREV(next) = p;
    }
    _unlock_heap();
}

/*---------------------------------------------------------------------*

Name            _same_seg - check if a block lies within a 64K segment

Usage           int _same_seg(void *block, size_t size);

Prototype in    local

Description     This function checks to see that a block lies entirely
                within 64K segment.  This check is performed by
                malloc() in order to insure that an allocated block
                can be used by a 16-bit DLL.  If the block is larger
                than 64K, no checking is performed.

Return value    If the block is greater than 64K, or lies within
                a 64K segment, 1 is returned; otherwise 0.

*---------------------------------------------------------------------*/

#ifdef __OS2__
int _same_seg(PBLOCK p, size_t size)
{
    if (size > SEG_SIZE)    /* if block is greater than 64K, we don't care */
        return (1);
    else
        return (((((ULONG)p) ^ ((ULONG)(p+size-1))) & ~(SEG_SIZE-1)) == 0);
}
#endif

/*---------------------------------------------------------------------*

Name            _heapadd - add a block to the heap

Usage           int _heapadd(void *block, size_t size);

Prototype in    malloc.h

Description     This function adds a new block of memory to the heap.
                The block must not have been previously allocated from
                the heap.

Return value    If the block can be succesfully added to the heap,
                0 is returned; otherwise -1.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _heapadd(void *ptr, size_t size)
{
    PBLOCK p, next, heap_top;
    int i;

    /* Check size, then round size down to next long word boundary.
     */
    if (size < MINBLOCK)
        return (-1);
    size = (size_t)ROUND_DOWN(size,WORD_SIZE);
    p = (PBLOCK)ptr;

    _lock_heap();

    /* Search for another heap area that's contiguous with the bottom
     * of this new area.  (It should be extremely unusual to find
     * one that's contiguous with the top).
     */
    for (i = 0; i < _nheaps; i++)
    {
        heap_top = _heaps[i].base + (int)_heaps[i].len;
        if (p == heap_top)
            break;
    }
    if (i != _nheaps)
    {
        /* The new block is contiguous with a previously allocated
         * heap area.  Add its length to that of the previous heap.
         * Merge it with the the dummy end-of-heap area marker
         * of the previous heap.
         */
        _heaps[i].len += size;
    }
    else
    {
        /* The new block is not contiguous.  Add it to the heap list.
         */
        if (_nheaps == MAXHEAPS)
        {
            _unlock_heap();
            return (-1);            /* too many non-contiguous heaps */
        }
        _heaps[_nheaps].base = p;
        _heaps[_nheaps].len = size;
        _nheaps++;

        /* Reserve the first LONG in the block for the ending boundary
         * tag of a dummy block at the start of the heap area.
         */
        size -= OVERHEAD;
        p += OVERHEAD;
        PSIZE(p) = 1;       /* mark the dummy previous block as allocated */
    }

    /* Convert the heap to one large block.  Set up its boundary tags,
     * and those of marker block after it.  The marker block before the
     * heap will already have been set up if this heap is not contiguous
     * with the end of another heap.
     */
    SIZE(p) = size | 1;
    next = p + size;    /* point to dummy end block */
    PSIZE(next) = size | 1;
    SIZE(next) = 1;     /* mark the dummy end block as allocated */
#ifdef _DEBUG
    USIZE(p) = size - OVERHEAD;
    BEFORE(p) = BEFORE(next) = AFTER(p) = ALLOC_SENTINEL;
    PAFTER(p) = (PSIZE(p) & 1) ? ALLOC_SENTINEL : FREE_SENTINEL;
    if (_malloc_debug != 0)
    {
        /* Add block to the allocated list so free() won't complain.
         */
        ALINK(p) = _alloc_list;
        _alloc_list = p;
    }
#endif

    /* Link the block to the start of the free list by calling
     * free().  This will merge the block with any adjacent free blocks.
     */
    _unlock_heap();
    _free(p);
    return (0);
}

/*---------------------------------------------------------------------*

Name            malloc - allocate a block from the heap

Usage           void * malloc(size_t size);

Prototype in    local

Description     This function allocates a block from the heap.
                The contents of the block are undefined.
                If the size of the block is less than 64K, the
                block is guaranteed to not cross a 64K boundary.

Return value    If the block can be succesfully allocated, the
                address of the block is returned; otherwise NULL
                is returned.

*---------------------------------------------------------------------*/

#ifdef _DEBUG
void * _RTLENTRY _EXPFUNC __malloc(size_t size, int hook)
#else
void * _RTLENTRY _EXPFUNC malloc(size_t size)
#endif
{
    size_t realsize, lsize, rem;
    int loops;
    PBLOCK p, next, prev, newb;

#ifdef _DEBUG
    _heap_allocations++;
    if (_malloc_debug == 2)
        if (_heapchk() != _HEAPOK)
            _heap_error(NULL, _heap_corrupt);
#endif

    /* Adjust the real size of the block to be a multiple of 4,
     * and add the overhead for the boundary tags.  Disallow negative
     * or zero sizes.
     */
    if (size < MINBLOCK - OVERHEAD)
        realsize = MINBLOCK;
    else
        realsize = (size_t)ROUND_UP(size,WORD_SIZE) + OVERHEAD;
    if ((int)realsize < MINBLOCK || size == 0)
        return (NULL);

    _lock_heap();

    /* Start searching the free list at the rover.  If we arrive back
     * at rover without finding anything, allocate some memory from
     * the OS and try again.
     */
    p = _rover;             /* start searching at rover */
    loops = 0;              /* allow two times through the loop */
    for (;;)
    {
#ifdef _DEBUG
        _heap_searches++;

        /* Check this block for consistency.
         */
        if (_malloc_debug != 0 && p != _free_list)
        {
            int i;

            /* Find the heap area that contains this block.
             * If not found, the block pointer must be invalid.
             */
            for (i = 0; i < _nheaps; i++)
                if (p >= _heaps[i].base &&
                    p <= _heaps[i].base + (int)_heaps[i].len)
                break;
            if (i == _nheaps)
                _heap_error(p, _heap_corrupt);

            /* Check the sentinels on either end of the block,
             * and check the size fields for consistency.
             */
            if (BEFORE(p) != FREE_SENTINEL)
                _heap_error(p, _heap_underrun);
            if (AFTER(p) != FREE_SENTINEL)
                _heap_error(p, _heap_overrun);
            if (SIZE(p) & 1)
                _heap_error(p, _heap_notfree);
            next = p + SIZE(p);
            if (PSIZE(next) != SIZE(p))
                _heap_error(p, _heap_sizemismatch);
        }
#endif

        if ((lsize = SIZE(p)) >= realsize)      /* block is big enough? */
        {
            /* If the first part of the block lies within a 64K
             * segment, split the block and return the first part.
             */
#pragma warn -ccc
            if (_same_seg(p,size))
            {
#pragma warn .ccc
                
                prev = PREV(p);     /* next block on free list */
                next = NEXT(p);     /* previous block on free list */

                /* If the remainder is too small, don't bother
                 * splitting the block.
                 */
                if ((rem = lsize - realsize) < MINBLOCK)
                {
                    /* Unlink the block from the free list.
                     */
                    NEXT(prev) = next;
                    PREV(next) = prev;
                    if (_rover == p)
                        _rover = next;

                    /* Set the boundary tags to mark it as allocated.
                     */
                    next = p + lsize;
                    SIZE(p) = PSIZE(next) = lsize | 1;
                }
                else                /* split the block */
                {
                    /* The remainder is big enough to split off into
                     * a new block. Put it on the free list in place of
                     * the block we're going to return.
                     */
                    newb = p + realsize;
                    _rover = NEXT(prev) = newb;
                    PREV(next) = newb;
                    NEXT(newb) = next;
                    PREV(newb) = prev;

                    /* Set the boundary tags of the new block and the
                     * block we're returning.
                     */
                    next = newb + rem;
                    SIZE(p) = PSIZE(newb) = realsize | 1;
                    SIZE(newb) = PSIZE(next) = rem;
#ifdef _DEBUG
                    /* Set the overrun sentinels for the new free block.
                     */
                    USIZE(newb) = rem - OVERHEAD;
                    BEFORE(newb) = AFTER(newb) = FREE_SENTINEL;
#endif
                }
                _unlock_heap();

                /* Set the underrun/overrun sentinels for the returned block,
                 * and add it to the allocated list.
                 */
#ifdef _DEBUG
                USIZE(p) = size;
                BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;
                if (_malloc_debug != 0)
                {
                    ALINK(p) = _alloc_list;
                    _alloc_list = p;
                }
                if (hook)
                    _malloc_hook(p, size);
#endif
                return ((void *)p);
            }

            /* See if a middle part of the block of the right size
             * lies within a 64K segment.
             */
#ifdef __OS2__
            newb = (PBLOCK)ROUND_UP(p,SEG_SIZE);
            if (newb < p + lsize && newb + realsize <= p + lsize)
            {
                /* Free the first part of the block.
                 */
                rem = newb - p;
                if (rem < MINBLOCK)
                {
                    /* First part is too small to be made into a separate
                     * block.  Unlink it from the free list, then add its
                     * size to that of the previous block, which is allocated.
                     */
                    next = NEXT(p);
                    prev = PREV(p);
                    NEXT(prev) = next;      /* unlink it */
                    PREV(next) = prev;
                    if (_rover == p)        /* if rover pointed to it, */
                        _rover = next;      /*  move rover */
                    prev = p - (PSIZE(p) & ~1);
                    SIZE(prev) = PSIZE(newb) = SIZE(prev) + rem;
#ifdef _DEBUG
                    /* Set the overrun sentinel for newly-grown prev. block.
                     */
                    USIZE(prev) = SIZE(prev) - OVERHEAD;
                    AFTER(prev) = ALLOC_SENTINEL;
#endif
                }
                else
                {
                    /* Shrink the first part of the block, leaving it
                     * on the free list.
                     */
                    SIZE(p) = PSIZE(newb) = rem;
#ifdef _DEBUG
                    /* Set new overrun sentinel for first part of block.
                     */
                    USIZE(p) = rem - OVERHEAD;
                    AFTER(p) = FREE_SENTINEL;
#endif
                }

                /* Free the third part of the block.
                 */
                next = p + lsize;           /* -> the next physical block */
                p = newb;                   /* -> block we'll return */
                newb = p + realsize;        /* -> new block to be freed */
                rem = next - newb;          /* size of new free block */

                if (rem < MINBLOCK)
                {
                    /* Third part too small to split off.  Include
                     * it in the block we're returning.
                     */
                    SIZE(p) = PSIZE(next) = (next - p) | 1;
                }
                else
                {
                    /* Split off the third part of the block, add
                     * it to the free list.  Don't have to worry about
                     * merging, because the next block is allocated.
                     */
                    SIZE(p) = PSIZE(newb) = (newb - p) | 1;
                    SIZE(newb) = PSIZE(next) = rem;

                    /* Set the underrun/overrun sentinels for the new block.
                     */
#ifdef _DEBUG
                    USIZE(newb) = rem - OVERHEAD;
                    BEFORE(newb) = AFTER(newb) = FREE_SENTINEL;
#endif

                    /* Link new block to head of the free list.
                     */
                    next = NEXT(_free_list);
                    NEXT(_free_list) = newb;
                    NEXT(newb) = next;
                    PREV(newb) = _free_list;
                    PREV(next) = newb;
                }
                _unlock_heap();

                /* Set the underrun/overrun sentinels for the returned block,
                 * and add it to the allocated list.
                 */
#ifdef _DEBUG
                next = p + (SIZE(p) & ~1);
                USIZE(p) = size;
                BEFORE(p) = AFTER(p) = ALLOC_SENTINEL;
                if (_malloc_debug != 0)
                {
                    ALINK(p) = _alloc_list;
                    _alloc_list = p;
                }
                if (hook)
                    _malloc_hook(p, size);
#endif
                return ((void *)p);
            }
#endif  /* OS/2 */
        }

        /* This block was unsuitable.  If we've gone through
         * this list once already without finding anything,
         * allocate some new memory from the OS and try again.
         */
        if ((p = NEXT(p)) == _rover)
        {
            if (loops == 2)
            {
                _unlock_heap();
#ifdef _DEBUG
                if (hook)
                    _malloc_hook(p, size);
#endif
                return ((void *)NULL);
            }
            else
            {
                loops++;
                if (_getmem(realsize) != 0)
                {
                    _unlock_heap();
#ifdef _DEBUG
                    if (hook)
                        _malloc_hook(p, size);
#endif
                    return ((void *)NULL);
                }
                p = _rover;
            }
        }
    }
}

#ifdef _DEBUG

void * _RTLENTRY _EXPFUNC malloc(size_t size)
{
    return (__malloc(size, 1));     /* call user hook */
}

void * _RTLENTRY _EXPFUNC _malloc(size_t size)
{
    return (__malloc(size, 0));     /* DON'T call user hook */
}

#endif

