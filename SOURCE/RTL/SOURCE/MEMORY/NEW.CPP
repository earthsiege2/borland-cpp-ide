/*-----------------------------------------------------------------------*
 * filename - new.cpp
 * C++ new
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.7 $        */


#include <stddef.h>
#include <new>
#include <stdlib.h>
#include <exception>

using namespace std;

extern new_handler _new_handler;
extern std::bad_alloc __bad_alloc;

namespace std {

new_handler _RTLENTRY _EXPFUNC set_new_handler(new_handler p)
{
    new_handler t = _new_handler;
    _new_handler = p;
    return t;
}

} // std

void * _RTLENTRY _EXPFUNC operator new( size_t size )
{
    void * p;

    size = size ? size : 1;

    /* FDIS 18.4.1.1 (3,4) now require new to throw bad_alloc if the
       most recent call to set_new_handler was passed NULL.
       To ensure no exception throwing, use the forms of new that take a
       nothrow_t, as they will call straight to malloc().
    */
    while ( (p = malloc(size)) == NULL)
        if (_new_handler)
            _new_handler();
        else
#if !defined(NOXX)
           throw __bad_alloc;
#else
           /* This is illegal according to ANSI, but if we've compiled the
              RTL without exception support we had better just return NULL.
           */
           break;
#endif


    return p;
}
