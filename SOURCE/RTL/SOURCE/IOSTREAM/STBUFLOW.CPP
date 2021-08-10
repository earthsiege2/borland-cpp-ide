/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbuflow.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::underflow()                          |*/
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

// streambuf can't do anything about underflow -- no place to get chars

int streambuf::underflow()
{
    if( egptr_ > gptr_ )
        return (unsigned char) *gptr_;

    gptr_ = egptr_;
    return EOF;
}


