/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stlock.cpp                                               |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios& lock(ios&)                                     |*/
/*|          ios& unlock(ios&)                                   |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

ios _FAR & _RTLENTRY _EXPFUNC lock(ios _FAR & s)
{
    s.rdbuf()->lock();
    return s;
}

ios & _RTLENTRY _EXPFUNC unlock(ios _FAR & s)
{
    s.rdbuf()->unlock();
    return s;
}
