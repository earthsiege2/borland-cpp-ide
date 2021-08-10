/*-----------------------------------------------------------------------*
 * filename - heapset.c
 *
 * function(s)
 *      _heapset - fill free blocks with constant
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <malloc.h>
#include <string.h>
#include <_heapdbg.h>
#include <_malloc.h>
#include <_thread.h>

/* Variables from heap.c
 */
extern PBLOCK _free_list;                   /* first block on free list */
extern ULONG  _free_dummy[4];               /* dummy free block */

/*---------------------------------------------------------------------*

Name            _heapset - fill free blocks with constant value

Usage           int _heapset (unsigned int fill);

Prototype in    malloc.h

Related
functions usage int _heapchk(void);
                int _rtl_heapwalk(_HEAPINFO *__entry);

Description     _heapset checks the heap for consistency in the same manner
                as _heapchk.  It then fill every free block in the heap
                with the specified fill value.

Return value    One of the following constants is returned (values
                are defined in malloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         heap is consistent
                _HEAPBADNODE    a corrupted heap block has been found

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _heapset(unsigned int fill)
{
    int rc;
    PBLOCK p;
    size_t size;

    if ((rc = _heapchk()) != _HEAPOK)
        return (rc);

    _lock_heap();

    /* Run through the free list filling each block.  There is guaranteed
     * to be at least one dummy block on the list, which has a size of 1
     * (i.e. it's an allocated block).  We have to be careful not to
     * overwrite the double links in the first 8 bytes of the block.
     */
    p = _free_list;
    do
    {
#ifdef _DEBUG
        size = USIZE(p) + OVERHEAD;
#else
        size = SIZE(p);
#endif
        if (size > OVERHEAD + 2*sizeof(PBLOCK))
            memset(p + 2*sizeof(PBLOCK), fill, size-OVERHEAD-2*sizeof(PBLOCK));
        p = NEXT(p);
    } while (p != _free_list);

    _unlock_heap();
    return (rc);
}
