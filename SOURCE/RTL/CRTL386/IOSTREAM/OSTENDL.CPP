/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostendl.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& endl( ostream& )                           |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

// insert newline and flush

ostream _FAR & _RTLENTRY _EXPFUNC endl(ostream _FAR & os)
{
    os << '\n';
    os.flush();
    return os;
}
