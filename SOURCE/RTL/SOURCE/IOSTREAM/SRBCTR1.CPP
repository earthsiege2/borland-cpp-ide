/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          strstreambuf::strstrambuf()                         |*/
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

strstreambuf::strstreambuf()
{
    allocf = 0;
    freef = 0;
    next_alloc = 0;
    ssbflags = dynamic;
}


