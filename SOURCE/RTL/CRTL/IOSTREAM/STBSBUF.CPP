/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbsbuf.cpp                                              |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          streambuf *streambuf::setbuf( signed char *, int )  |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1992 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

streambuf* streambuf::setbuf(char* p, int len)
{
    setb(p, p + len, 0);
    return this;
}


