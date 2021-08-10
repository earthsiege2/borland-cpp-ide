/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream::istream( streambuf * )                     |*/
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

istream::istream(streambuf* s)
{
    ios::init(s);
    gcount_ = 0;
}


