/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istpback.cpp                                  |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::putback(char c)                   |*/
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

// push back char into input

istream _FAR & istream::putback(char c)
{
    if( ! fail() )
        {
        if( bp->sputbackc(c) == EOF )
            setstate(ios::failbit);
        else
            clear(rdstate() & ~ios::eofbit);
        }
    return *this;
}


