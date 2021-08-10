/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbsbuf.cpp                                              |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          streambuf *streambuf::setbuf( signed char *, int )  |*/
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

streambuf* streambuf::setbuf(char* p, int len)
{
    setb(p, p + len, 0);
    return this;
}


