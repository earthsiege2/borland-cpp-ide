/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbsync.cpp                                              |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::sync()                               |*/
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

int streambuf::sync() 
{
     return (in_avail() == 0  &&  out_waiting() == 0) ? 0 : EOF;
}
