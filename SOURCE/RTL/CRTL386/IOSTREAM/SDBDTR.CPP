/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     sdbdtr.cpp                                               |*/
/*|                                                              |*/
/*|     Class stdiobuf                                           |*/
/*|          stdiobuf::~stdiobuf()                               |*/
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
#include <filesys.h>
#include <stdiostr.h>

stdiobuf::~stdiobuf()
{
    overflow(EOF);
}


