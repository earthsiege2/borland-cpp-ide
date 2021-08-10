/*-----------------------------------------------------------------------*
 * filename - hrdir_mf.c
 *
 * function(s)
 *
 *     malloc
 *     free
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <alloc.h>
#include <_hrdir.h>

void * _RTLENTRY _EXPFUNC malloc(size_t size)
{
    return _heap_redirector.malloc (size);
}

void _RTLENTRY _EXPFUNC free(void *block)
{
    _heap_redirector.free (block);
}
