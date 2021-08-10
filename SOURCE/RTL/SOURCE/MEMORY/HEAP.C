/*-----------------------------------------------------------------------*
 * filename - heap.c
 *
 * function(s)
 *      _lock_heap              - lock the global heap lock
 *      _unlock_heap            - unlock the global heap lock
 *      _release_heap           - releases all the memory allocated by the heap manager
 *      _init_lock              - creates the lock for MT heap management
 *      _internal_free          - free an allocated block
 *      _heapadd                - add a block to the heap
 *      _internal_malloc        - allocate a block from the heap
 *      _internal_malloc_helper -
 *      big_malloc              -
 *      big_free                -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.12  $        */

#include <mem.h>
#include <stdio.h>
#include <windows.h>
#include <_heap.h>
#include <_thread.h>

static void _internal_free_helper(void *block);  // The work is done in here
static  * _internal_malloc_helper (size_t size); // The work is done in here

/*----------------------------------------------------------------------
 * Knuth's "boundary tag" algorithm is used to manage the heap.
 * Each block in the heap has a tag word before it, which
 * contains the size of the block and two bits:
 *  SIZE f1 f2
 *  block ...
 *  SIZE f1 f2
 *  block ...
 * The size is stored as a long word, and does not include the 4 bytes of
 * overhead that the boundary tag consumes.  Blocks are allocated
 * on LONG word boundaries, so the size is always even.  When the
 * block is allocated, bit 0 (F_FREE) of the size is set to 1.  When a block
 * is freed, it is merged with adjacent free blocks, and bit 0 of the
 * size is set to 0. Bit 1 (F_PFREE) signals that the previous block is free.
 *
 * When a block is on the free list, the first two LONG words of the block
 * contain double links. In addition, there is a tag at the end of the block,
 * which stores the size + 4. These links are not used when the block is
 * allocated, but space needs to be reserved for them.  Thus, the minimum
 * block size (not counting the tag) is 12 bytes.
 *
 * There are separate free lists for blocks smaller than _smalloc_threshold.
 * Each of these lists link free blocks of the same size. There is one list
 * for free blocks > _smalloc_threshold with a roving pointer.
 *
 * When an allocation request comes in for a block >= _smalloc_threshold,
 * the usual 'nextfit' algorithm is used with the rover. Note that the search
 * will only browse the free blocks that are >=_smalloc_threshold.
 *
 * When an allocation request is made for a block <=smalloc_threshold,
 * first we check if we have a free block of that size. Note that this is
 * very fast, since it involves only one indexing. If there is a free
 * block of the requested size, it simply needs to be unlinked from the
 * free list. If there is no such size free block, we will take the rover
 * (>=_smalloc_threshold). If there are no blocks > _smalloc_threshold,
 * we will scan forward in the 'small' list until we find any free
 * blocks.
 *
 * See <heap.h> for the definition and description of the macros
 * and structures used to access heap blocks.
 */

/*----------------------------------------------------------------------
 * Internal public variables.
 */
size_t _virt_heap_size = 0x400000;      // reserve that much for a heap

size_t _virt_chunk_size = 0x010000;     // commit that much at once

size_t _virt_chunk_size2 = 0x001000;    // commit that much at once after going virtual

size_t _nv_heap_size = 0x100000;        // take that much for a heap if no virtual memory support

size_t _smalloc_threshold = 4096;       // small block allocation threshold. Uses *2 bytes overhead

size_t _virt_chunk_free = 0x020000;     // free if that much is free

size_t _virt_chunk_free2 = 0x002000;    // free if that much is free if virtual

HEAP  *_firstHeap = NULL;
HEAP  *_lastHeap = NULL;
DLINK *_linktable = NULL;               // vector of double link list headers for blocks < _smalloc_threshold

// free list header for blocks > _smalloc_threshold
BLOCKHDR _freeStart = {0 + F_FREE, &_freeStart, &_freeStart};

// _rover for blocks > _smalloc_threshold
BLOCKHDR *_rover = &_freeStart;

static size_t avail = 0;
size_t __allocated  = 0;

#ifdef _MT
lock_t _heap_lock;                      // heap semaphore

/*---------------------------------------------------------------------*

Name            _init_lock - creates the lock for the global heap

Usage           void _init_lock(void);

Prototype in    _heap.h

Return value    None.

*---------------------------------------------------------------------*/

void _init_lock (void)
{
#pragma startup _init_lock 1 /* Initializes the MT locks for the heap */

    // Create the lock used to govern access to the heap.
    _create_lock(&_heap_lock,"creating heap lock");
}


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
    _lock(_heap_lock, "locking heap");
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
    _unlock(_heap_lock, "unlocking heap");
}
#endif /* _MT */

/*---------------------------------------------------------------------*

Name            _table_init - initializes the headers for small blocks

Usage           int _table_init(void)

Prototype in

Description

Return value    None

*---------------------------------------------------------------------*/

static void _table_init(void)
{
    int i;
    BLOCKHDR *stopper;

    for (i = MINSIZE; i < (int)_smalloc_threshold; i += ALIGNMENT)
    {
        BLOCKHDR *p = HDR4SIZE(i);

        p->nextFree = p;
        p->prevFree = p;
    }
    stopper = HDR4SIZE(_smalloc_threshold);
    stopper->nextFree = NULL;
    stopper->prevFree = NULL;
}


/*---------------------------------------------------------------------*

Name            _vheapadd - add a block to the heap

Usage           int _vheapadd(void *block, size_t cSize, size_t rSize);

Prototype in    malloc.h

Description     This function adds a new block of memory to the heap.
                The block must not have been previously allocated from
                the heap.

Return value    If the block can be successfully added to the heap,
                0 is returned; otherwise -1.

*---------------------------------------------------------------------*/

static int _RTLENTRY _EXPFUNC _vheapadd(void *ptr, size_t cSize, size_t rSize)
{
    BLOCKHDR *b, *bp;
    HEAP *h = (HEAP *) ptr;
    size_t tsize = 0, size;

    if (cSize < PAGESIZE)
        return -1;

    // create the heap header

    h->numSysBlocks = 1;
    h->sysBlocks[0] = ptr;

    h->cSize = cSize;
    h->rSize = rSize;

    // add it to the list of heaps

    h->nextHeap = _firstHeap;
    h->prevHeap = NULL;
    if (_firstHeap)
        _firstHeap->prevHeap = h;
    else
        _lastHeap = h;

    _firstHeap = h;

    // Setup zero length allocated block

    b = FIRSTBLOCK(h);
    b->blockSize = 0;                   // size 0 , used, prev used.
    b = NEXT(b);

    // If table has not been initialized, allocate block and initialize
    if (!_linktable)
    {
        tsize = ALIGNUPBY(_smalloc_threshold * (sizeof(DLINK) / ALIGNMENT), ALIGNMENT);
        _linktable = HDR2PTR(b);
        b->blockSize = tsize;
        b = NEXT(b);
        _table_init();
        tsize += sizeof(size_t);
    }

    // Setup huge free block

    // Size of block is (committed size) - (heap header) -
    //                  (zero length block + free block header + last block header) -
    //                  (linktable size)
    size = cSize - sizeof(HEAP) - 3 * sizeof(size_t) - tsize;
    b->blockSize = size + F_FREE;

    // Set last block header
    NEXT(b)->blockSize = 0 + F_PFREE;   // size 0, used, prev free.

    if (size < _smalloc_threshold)
    {
        bp = HDR4SIZE(size);
    }
    else
    {
        bp = _rover;
    }

    ADDFREEAFTER(b, bp);
    SETFSIZE(b, size);

    return 0;
}


/*---------------------------------------------------------------------*

Name            _heapadd - add a block to the heap

Usage           int _heapadd(void *block, size_t size);

Prototype in    malloc.h

Description     This function adds a new block of memory to the heap.
                The block must not have been previously allocated from
                the heap.

Return value    If the block can be successfully added to the heap,
                0 is returned; otherwise -1.

*---------------------------------------------------------------------*/
#if 0
   int _RTLENTRY _EXPFUNC _heapadd(void *ptr, size_t size)
   {
       return _vheapadd(ptr, size, size);
   }
#endif
/*---------------------------------------------------------------------*

Name            _heapresize - resize a heap

Usage           int _heapresize (HEAP * h, size_t newSize);

Prototype in    malloc.h

Description     This function adds a new block of memory to the heap.
                The block must not have been previously allocated from
                the heap.

Return value    If the block can be successfully added to the heap,
                0 is returned; otherwise -1.

*---------------------------------------------------------------------*/

static int _heapresize(HEAP * h, size_t cSize)
{
    size_t delta;
    BLOCKHDR *b;

    cSize = ALIGNDNBY(cSize, PAGESIZE);

    b = LASTBLOCK(h);

    if (cSize < h->cSize)
    {
        // shrink
        if (ISPFREE(b))
        {
            b = PFREE(b);
            delta = h->cSize - cSize;

            //if (SIZE(b) + MINFREE < delta)
            if (SIZE(b) - MINFREE < delta)
            {
                return -1;
            }

            b->blockSize -= delta;
            SETFSIZE(b, SIZE(b));
            NEXT(b)->blockSize = 0 + F_PFREE;

            if (SIZE(b)<_smalloc_threshold)
            {
                // the block needs to move
                REMOVEFREE(b);
                ADDFREEAFTER(b, HDR4SIZE(SIZE(b)));
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        // grow

        delta = cSize - h->cSize;

        b->blockSize += delta - sizeof(size_t);             // was 0, now it is cSize

        NEXT(b)->blockSize = 0;

        _internal_free_helper(HDR2PTR(b));

        h->cSize += delta;

    }

    return 0;
}


/*---------------------------------------------------------------------*

Name            _get_more_heap - allocate more memory from the system for heap

Usage           void  _get_more_heap(size_t minSize);

Prototype in    local

Description     This function allocates more system memory by growing a heap
                                or adding a new one.

Return value    none.

*---------------------------------------------------------------------*/

static int _get_more_heap(size_t minSize)
{
    HEAP *h;
    void *v;
    size_t vsize;
    size_t csize;
    size_t aMinSize = ALIGNUPBY(minSize, PAGESIZE);

    if (!avail)
        avail = _phys_avail();

    if (!_linktable)
        aMinSize += ALIGNUPBY(_smalloc_threshold * (sizeof(DLINK) / ALIGNMENT) + sizeof(HEAP)+12, PAGESIZE);

    for (h = _firstHeap; h; h = h->nextHeap)
    {
        if (h->rSize - h->cSize > aMinSize)
        {
            size_t newSize = MIN(h->rSize, h->cSize + ALIGNUPBY(aMinSize, avail > __allocated + _virt_chunk_size ? _virt_chunk_size : _virt_chunk_size2));

            if (_virt_commit((char *) h + h->cSize, newSize - h->cSize) != 0)
            {
                // should never fail
                __allocated += newSize - h->cSize;
                _heapresize(h, newSize);

                return 0;
            }
            // otherwise, try to commit PAGESIZE
            else if(_virt_commit ((char *) h+h->cSize, PAGESIZE))
            {
                __allocated+= PAGESIZE;
                _heapresize(h, h->cSize+PAGESIZE);

                return 0;
            }
            // we are out of memory, not worth trying more
            else
            {
              return -1;
            }
        }
    }

    if (_virt_reserve(MAX(_virt_heap_size, aMinSize+PAGESIZE), &v, &vsize) == 0) /* fix for bts-37621 */
    {
        return -1;
    }

    csize = ALIGNUPBY(aMinSize + PAGESIZE, avail > __allocated + _virt_chunk_size ? _virt_chunk_size : _virt_chunk_size2);

    for (h = _firstHeap; h; h = h->nextHeap)
    {
        if ((char *) h + h->rSize == v && h->numSysBlocks < MAXSYSBLOCKS)
        {
            size_t g = h->rSize - h->cSize;

            // merge the heaps and commit overlapping

            if (g)
            {
                if (_virt_commit((char *) h + h->cSize, g) != 0)
                {
                    __allocated += g;
                    _heapresize(h, h->rSize);
                }
                else
                {
                    return -1;
                }
            }

            if (_virt_commit(v, csize - g) != 0)
            {
                __allocated += csize - g;
                h->sysBlocks[h->numSysBlocks++] = v;
                h->rSize += vsize;
                _heapresize(h, h->cSize + csize - g);

                return 0;
            }
            else
            {
                return -1;
            }
        }
    }

    if (_virt_commit(v, csize) == 0)
    {
        _virt_release(v);
        return -1;
    }

    // should never fail

    __allocated += csize;
    _vheapadd(v, csize, vsize);

    return 0;
}


/*---------------------------------------------------------------------*

Name            _release_heap_at

Usage

Prototype in

Description


Return value

*---------------------------------------------------------------------*/

static int _release_heap_at(BLOCKHDR * b)
{
    HEAP *h;
    BLOCKHDR *bn;
    size_t delta;
    size_t freethreshold;

    bn = NEXT(b);
    freethreshold = avail > __allocated ? _virt_chunk_free : _virt_chunk_free2;

    if (b->blockSize-MINFREE < freethreshold)
    {
        return 0;
    }

    delta = ALIGNDNBY(b->blockSize-MINFREE, freethreshold);

    for (h = _firstHeap; h; h = h->nextHeap)
    {
        if (LASTBLOCK(h) == bn)
        {
            // we can shrink this heap

            size_t newSize = h->cSize - delta;

            // we made sure it will not fail
            _heapresize(h, newSize);

            while ((char *) h + newSize <= h->sysBlocks[h->numSysBlocks - 1])
            {
                // release attached block

                size_t s = h->cSize - (h->sysBlocks[--h->numSysBlocks] -(char*)h);

                _virt_decommit(h->sysBlocks[h->numSysBlocks], s);
                __allocated -= s;

                _virt_release(h->sysBlocks[h->numSysBlocks]);
                h->cSize = h->rSize = h->sysBlocks[h->numSysBlocks] - (char *) h;
            }

            _virt_decommit(((char *) h) + newSize, h->cSize - newSize); /* fix for bts-13191 */
            /* Thanks to Dean Elhard for this fix */

            __allocated -= h->cSize - newSize;
            h->cSize = newSize;

            return 1;
        }
    }

    return 0;
}

/*---------------------------------------------------------------------*

Name            big_free - free an allocated big block

Description     Return a block to the heap.  The block must have
                previously allocated with big_malloc or big_realloc.
                If the block pointer is NULL, no action is performed.

Return value    None.

*---------------------------------------------------------------------*/

static __inline void big_free(void *block)
{
    // Back up to the beginning of the xtra size (which is where the
    // allocated block physically starts), and then free the whole thing.

    _virt_release(((char *)block)-XTRA_SIZE);
}

/*---------------------------------------------------------------------*

Name            _internal_free - free an allocated block

Usage           void _internal_free(void *block);

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


void _RTLENTRY _internal_free(void *block)
{
    if (!block)
        return;

    if (IS_BIG_BLOCK (block))
        big_free (block);
    else
        _internal_free_helper (block);
}

static void _internal_free_helper(void *block)
{
    BLOCKHDR *b, *nb, *bp;
    size_t s;

    if (!block)
        return;

    _lock_heap();

    b = PTR2HDR(block);

    if (ISPFREE(b))
    {
        // previous block is free, merge it

        BLOCKHDR *bp = PFREE(b);

        bp->blockSize += SIZE(b) + sizeof(size_t);
        b = bp;

        if (_rover == b)
            _rover = _rover->nextFree;
        REMOVEFREE(b);
    }
    else
    {
        // can't merge back, mark it free and simply add it to the free list
        b->blockSize |= F_FREE;
    }

    if (ISFREE(nb = NEXT(b)))
    {
        // merge forward
        b->blockSize += SIZE(nb) + sizeof(size_t);

        if (_rover == nb)
            _rover = nb->nextFree;

        REMOVEFREE(nb);
    }

    NEXT(b)->blockSize |= F_PFREE;

    // reinsert b to free list
    s = SIZE(b);

    if (s < _smalloc_threshold)
    {
        bp = HDR4SIZE(s);
    }
    else
    {
        bp = _rover->nextFree;
    }

    ADDFREEAFTER(b, bp);
    SETFSIZE(b, s);

    // check if we can shrink the heap
    if (NEXT(b)->blockSize == 0 + F_PFREE && b->blockSize > (avail > __allocated ? _virt_chunk_free : _virt_chunk_free2))
    {
        _release_heap_at(b);
    }
    _unlock_heap();
}


/*---------------------------------------------------------------------*

Name            big_malloc - allocate a big block from the heap

Description     This function allocates a big block from the heap.
                The contents of the block are undefined.

Return value    If the block can be successfully allocated, the
                address of the block is returned; otherwise NULL
                is returned.

*---------------------------------------------------------------------*/

static void * big_malloc(size_t size)
{
    char *ptr = NULL;

    size = ALIGNUPBY(size+XTRA_SIZE, PAGESIZE);  // Page round up + xtra size

    if (_virt_alloc((void **)&ptr, size))
    {
        ptr += XTRA_SIZE;                        // Adjust for the size slot
        SET_BLOCK_SIZE(ptr, size - XTRA_SIZE);   // Store the block size
    }
    return ptr;
}

/*---------------------------------------------------------------------*

Name            _internal_malloc - allocate a block from the heap

Usage           void * _internal_malloc(size_t size);

Prototype in    local

Description     This function allocates a block from the heap.
                The contents of the block are undefined.
                If the size of the block is less than 64K, the
                block is guaranteed to not cross a 64K boundary.

Return value    If the block can be successfully allocated, the
                address of the block is returned; otherwise NULL
                is returned.

*---------------------------------------------------------------------*/

void * _RTLENTRY _internal_malloc(size_t size)
{
    if (!size)
        return NULL;

    if (IS_BIG_SIZE (size))
        return big_malloc (size);

    return _internal_malloc_helper (size);
}

static  * _internal_malloc_helper (size_t size)
{
    size_t aSize;
    size_t saveSize;
    BLOCKHDR *fh;
    void *vp;

    if (!size)
        return NULL;

    _lock_heap();

    if (size < MINSIZE)
        aSize = MINSIZE;
    else
        aSize = ALIGNUPBY(size, ALIGNMENT);

    if (!_linktable)
        _get_more_heap(1);


    if (aSize < _smalloc_threshold)
    {
        fh = HDR4SIZE(aSize);

        if (fh->nextFree != fh)
        {
            fh = fh->nextFree;
            fh->blockSize &= ~F_FREE;   // size remains, but now it's used

            NEXT(fh)->blockSize &= ~F_PFREE;
            REMOVEFREE(fh);
            vp = HDR2PTR(fh);
            _unlock_heap();
            return vp;
        }

#if 0
            // we won't need to search the 'big list' _rover should be perfect
            fh = _rover;
            if (fh == &_freeStart)
                fh = fh->nextFree;
#else // potential fix to one type of fragmentation:

            // we don't need to search the 'big list', any block on the
            // list is going to be > _smalloc_threshold, so grab the
            // first one.  we do not use _rover to minimize fragmentation.
            fh = _freeStart.nextFree;
#endif
            // if 'big block list' is empty, find a small slot

            if (_freeStart.nextFree == &_freeStart)
            {
                // scan the free list vector for an entry. It will be terminated
                // by the 'stopper', whose ->nextFree is NULL.


                for (fh = HDR4SIZE(aSize + ALIGNMENT); fh->nextFree == fh; ((DLINK *) fh)++)
                    ;

                if (fh->nextFree)
                    fh = fh->nextFree;  // found
                else
                    fh = _rover;        // not found (out of memory)
            }
    }
    else                                //  aSize >= _smalloc_threshold
    {
        if ((saveSize = (fh = _rover)->blockSize) < aSize)
        {
            _rover->blockSize = 0xFFFFFFFCL + F_FREE;

            for (fh = fh->nextFree; fh->blockSize < aSize; fh = fh->nextFree)
                ;

            _rover->blockSize = saveSize;
            if (fh == _rover)
                fh = &_freeStart;
        }
    }

    if (fh != &_freeStart)
    {
        size_t fSize = SIZE(fh);

        if (fSize - aSize < MINFREEH)
        {

            fh->blockSize &= ~F_FREE;   // size remains, but now it's used

            NEXT(fh)->blockSize &= ~F_PFREE;
            if (fSize >= _smalloc_threshold)
            {
                _rover = fh->nextFree;
            }

            REMOVEFREE(fh);
            vp = HDR2PTR(fh);
            _unlock_heap();
            return vp;
        }
        else
        {
            // split block

            BLOCKHDR *nh, *f;
            size_t s;

            fh->blockSize = aSize;      // that takes it too

            nh = NEXT(fh);
            s = fSize - aSize - sizeof(size_t);
            nh->blockSize = s + F_FREE;

            SETFSIZE(nh, s);
            if (s < _smalloc_threshold)
            {
                f = HDR4SIZE(s);
                ADDFREEAFTER(nh, f);
                if (fh == _rover)
                    _rover = fh->nextFree;

                REMOVEFREE(fh);
            }
            else
            {
                fh->prevFree->nextFree = nh;
                nh->prevFree = fh->prevFree;
                fh->nextFree->prevFree = nh;
                nh->nextFree = fh->nextFree;

                _rover = nh;
            }

            vp = HDR2PTR(fh);
            _unlock_heap();
            return vp;
        }
    }
    else
    {

        if (_get_more_heap(size + 64) == 0)
        {
            _unlock_heap();
            return _internal_malloc_helper(size);
        }

        else
        {
            _unlock_heap();
            return NULL;
        }
    }
}


size_t  _phys_avail(void)
{
    MEMORYSTATUS mst;
    mst.dwLength = sizeof(MEMORYSTATUS);
    GlobalMemoryStatus(&mst);

    return  mst.dwAvailPhys;
}

void _RTLENTRY _internal_free_heaps()
{
    HEAP *h, *nexth;
    int i;

    for (h = _firstHeap; h; h = nexth)
    {
        nexth = h->nextHeap;
        for (i = --h->numSysBlocks; i>=0 ; i--)
        {
            size_t s = h->cSize - (h->sysBlocks[i] -(char*)h);
            void *p = h->sysBlocks[i];

            h->cSize = h->rSize = h->sysBlocks[i] - (char *) h;

            _virt_decommit(p, s);
            _virt_release(p);
        }
    }
}
