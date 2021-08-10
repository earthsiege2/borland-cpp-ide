/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostflush.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::flush()                           |*/
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

ostream _FAR & _RTLENTRY _EXPFUNC32 ostream::flush()
{
    if( bp->sync() == EOF )
        setstate(ios::badbit);
    return *this;
}
