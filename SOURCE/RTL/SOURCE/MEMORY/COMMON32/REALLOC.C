/*-----------------------------------------------------------------------*
 * filename - realloc.c
 *
 * function(s)
 *      _expand         - grow or shrink a block in place
 *      realloc         - change size of block, copy contents
 *      _msize          - return size of a heap block
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1995, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <mem.h>
#include <_heap.h>

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
#ifdef  BALANCEDFIT
                _numBig--;
#endif
            }
#ifdef  BALANCEDFIT
            else
            {
                _numSmall--;
            }
#endif
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
#ifdef  BALANCEDFIT
                _numSmall++;
#endif
            }
            else
            {
                if (oldPrevFree)
                    bp=oldPrevFree;
                else
                    bp = _rover->nextFree;
#ifdef  BALANCEDFIT
                _numBig++;
#endif
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

void * _RTLENTRY _EXPFUNC grealloc(void * block, size_t size)
{
    BLOCKHDR * bh;
    size_t aSize;

    if (size == 0)
    {
        gfree(block);
        return NULL;
    }

    if (block == NULL)
        return gmalloc(size);


    if (_expand(block,size))
        return block;
    else
    {
        void * newb;
    _lock_heap();
        bh = PTR2HDR(block);
        if ((newb = gmalloc(size)) != NULL)
        {
            memmove(newb,block,MIN( size, SIZE(bh)));
            gfree(block);
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

    _lock_heap();
    bh = PTR2HDR(block);
    s = SIZE(bh);
    _unlock_heap();
    return s;
}
