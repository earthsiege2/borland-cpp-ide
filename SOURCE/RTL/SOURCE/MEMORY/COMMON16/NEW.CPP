/*-----------------------------------------------------------------------*
 * filename - new.cpp
 * C++ new
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stddef.h>
#include <stdlib.h>
#include <new.h>
#include <rtldata.h>

#if !defined(_BUILDRTLDLL)
extern new_handler _new_handler;
#endif

new_handler _EXPFUNC set_new_handler(new_handler p)
{
    _QRTLDataBlock;
    new_handler t = _QRTLInstanceData(_new_handler);
    _QRTLInstanceData(_new_handler) = p;
    return t;
}

/*
    This block of code pre-allocates a block of memory that gets
    freed before new() calls the new_handler function.  This is to ensure
    that there is a small amount of memory availible to throw the XALLOC
    exception in our default handler or for the user to use from their
    new_handler.

*/
#define _EXTRA_BLOCK_SIZE 64
static void *_extra_cpp_memory;

static void _init_extra_cpp_memory (void)
{
  _extra_cpp_memory = malloc (_EXTRA_BLOCK_SIZE);
}
static void _free_extra_cpp_memory (void)
{
  if (_extra_cpp_memory)
  {
    free (_extra_cpp_memory);
    _extra_cpp_memory = NULL;
  }
}

#pragma startup _init_extra_cpp_memory 20
#pragma exit    _free_extra_cpp_memory 20

void * _EXPFUNC operator new( size_t size )
{
    _QRTLDataBlock;
    void * p = 0;

    size = size ? size : 1;
    while ( (p = malloc(size)) == NULL && _QRTLInstanceData(_new_handler) != NULL)
    {
        _free_extra_cpp_memory();
        _QRTLInstanceData(_new_handler)();
    }
    return p;
}
