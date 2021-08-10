/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbskpos.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          streampos streambuf::seekpos( streampos, int )      |*/
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
#include <iostream.h>

streampos streambuf::seekpos(streampos pos, int mode)
{
    return seekoff(streamoff(pos), ios::beg, mode);
}


