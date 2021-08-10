/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istread.cpp                                   |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::read( char* , int )               |*/
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

istream _FAR & istream::read(char* p, int len)
{
    if( ipfx1() )
        {
        int c = 0;
        while( --len >= 0  &&  (c = bp->sgetc()) != EOF )
            {
            *p++ = c;
            ++gcount_;
            bp->stossc();
            }
        if( c == EOF )
            setstate((len >= 0) ? (ios::eofbit | ios::failbit) : ios::eofbit);
        }
    return *this;
}


