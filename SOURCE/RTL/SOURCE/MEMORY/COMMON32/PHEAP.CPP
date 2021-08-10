/*-----------------------------------------------------------------------*
 * filename - pheap.c
 *
 * function(s)
 *      _lock_heap      - lock the global heap lock
 *      _unlock_heap    - unlock the global heap lock
 *      _init_lock      - creates the lock for MT heap management
 *      free            - free an allocated block
 *      malloc          - allocate a block from the heap
 *      realloc         - resize a memory block from the heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.7  $        */

#include <mem.h>

#include "delphimm.h"

int __fastcall InitProntoMemoryManager(void)
{
    return 0;
}

extern "C"
{

void *_RTLENTRY _EXPFUNC malloc(size_t size)
{
    return GetMemory(size);
}

void _RTLENTRY _EXPFUNC free(void *block)
{
    FreeMemory(block);
}

void * _RTLENTRY _EXPFUNC realloc(void * block, size_t size)
{
    if	(block)
       return ReallocMemory(block, size);
    else
       return GetMemory(size);
}

void _RTLENTRY _EXPFUNC _free_heaps()
{
}

} // extern "C"








