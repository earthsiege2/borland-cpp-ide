/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istechp.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::operator>> (char*)                |*/
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
#include <ctype.h>

istream _FAR & istream::operator>> (char* p)
{
    if( ipfx0() )
        {
        char* op = p;
        int c = 0;
        int len = width(0); // <=0 means no limit
        while( --len  &&  (c = bp->sgetc(), ! isspace(c))  &&  c != EOF )
            {
            *p++ = c;
            bp->stossc();
            }
        if( c == EOF )
            setstate((p == op) ? (ios::eofbit | ios::failbit) : ios::eofbit);
        }
    *p = 0; // always terminate with a null, even if nothing was read,
            // per AT&T ISTREAM(3C++), May 18, 1989, p. 3
    return *this;
}


