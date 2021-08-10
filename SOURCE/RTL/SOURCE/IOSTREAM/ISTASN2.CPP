/*[]--------------------------------------------------------------------[]*/
/*|                                                                     |*/
/*|     istasn2.cpp                                                     |*/
/*|                                                                     |*/
/*|     Class istream_withassign                                        |*/
/*|     istream_withassign& istream_withassign::operator= ( streambuf* )|*/
/*|                                                                     |*/
/*[]-------------------------------------------------------------------[]*/

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

// associates streambuf with stream and does entire initialization

istream_withassign _FAR & istream_withassign::operator= (streambuf* s)
{
    ios::init(s);
    return *this;
}
