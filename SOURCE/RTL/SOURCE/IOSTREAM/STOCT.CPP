/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stoct.cpp                                                |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios& oct(ios&)                                      |*/
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

ios _FAR & _RTLENTRY _EXPFUNC32 oct(ios _FAR & s)
{
    s.setf(ios::oct, ios::basefield);
    return s;
}


