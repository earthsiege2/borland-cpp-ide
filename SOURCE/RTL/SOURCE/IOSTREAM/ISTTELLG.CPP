/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - isttellg.cpp                                  |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          streampos istream::tellg()                          |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

streampos istream::tellg()
{
    streampos p = EOF;
    if( bad()  ||  (p = bp->seekoff(0, ios::cur, ios::in)) == EOF )
        setstate(ios::failbit);
    return p;
}
