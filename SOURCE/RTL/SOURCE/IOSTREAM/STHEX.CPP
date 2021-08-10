/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     sthex.cpp                                                |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios& hex(ios&)                                      |*/
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

ios _FAR & _RTLENTRY _EXPFUNC32 hex(ios _FAR & s)
{
    s.setf(ios::hex, ios::basefield);
    return s;
}


