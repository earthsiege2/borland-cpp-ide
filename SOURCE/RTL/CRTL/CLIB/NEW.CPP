/*-----------------------------------------------------------------------*
 * filename - new.cpp
 * C++ new
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stddef.h>
#include <stdlib.h>
#include <new.h>
#include <cstring.h>
#include <except.h>

xalloc __xalloc( "Out of memory", 0 );

void xnew_handler() { throw __xalloc; }
new_handler _new_handler = xnew_handler;

new_handler set_new_handler(new_handler p)
{
    new_handler t = _new_handler;
    _new_handler = p;
    return t;
}

void *operator new( size_t size )
{
    void * p = 0;

    size = size ? size : 1;
    while ( (p = malloc(size)) == NULL && _new_handler != NULL)
        _new_handler();
    return p;
}
