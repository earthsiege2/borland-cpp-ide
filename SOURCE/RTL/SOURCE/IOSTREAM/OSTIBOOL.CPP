/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostibool.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::operator<< ( bool )               |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include <iostream.h>

ostream _FAR & _RTLENTRY _EXPFUNC32 ostream::operator<< (bool _b)
{
    if ((x_flags & boolalpha) != 0)
        *this << (_b ? "true":"false");
    else
        *this << (int) _b;
    return *this;
}


