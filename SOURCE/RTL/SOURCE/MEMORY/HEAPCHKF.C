/*-----------------------------------------------------------------------*
 * filename - heapchkf.c
 *
 * function(s)
 *      heapcheckfree - check free blocks for constant value
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

int _RTLENTRY _EXPFUNC heapcheckfree(unsigned int value)
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
                if (_memchk (((char *)HDR2PTR(bh))+8, value, SIZE(bh)-12) == 0)
                {
                    _unlock_heap();
                    return _BADVALUE;
                }
            }
        }

        for (bh = _freeStart.nextFree; bh != &_freeStart; bh = bh->nextFree)
        {
            if (_memchk (((char *)HDR2PTR(bh) +8), value, SIZE(bh) - 12) == 0)
            {
                _unlock_heap();
                return _BADVALUE;
            }
        }
    }
    _unlock_heap();
    return _HEAPOK;
}

