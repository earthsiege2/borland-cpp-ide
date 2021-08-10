/*-----------------------------------------------------------------------*
 * filename - heapwalk.c
 *
 * function(s)
 *      _rtl_heapwalk - walk through the heap node by node
 *      _heapwalk - walk through the heap node by node (obsolete)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <alloc.h>
#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include <_heap.h>

#ifdef DBG
#define DBG_MAC(a) printf ("\nHEAP ERROR on line %ld of %s: %s\n", \
                             __LINE__, __FILE__, a)
#endif

extern size_t __allocated;

int __memBogusAddr(void *p);	/* ptr validation routine in HEAPCHK.C */

/*---------------------------------------------------------------------*

Name            heapwalk - iterates through the heap(s)

Usage           void heapwalk(void);

Prototype in    alloc.h

Description     walks through the whole heap and returns each node

Return value    _HEAPOK
                _HEAPEND
                _HEAPBADPTR

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _rtl_heapwalk(_HEAPINFO * __entry)
{
    HEAP *h;
    BLOCKHDR *bh;

    _lock_heap();
    if (__entry->_pentry == NULL)
    {
	h = _firstHeap;
	bh = FIRSTBLOCK(h);
    }
    else
    {
	h = (HEAP *) __entry->_pentry;
	bh = (BLOCKHDR *) __entry->__pentry;
    }

    while (h)
    {
	if (__memBogusAddr(h))
	    return _HEAPBADPTR;

	while (HDR2PTR(bh) != ((char *) h + h->cSize))
	{
	    if (__memBogusAddr(bh))
		return _HEAPBADPTR;

	    __entry->_useflag = (ISFREE(bh) == 0);
	    __entry->_size = SIZE(bh);

	    bh = NEXT(bh);
	    __entry->_pentry = (void *) h;
	    __entry->__pentry = (void *) bh;
	    _unlock_heap();
	    return _HEAPOK;
	}
	h = h->nextHeap;
	if (h)
	    bh = FIRSTBLOCK(h);
    }
    _unlock_heap();
    return _HEAPEND;
}

int _RTLENTRY _EXPFUNC _heapwalk(_HEAPINFO * __entry)
{
    return _rtl_heapwalk((_HEAPINFO *) __entry);
}
