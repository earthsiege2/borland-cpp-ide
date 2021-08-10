/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stdec.cpp                                                |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios& dec(ios&)                                      |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

ios _FAR & _RTLENTRY _EXPFUNC32 dec(ios _FAR & s)
{
    s.setf(ios::dec, ios::basefield);
    return s;
}


