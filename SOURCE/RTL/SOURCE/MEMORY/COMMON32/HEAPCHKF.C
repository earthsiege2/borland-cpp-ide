/*-----------------------------------------------------------------------*
 * filename - heapchkf.c
 *
 * function(s)
 *      heapcheckfree - check free blocks for constant value
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
#include <alloc.h>
#include <_heap.h>

int _RTLENTRY _EXPFUNC heapcheckfree(unsigned int value)
{
    HEAP *h;
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

