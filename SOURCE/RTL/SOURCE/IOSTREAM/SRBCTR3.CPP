/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbctr3.cpp                                              |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          strstreambuf::strstreambuf( int )                   |*/
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

strstreambuf::strstreambuf(int n)
{
    if( n < MinStrstreamAlloc )
        n = MinStrstreamAlloc;
    char *p = new char[n];
    setb(p, p+n, 0);
    *p = 0;
    allocf = 0;
    freef = 0;
    next_alloc = 0;
    ssbflags = dynamic;
}

