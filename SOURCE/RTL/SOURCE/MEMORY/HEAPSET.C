/*-----------------------------------------------------------------------*
 * filename - heapset.c
 *
 * function(s)
 *      _heapset - fill free blocks with constant
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1995, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <stdio.h>
#include <mem.h>
#include <alloc.h>
#include <_heap.h>

int _RTLENTRY _EXPFUNC _heapset (unsigned int __fill)
{
    BLOCKHDR *bh;

    _lock_heap();
    if (_linktable)
    {
        size_t i;

        if (heapcheck () != _HEAPOK)
        {
            _unlock_heap();
            return _HEAPCORRUPT;
        }

        for (i = MINSIZE; i < _smalloc_threshold; i += ALIGNMENT)
        {
            BLOCKHDR *p = HDR4SIZE(i);

            for (bh = p->nextFree; bh != p; bh = bh->nextFree)
            {
#ifdef DBG
                printf ("* Block:%p Data:%p Size:%04X NextBlock:%p\n", bh, ((char *)HDR2PTR(bh))+8,SIZE(bh)-12, bh->nextFree);
#endif
                memset (((char *)HDR2PTR(bh))+8, __fill, SIZE(bh)-12);
            }
        }

        for (bh = _freeStart.nextFree; bh != &_freeStart; bh = bh->nextFree)
        {

#ifdef DBG
            void *q, *r;
            int sz;
            q = ((char *)HDR2PTR(bh) +8);
            sz = SIZE(bh) - 12;
            r = (void*) bh->nextFree;
            printf ("  Block:%p Data:%p Size:%04X NextBlock:%p\n", bh, q, sz, r);
#endif
            memset (((char *)HDR2PTR(bh) +8), __fill, SIZE(bh)-12);
        }
    }
    _unlock_heap();
    return _HEAPOK;
}
