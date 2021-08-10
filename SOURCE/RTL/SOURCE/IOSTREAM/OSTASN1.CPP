/*[]-----------------------------------------------------------------[]*/
/*|                                                                   |*/
/*|     ostasn1.cpp                                                   |*/
/*|                                                                   |*/
/*|     Class ostream_withassign                                      |*/
/*|     ostream_withassign& ostream_withassign::operator= ( ostream& )|*/
/*|                                                                   |*/
/*[]-----------------------------------------------------------------[]*/

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

// gets buffer from ostream and does entire initialization

ostream_withassign _FAR & ostream_withassign::operator= (ostream _FAR & os)
{
    ios::init(os.rdbuf());
    x_delbuf = 0;
    return *this;
}


