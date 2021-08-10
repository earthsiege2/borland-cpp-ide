/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbstr.cpp                                               |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          char* strstreambuf::str()                           |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
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

