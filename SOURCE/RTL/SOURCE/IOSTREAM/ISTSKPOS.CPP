/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istskpos.cpp                                  |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::seekg( streampos )                |*/
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

// set/read the get pointer's position

istream _FAR & istream::seekg(streampos pos)
{
    if( bad()  ||  bp->seekpos(pos, ios::in) == EOF )
        setstate(ios::failbit);
    return *this;
}


