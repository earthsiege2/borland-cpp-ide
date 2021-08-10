/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istdget.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          signed char istream::do_get()                       |*/
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

// get next char, not immediately available

signed char istream::do_get()
{
    int c = bp->sbumpc();
    if( c == EOF )
        setstate(ios::eofbit | ios::failbit);
    else
        ++gcount_;
    return c;
}


