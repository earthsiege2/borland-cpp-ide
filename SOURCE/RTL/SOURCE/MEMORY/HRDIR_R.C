/*-----------------------------------------------------------------------*
 * filename - hrdir_r.c
 *
 * function(s)
 *
 *     realloc
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <alloc.h>
#include <_hrdir.h>

void * _RTLENTRY _EXPFUNC realloc(void * block, size_t size)
{
    return _heap_redirector.realloc (block, size);
}