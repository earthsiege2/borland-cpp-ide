/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istws.cpp                                     |*/
/*|                                                              |*/
/*|     Class istream member functions                           |*/
/*|          istream& ws( istream& )                             |*/
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

// extract whitespace characters

istream _FAR & _RTLENTRY _EXPFUNC32 ws(istream _FAR & is)
{
    long f = is.flags();
    is.setf(ios::skipws, ios::skipws);
    is.ipfx0();
    is.flags(f);
    return is;
}
