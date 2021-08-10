/*-----------------------------------------------------------------------*
 * filename - heapchkf.c
 *
 * function(s)
 *      heapcheckfree - check free blocks for constant value
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <malloc.h>
#include <string.h>
#include <_heapdbg.h>
#include <_malloc.h>
#include <_thread.h>
#include <_io.h>

/* Helper function from memchk.asm
 */
int _memchk(void *src, int c, size_t n);

/* Variables from heap.c
 */
extern PBLOCK _free_list;                   /* first block on free list */
extern ULONG  _free_dummy[4];               /* dummy free block */

/*---------------------------------------------------------------------*

Name            heapcheckfree - check free blocks for constant value

Usage           int heapcheck (unsigned int fill);

Prototype in    alloc.h

Related
functions usage int heapfillfree(unsigned int fill);

Description     heapcheckfree checks the heap for consistency in the same manner
                as _heapchk.  It then checks that every free block in the heap
                is filled with the specified fill value.

Return value    One of the following constants is returned (values
                are defined in malloc.h):

                _HEAPEMPTY      no heap exists
                _HEAPOK         heap is consistent
                _HEAPCORRUPT    a corrupted heap block has been found
                _BADVALUE       a value other than the fill value was found

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC heapcheckfree(unsigned int fill)
{
    int rc;
    PBLOCK p;
    size_t size;

    if ((rc = _heapchk()) != _HEAPOK)
        return (_HEAPCORRUPT);

    _lock_heap();

    /* Run through the free list checking each block.  There is guaranteed
     * to be at least one dummy block on the list, which has a size of 1
     * (i.e. it's an allocated block).  We have to be careful not to
     * check the double links in the first 8 bytes of the block.
     */
    p = _free_list;
    do
    {
        if ((size = SIZE(p)) > OVERHEAD + 2*sizeof(PBLOCK))
            if (_memchk(p + 2*sizeof(PBLOCK), fill,
                        size-OVERHEAD-2*sizeof(PBLOCK)) == 0)
                RETURN (_BADVALUE);
        p = NEXT(p);
    } while (p != _free_list);

exit:
    _unlock_heap();
    return (rc);
}
