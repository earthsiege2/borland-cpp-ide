/*-----------------------------------------------------------------------*
 * filename - heapchk.c
 *
 * function(s)
 *      _heapchk - check and verify heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <alloc.h>
#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include <_heap.h>
#include <_io.h>
#include <ntbc.h>
#ifdef DBG
  #define DBG_MAC(a) printf ("\nHEAP ERROR on line %ld of %s: %s\n", \
                             __LINE__, __FILE__, a)
#endif

extern size_t __allocated;

/*---------------------------------------------------------------------*

Name            _heapchk  - check the whole heap. This is a good exercise
                            to understand how the heap/block structures work.

Usage           int _heapchk(void);

Prototype in    malloc.h

Description     Walks through the whole heap and checks it for consistency

Return value    _HEAPEMPTY
                _HEAPCORRUPT
                _HEAPOK

*---------------------------------------------------------------------*/

int __memBogusAddr (void *p)
{
    /*
        This helper function takes an address and tests to see if the memory
        is valid to read from.  If not it returns 1, If so it returns 0
    */
    return IsBadReadPtr (p, 1);
}

/*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _heapchk(void)
{
    int rc;
    HEAP *h;
    BLOCKHDR *bh;
    int fnum1 = 0;
    int fnum2 = 0;
    int commitSum = 0;

#ifdef	BALANCEDFIT
    int snum = 0;
    int bnum = 0;

#endif
    int _roverFound = 0;

    _lock_heap();

    if (!_firstHeap)
        RETURN(_HEAPEMPTY);

    for (h = _firstHeap; h; h = h->nextHeap)
    {
        if (__memBogusAddr (h))
        {
            RETURN(_HEAPCORRUPT);
        }
        commitSum += h->cSize;
        for (bh = FIRSTBLOCK(h); HDR2PTR(bh) != ((char *) h + h->cSize); bh = NEXT(bh))
        {
            void *p = HDR2PTR(bh);

            if (__memBogusAddr (bh))
            {
                RETURN(_HEAPCORRUPT);
            }

            if (p < h || p > (char *) h + h->cSize)
            {
#ifdef DBG
                char buf[80];
                sprintf(buf, "Block out of range block[%p]  heap[%p]", p, h);
                DBG_MAC (buf);
#endif
                RETURN(_HEAPCORRUPT);
            }

            if (ISFREE(bh))
            {
                if (__memBogusAddr(NEXT(bh)))
                {
                    RETURN(_HEAPCORRUPT);
                }
                if (!ISPFREE(NEXT(bh)))
                {
#ifdef DBG
                    DBG_MAC("prev free bit missing");
#endif
                    RETURN(_HEAPCORRUPT);
                }

                if (PFREE(NEXT(bh)) != bh)
                {
#ifdef DBG
                    DBG_MAC("free backlink broken");
#endif
                    RETURN(_HEAPCORRUPT);
                }

                fnum1++;
            }
        }
    }
    if (commitSum != __allocated)
    {
#ifdef DBG
        DBG_MAC("allocated number is off!!!");
#endif
        RETURN(_HEAPCORRUPT);
    }

    if (_linktable)
    {
        size_t i;

        for (i = MINSIZE; i < _smalloc_threshold; i += ALIGNMENT)
        {
            BLOCKHDR *p = HDR4SIZE(i);
            if (__memBogusAddr(p))
            {
                RETURN(_HEAPCORRUPT);
            }

            for (bh = p->nextFree; bh != p; bh = bh->nextFree)
            {
                if (__memBogusAddr(bh))
                {
                    RETURN(_HEAPCORRUPT);
                }
                if (__memBogusAddr(bh->nextFree))
                {
                    RETURN(_HEAPCORRUPT);
                }
                if (bh->nextFree->prevFree != bh)
                {
#ifdef DBG
                    DBG_MAC("free list error");
#endif
                    RETURN(_HEAPCORRUPT);
                }
                if (SIZE(bh) != i)
                {
#ifdef DBG
                    DBG_MAC("bad size block in small free list");
#endif
                    RETURN(_HEAPCORRUPT);
                }

                if (!ISPFREE(NEXT(bh)))
                {
#ifdef DBG
                    DBG_MAC("bad block in free list");
#endif
                    RETURN(_HEAPCORRUPT);
                }

                if (PFREE(NEXT(bh)) != bh)
                {
#ifdef DBG
                    DBG_MAC("bad block in free list");
#endif
                    RETURN(_HEAPCORRUPT);
                }

#ifdef	BALANCEDFIT
                snum++;
#endif
                fnum2++;
            }
        }

        for (bh = _freeStart.nextFree; bh != &_freeStart; bh = bh->nextFree)
        {
            if (__memBogusAddr(bh))
            {
                RETURN(_HEAPCORRUPT);
            }
            if (__memBogusAddr(bh->nextFree))
            {
                RETURN(_HEAPCORRUPT);
            }

            if (bh->nextFree->prevFree != bh)
            {
#ifdef DBG
                DBG_MAC("free list error");
#endif
                RETURN(_HEAPCORRUPT);
            }

            if (SIZE(bh) < _smalloc_threshold)
            {
#ifdef DBG
                DBG_MAC("small block in big free list");
#endif
                RETURN(_HEAPCORRUPT);
            }

            if (!ISPFREE(NEXT(bh)))
            {
#ifdef DBG
                DBG_MAC("bad block in free list");
#endif
                RETURN(_HEAPCORRUPT);
            }

            if (PFREE(NEXT(bh)) != bh)
            {
#ifdef DBG
                DBG_MAC("bad block in free list");
#endif
                RETURN(_HEAPCORRUPT);
            }

#ifdef	BALANCEDFIT
            bnum++;
#endif
            fnum2++;

            if (bh == _rover)
                _roverFound = 1;
        }
    }

    if (!_roverFound && &_freeStart != _rover)
    {
#ifdef DBG
        DBG_MAC("_rover not in free list!");
#endif
        RETURN(_HEAPCORRUPT);
    }

    if (fnum1 != fnum2)
    {
#ifdef DBG
        DBG_MAC("Free block number mismatch");
#endif
        RETURN(_HEAPCORRUPT);
    }

#ifdef	BALANCEDFIT
    if (snum != _numSmall)
    {
#ifdef DBG
        DBG_MAC("Small block number mismatch");
#endif
        RETURN(_HEAPCORRUPT);
    }

    if (bnum != _numBig)
    {
#ifdef DBG
        DBG_MAC("Big block number mismatch");
#endif
        RETURN(_HEAPCORRUPT);
    }
#endif
    rc = _HEAPOK;
  exit:
    _unlock_heap();
    return rc;
}
