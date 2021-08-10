/*[]-------------------------------------------------------------------[]*/
/*|                                                                     |*/
/*|     ostasn2.cpp                                                     |*/
/*|                                                                     |*/
/*|     Class ostream_withassign                                        |*/
/*|     ostream_withassign& ostream_withassign::operator= ( streambuf* )|*/
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

ostream_withassign _FAR & ostream_withassign::operator= (streambuf* s)
{
    ios::init(s);
    x_delbuf = 0;
    return *this;
}
