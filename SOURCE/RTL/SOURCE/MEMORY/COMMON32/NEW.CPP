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
/* $Revision:   8.3  $        */


#include <stddef.h>
#include <stdlib.h>
#include <new.h>
#include <cstring.h>
#include <except.h>

extern new_handler _new_handler;

new_handler _RTLENTRY _EXPFUNC set_new_handler(new_handler p)
{
    new_handler t = _new_handler;
    _new_handler = p;
    return t;
}

void * _RTLENTRY _EXPFUNC operator new( size_t size )
{
    void * p;

    size = size ? size : 1;
    while ( (p = malloc(size)) == NULL && _new_handler != NULL)
        _new_handler();
    return p;
}
