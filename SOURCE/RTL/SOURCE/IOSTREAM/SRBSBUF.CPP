/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbsbuf.cpp                                              |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          streambuf* strstreambuf::setbuf( char *, int )      |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include <strstrea.h>

streambuf* strstreambuf::setbuf(char* p, int n)
{
    if( p )
        return 0;   // can't honor this kind of request

    if( n > MinStrstreamIncr )
        next_alloc = n; // next alloc will be this many
    return this;
}


