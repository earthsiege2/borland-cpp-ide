/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbstr.cpp                                               |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          char* strstreambuf::str()                           |*/
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

char* strstreambuf::str()
{
    freeze(1);
    return base();
}

