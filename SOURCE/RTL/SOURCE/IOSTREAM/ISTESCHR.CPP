/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     isteschr.cpp                                             |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::operator>> ( signed char& )       |*/
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

istream _FAR & istream::operator>> (signed char _FAR & c)
{
    if( ipfx0() )
        c = bp->in_avail() ? bp->sbumpc() : do_get();
    return *this;
}


