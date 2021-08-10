/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostends.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ends( ostream& )                           |*/
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

// insert null to terminate string

ostream _FAR & _RTLENTRY _EXPFUNC32 ends(ostream _FAR & os)
{
    os << char(0);
    return os;
}


