/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbalc.cpp                                               |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::doallocate()                         |*/
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
#include <iostream.h>

int streambuf::doallocate()
{
    char *p = new char[StreambufSize];
    if( ! p )
        return EOF;
    base_ = p;
    ebuf_ = p + StreambufSize;
    alloc_ = 1;
    return 1;
}


