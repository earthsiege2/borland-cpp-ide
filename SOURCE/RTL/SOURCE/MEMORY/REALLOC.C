/*-----------------------------------------------------------------------*
 * filename - realloc.c
 *
 * function(s)
 *      _expand           - grow or shrink a block in place
 *      _internal_realloc - change size of block, copy contents
 *      _msize            - return size of a heap block
 *      big_realloc       - realloc for large block sizes
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.7  $        */

#include <stdio.h>
#include <mem.h>
#include <_heap.h>
#include <_io.h>
#include <windows.h>

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

void * _RTLENTRY _EXPFUNC _expand(void * block, size_t size)
{
    BLOCKHDR * bh, * nh;
    size_t aSize, fSize;

    _lock_heap();

    bh = PTR2HDR(block);
    nh = NEXT(bh);

    if (size <MINSIZE)
        aSize = MINSIZE;
    else
        aSize = ALIGNUPBY(size,ALIGNMENT);

    fSize = SIZE(bh);

    if (fSize==aSize)
    {
      _unlock_heap();
      return block;
    }

    if (ISFREE(nh))
        fSize += SIZE(nh)+sizeof(size_t);

    // fsize is the biggest size we can grow

    if (fSize >= aSize)
    {
        BLOCKHDR * oldPrevFree = NULL;

        // yes, we can grow/shrink in place. First, remove the next free
        // block if any by merging it with our block

        if (ISFREE(nh))
        {
            if (SIZE(nh)>= _smalloc_threshold)
                oldPrevFree = nh->prevFree;
            if (_rover==nh)
            {
                _rover = nh->nextFree;
            }

            REMOVEFREE(nh);
            NEXT(nh)->blockSize &= ~F_PFREE;
            bh->blockSize = fSize+(bh->blockSize&F_PFREE);      // merge it into our block
        }

        // if enough room to create a new free block, do so.

        if ( fSize-aSize >= MINFREEH)
        {
            BLOCKHDR * bp;
            size_t s = fSize-aSize-sizeof(size_t);

            // shrink it back to requested size

            bh->blockSize = aSize + (bh->blockSize&F_PFREE); // shrink it
            nh = NEXT(bh);
            nh->blockSize = s + F_FREE;

            NEXT(nh)->blockSize|=F_PFREE;

            // reinsert nh to free list

            if (s<_smalloc_threshold)
            {
                bp = HDR4SIZE(s);
            }
            else
            {
                if (oldPrevFree)
                    bp=oldPrevFree;
                else
                    bp = _rover->nextFree;
            }

            ADDFREEAFTER(nh,bp);
            SETFSIZE(nh,s);

        }

      _unlock_heap();
      return block;
    }
    _unlock_heap();
    return NULL;
}


/*---------------------------------------------------------------------*

Name            big_realloc - realloc for large block sizes

Description     This function is called from the normal realloc routine
                if the block size is larger than a threshold set in
                _HEAP.H.  It behaves on these large blocks in a similar
                way to the original realloc routine.

Return value    If the block can be succesfully resized, the
                address of the block is returned; otherwise NULL
                is returned.

*---------------------------------------------------------------------*/
static void * big_realloc(void * block, size_t size)
{
    size_t bsize;
    size_t asize;

    bsize = BLOCK_SIZE(block);             // calculate the original block size

    asize = ALIGNUPBY(size+XTRA_SIZE, PAGESIZE); // calculate page rounded size + xtra

    if (asize-XTRA_SIZE == bsize)          // if same size is requested, simply
        return block;                      // return the same block
                                           // Also, larger requests which fit
                                           // within the original page
                                           // aligned block will round up to
                                           // this same size and cause the same
                                           // block to be returned.

    if (asize-XTRA_SIZE > bsize)           // Block must be resized larger...
    {
        void *newb;

        // *1
        // lock the heap so that another thread doesn't encounter an
        // out-of-memory condition both the old and new blocks are
        // allocated.
        _lock_heap();

        // allocate a new block with XTRA_SIZE padding for the size field
        newb = _internal_malloc(size);
        if (newb != NULL)
        {
            // _internal_malloc will adjust the size accordingly and add in
            // XTRA_SIZE itself.

            memcpy(newb, block, bsize);    // copy the user's old data to the
                                           // new addr.

            _internal_free(block);         // free the user's old block.
        }

        _unlock_heap();
        return newb;
    }
    else                                   // Block can be resized smaller...
    {
        if (!IS_BIG_SIZE(asize-XTRA_SIZE)) // The shrink request falls below
        {                                  // the threshold of a big block
                                           // so we'll call malloc to
                                           // allocate a new small block, and
                                           // then free this one.
            // allocate a new small block
            void *newb = _internal_malloc(size);

            _lock_heap();                  // see *1 above.
            if (newb != NULL)
            {
                memcpy(newb, block, size); // copy the user's old data to the new addr.
                _internal_free(block);     // free the user's old block
            }
            _unlock_heap();
            return newb;
        }
        else
        {
            // At this point we know that the new adjusted size is smaller
            // than the original block by some multiple of full pages.
            // This means that we can release the unused pages with a call
            // to _virt_decommit.

            _virt_decommit((char *)block - XTRA_SIZE + asize, (bsize+XTRA_SIZE) - asize);
            SET_BLOCK_SIZE(block, asize-XTRA_SIZE);  // store the new size in the block
            return block;
        }
    }
}


/*---------------------------------------------------------------------*

Name            _internal_realloc - change size of block, copy contents

Usage           void * _internal_realloc(void *block, size_t size);

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

void * _RTLENTRY _internal_realloc(void * block, size_t size)
{
    BLOCKHDR * bh;
    void * newb;

    if (size == 0)
    {
        _internal_free(block);
        return NULL;
    }

    if (block == NULL)
        return _internal_malloc(size);

    if (IS_BIG_BLOCK (block))
    {
        return big_realloc (block, size);
    }
    else
    if (_expand(block,size))
        return block;
    else
    {
        bh = PTR2HDR(block);
        /* locking the heap here is not required to prevent corruption
         * of the heap's data structures, but rather to reduce the
         * likelihood of an out-of-memory failure if another thread
         * attempts to malloc something while we temporarily have
         * allocated extra memory.
         */
        _lock_heap();
        if ((newb = _internal_malloc(size)) != NULL)
        {
            memmove(newb,block,MIN( size, SIZE(bh)));
            _internal_free(block);
        }
        _unlock_heap();
        return newb;
    }
}

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
    size_t s;
    BLOCKHDR * bh;
    if (block == NULL)
        return 0;

    bh = PTR2HDR(block);
    s = SIZE(bh);

    return s;
}
