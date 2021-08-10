/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stdec.cpp                                                |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios& dec(ios&)                                      |*/
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

ios _FAR & _RTLENTRY _EXPFUNC dec(ios _FAR & s)
{
    s.setf(ios::dec, ios::basefield);
    return s;
}


