/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     sdbdtr.cpp                                               |*/
/*|                                                              |*/
/*|     Class stdiobuf                                           |*/
/*|          stdiobuf::~stdiobuf()                               |*/
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
#include <filesys.h>
#include <stdiostr.h>

stdiobuf::~stdiobuf()
{
    overflow(EOF);
}


