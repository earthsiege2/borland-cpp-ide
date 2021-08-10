/*[]-------------------------------------------------------------------[]*/
/*|                                                                     |*/
/*|     iostasn2.cpp                                                    |*/
/*|                                                                     |*/
/*|     Class iostream_withassign                                       |*/
/*|  iostream_withassign& iostream_withassign::operator= ( streambuf * )|*/
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
iostream_withassign _FAR & iostream_withassign::operator= (streambuf* s)
{
    ios::init(s);
    return *this;
}

