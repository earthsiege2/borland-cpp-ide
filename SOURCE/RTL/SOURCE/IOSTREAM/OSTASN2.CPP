/*[]-------------------------------------------------------------------[]*/
/*|                                                                     |*/
/*|     ostasn2.cpp                                                     |*/
/*|                                                                     |*/
/*|     Class ostream_withassign                                        |*/
/*|     ostream_withassign& ostream_withassign::operator= ( streambuf* )|*/
/*|                                                                     |*/
/*[]-------------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

// associates streambuf with stream and does entire initialization

ostream_withassign _FAR & ostream_withassign::operator= (streambuf* s)
{
    ios::init(s);
    x_delbuf = 0;
    return *this;
}
