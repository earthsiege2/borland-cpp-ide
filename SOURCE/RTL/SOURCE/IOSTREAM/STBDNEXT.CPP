/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbdnxtc.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::do_snextc()                          |*/
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

// called when snextc doesn't have an available character

int streambuf::do_snextc()
{
    return (underflow() == EOF) ? EOF : (unsigned char) *gptr_;
}


