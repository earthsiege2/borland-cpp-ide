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
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

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
