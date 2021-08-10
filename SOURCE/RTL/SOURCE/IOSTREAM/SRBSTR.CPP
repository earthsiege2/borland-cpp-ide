/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbstr.cpp                                               |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          char* strstreambuf::str()                           |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <strstrea.h>

char* strstreambuf::str()
{
    freeze(1);
    return base();
}

