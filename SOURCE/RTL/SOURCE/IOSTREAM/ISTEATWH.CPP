/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     isteatwh.cpp                                             |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          void istream::eatwhite()                            |*/
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

// extract consecutive whitespace

void istream::eatwhite()
{
    int c;
    while( (c = bp->sgetc()), isspace(c) )
        {
        bp->stossc();
        ++gcount_;
        }

    if( c == EOF )
        setstate(ios::eofbit);
}


