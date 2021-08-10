/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbpbfl.cpp                                              |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::pbackfail( int )                     |*/
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

int streambuf::pbackfail(int)
{
    return EOF;
}


