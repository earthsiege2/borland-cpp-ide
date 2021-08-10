/*-----------------------------------------------------------------------*
 * filename - hrdir_bh.c
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <stddef.h>
#include <_hrdir.h>


/* Disable stack frames for all the functions in this file since none of
   them have local vars, and we want to get as efficient as possible.  If
   we have debug info enabled, though, we'll leave the stack frames on */

#ifndef __DEBUG__
#pragma option -k-
#endif

/* These routines are simple stubs that perform some simple tests before
   passing the requests along to the borlndmm.dll.  This is done since the
   borlndmm.dll doesn't follow all the allocation rules of C/C++ */

void _RTLENTRY _bormm_stub_FreeMem (void *block)
{
    if (block)
        _bormm_pfn_FreeMem (block);
}

void * _RTLENTRY _bormm_stub_GetMem (size_t size)
{
    if (size)
        return _bormm_pfn_GetMem (size);

    return NULL;
}

void * _RTLENTRY _bormm_stub_ReallocMem (void *block, size_t size)
{
    if (!block)
    {
        if (size)
            return _bormm_pfn_GetMem (size);
    }
    else
        if (!size)
            _bormm_pfn_FreeMem (block);
        else
            return _bormm_pfn_ReallocMem (block, size);

    return NULL;
}

void _RTLENTRY _bormm_stub_Terminate (void)
{
    _bormm_pfn_HeapRelease ();
}
