/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istdipfx.cpp                                             |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          int istream::ipfx( int )                            |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1992 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

// implementation of ipfx
// flush tied stream if needed, skip whitespace if needed

int istream::ipfx(int need)
{
    gcount_ = 0;

    if( ! good() )
        {
        setstate(ios::failbit); // per ANSI C++ IOStream doc rev 6
        return 0;               // if state is nonzero on entry set failbit
        }

    // flush tied stream if needed
    if ( tie()  &&  (! need  ||  need > bp->in_avail()) )
        tie()->flush();

    if( ! need  &&  (ispecial & skipping))
        {    
        eatwhite();
        if (!good())    // if eof then fail
            setstate(ios::failbit);
        }

    return good();
}


