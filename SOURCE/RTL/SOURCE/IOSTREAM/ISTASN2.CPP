/*[]--------------------------------------------------------------------[]*/
/*|                                                                     |*/
/*|     istasn2.cpp                                                     |*/
/*|                                                                     |*/
/*|     Class istream_withassign                                        |*/
/*|     istream_withassign& istream_withassign::operator= ( streambuf* )|*/
/*|                                                                     |*/
/*[]-------------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

// associates streambuf with stream and does entire initialization

istream_withassign _FAR & istream_withassign::operator= (streambuf* s)
{
    ios::init(s);
    return *this;
}
