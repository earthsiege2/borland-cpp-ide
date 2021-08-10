/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          strstreambuf::strstrambuf()                         |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <strstrea.h>

strstreambuf::strstreambuf()
{
    allocf = 0;
    freef = 0;
    next_alloc = 0;
    ssbflags = dynamic;
}


