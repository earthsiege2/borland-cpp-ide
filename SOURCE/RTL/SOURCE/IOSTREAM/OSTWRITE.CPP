/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostwrite.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::write( const signed char *, int ) |*/
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

ostream _FAR & ostream::write(const char* s, int n)
{
    if( ! fail() )
        {
        if( bp->sputn((const char*)s, n) != n )
            setstate(badbit);
        }
    return *this;
}
