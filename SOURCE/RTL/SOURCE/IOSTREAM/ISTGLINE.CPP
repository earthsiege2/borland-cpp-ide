/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istgline.cpp                                  |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::getline( signed char*, int, char )|*/
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

// extract characters into an array, reading and discarding delimiter d

istream _FAR & istream::getline(char* p, int len, char d)
{
    if( ipfx1() )
        {
        char* op = p;
        int c = 0;
        while( --len > 0  &&  (c = bp->sgetc()) != EOF )
            {
            ++gcount_;
            bp->stossc();
            if( c == (unsigned char)d )
                break;
            *p++ = c;
            }
        if( c == EOF )
            setstate((p == op) ? (ios::eofbit | ios::failbit) : ios::eofbit);
        }

    *p = 0; // always terminate with a null
    return *this;
}


