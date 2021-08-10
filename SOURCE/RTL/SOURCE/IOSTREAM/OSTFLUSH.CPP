/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostflush.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::flush()                           |*/
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

ostream _FAR & _RTLENTRY _EXPFUNC32 ostream::flush()
{
    if( bp->sync() == EOF )
        setstate(ios::badbit);
    return *this;
}
