/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream::ostream( streambuf * )                     |*/
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

ostream::ostream(streambuf* s)
{
    ios::init(s);
}


