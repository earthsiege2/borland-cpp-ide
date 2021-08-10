/*-----------------------------------------------------------------------*
 * filename - heap.c
 *
 * function(s)
 *      _lock_heap      - lock the global heap lock
 *      _unlock_heap    - unlock the global heap lock
 *      _init_heap      - set up the heap variables
 *      free            - free an allocated block
 *      same_seg        - check if a block lies within a 64K segment
 *      _heapadd        - add a block to the heap
 *      get_mem         - allocate new memory for the heap
 *      malloc          - allocate a block from the heap
 *      _expand         - grow or shrink a block in place
 *      realloc         - change size of block, copy contents
 *      _msize          - return size of a heap block
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef _DEBUG
#error heaperr.c must be compiled with _DEBUG defined
#endif

#include <stdio.h>
#include <_heapdbg.h>
#include <_malloc.h>
#include <_io.h>

void (* _RTLENTRY _EXPDATA _error_hook)  (void *block, _heaperr_t errtype);

void _RTLENTRY _EXPFUNC _heap_error (PBLOCK ptr, _heaperr_t type)
{
    char buf[60];
    char *fmt;

    /* If user has set up an error hook, call it and return.
     */
    if (_error_hook)
    {
        _error_hook(ptr, type);
        return;
    }

    /* User hasn't set up an error hook.  Print our own message and exit.
     */
    switch(type)
    {
    case _heap_overrun:
        fmt = "%p: block overrun";
        break;
    case _heap_underrun:
        fmt = "%p: block underrun";
        break;
    case _heap_notallocated:
        fmt = "%p: block was not allocated";
        break;
    case _heap_notfree:
        fmt = "%p: block was not free";
        break;
    case _heap_sizemismatch:
        fmt = "%p: block size fields do not match";
        break;
    case _heap_corrupt:
        fmt = "heap corrupted";
        break;
    case _heap_freenull:
        fmt = "attempt to free NULL pointer";
        break;
    case _heap_badsize:
        fmt = "%p: bad size field";
        break;
    case _heap_free:
        fmt = "%p: block already free";
        break;
    default:
        fmt = "%p: unknown heap error";
        break;
    }
    sprintf(&buf[sprintf(buf, "Heap Error: ")], fmt, ptr);
    _ErrorExit(buf);
}
