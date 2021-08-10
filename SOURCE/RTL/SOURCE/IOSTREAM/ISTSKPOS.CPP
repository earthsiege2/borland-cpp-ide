/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istskpos.cpp                                  |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::seekg( streampos )                |*/
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

// set/read the get pointer's position

istream _FAR & istream::seekg(streampos pos)
{
    if( bad()  ||  bp->seekpos(pos, ios::in) == EOF )
        setstate(ios::failbit);
    return *this;
}


