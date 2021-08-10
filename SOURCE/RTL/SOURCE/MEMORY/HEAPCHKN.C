/*-----------------------------------------------------------------------*
 * filename - heapchkn.c
 *
 * function(s)
 *      heapchecknode - check and verify a single node on the heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1995, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <alloc.h>
#include <malloc.h>
#include <_heap.h>

/*---------------------------------------------------------------------*

Name            heapchecknode - check and verify a single node on the heap

Usage           int heapchecknode(void *node);

Prototype in    alloc.h

Related
functions usage int _heapchk (void);
                int _rtl_heapwalk(_HEAPINFO *__entry);

Description     If a node has been freed and heapchecknode is called
                with a pointer to the freed block, heapchecknode can
                return _BADNODE rather than the expected _FREEENTRY.
                This is because adjacent free blocks on the heap are
                merged, and the block in question no longer exists.

Return value    One of the following constants is returned (values
                are defined in alloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPCORRUPT    heap has been corrupted
                _BADNODE        node could not be found
                _FREEENTRY      node is a free block
                _USEDENTRY      node is a used block

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC heapchecknode(void *node)
{
  HEAP *h;
  BLOCKHDR *bh;

  if (heapcheck() != _HEAPOK)
    return _HEAPCORRUPT;

  _lock_heap();

  h = _firstHeap;
  bh = FIRSTBLOCK(h);

  while (h)
  {
    while (HDR2PTR(bh) != ((char *) h + h->cSize))
    {
      if (node == (void *) HDR2PTR(bh))
      {
        if (ISFREE(bh))
        {
          _unlock_heap();
          return _FREEENTRY;
        }
        else
        {
          _unlock_heap();
          return _USEDENTRY;
        }
      }

      bh = NEXT(bh);
    }
    h = h->nextHeap;
    if (h)
      bh = FIRSTBLOCK(h);
  }

  _unlock_heap();
  return _BADNODE;
}