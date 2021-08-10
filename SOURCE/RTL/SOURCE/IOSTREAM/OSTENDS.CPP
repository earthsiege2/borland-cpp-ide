/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostends.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ends( ostream& )                           |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

// insert null to terminate string

ostream _FAR & _RTLENTRY _EXPFUNC32 ends(ostream _FAR & os)
{
    os << char(0);
    return os;
}


