/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istgstr.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::get( signed char *, int, char )   |*/
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

// extract characters into an array, up to len chars or delimiter d
istream _FAR & istream::get(char* p, int len, char d)
{
    if( ipfx1() )
        {
        char* op = p;
        int c = 0;
        while( --len > 0  &&  (c = bp->sgetc()) != d  &&  c != EOF )
            {
            *p++ = c;
            ++gcount_;
            bp->stossc();
            }
        if( c == EOF )
            setstate((p == op) ? (ios::eofbit | ios::failbit) : ios::eofbit);
        }

    *p = 0;     // always terminate with a null
    return *this;
}
