/*-----------------------------------------------------------------------*
 * filename - pheap.cpp (Pascal memory manager VCL based memory routines)
 *
 * function(s)
 *      _internal_free            - free an allocated block
 *      _internal_malloc          - allocate a block from the heap
 *      _internal_realloc         - resize a memory block from the heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.10 $        */

/* This file must be compiled without use of COMDEFS (-V?-) so that PUBDEFS
   will exist for malloc(), free(), and realloc(), since the PUBDUP utility
   will attempt to map them to the __org_malloc() names.
*/
#pragma option -V?-

#include <mem.h>
#include "delphimm.h"
#include "_hrdir.h"

int __fastcall InitProntoMemoryManager(void)
{
    return 0;
}

namespace { // private namespace

class MemoryManager  // Helper class for this file only
{
    public:

    MemoryManager()                        { System::GetMemoryManager(mmgr); }
    void *GetMem(size_t size)              { return mmgr.GetMem(size); }
    int FreeMem(void *p)                   { return mmgr.FreeMem(p); }
    void *ReallocMem(void *p, size_t size) { return mmgr.ReallocMem(p, size); }

    private:

    System::TMemoryManager mmgr;
};

} // unnamed namespace


extern "C"
{

void *_RTLENTRY _internal_malloc(size_t size)
{
    return MemoryManager().GetMem(size);
}

void _RTLENTRY _internal_free(void *block)
{
    if (block)
        MemoryManager().FreeMem(block);
}

void * _RTLENTRY _internal_realloc(void * block, size_t size)
{
    MemoryManager mmgr;
    if (block)
    {
        if (size == 0)
        {
            mmgr.FreeMem(block);
            return NULL;
        }
        else
            return mmgr.ReallocMem(block, size);
    }
    else if (size == 0)
        return NULL;
    else
        return mmgr.GetMem(size);
}

void _RTLENTRY _internal_free_heaps()
{
}

} // extern "C"
