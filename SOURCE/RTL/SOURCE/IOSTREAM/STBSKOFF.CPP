/*[]-------------------------------------------------------------------[]*/
/*|                                                                     |*/
/*|     stbskoff.cpp                                                    |*/
/*|                                                                     |*/
/*|     Class streambuf                                                 |*/
/*|      streampos streambuf::seekoff( streamoff, ios::seek_dir, int )  |*/
/*|                                                                     |*/
/*[]-------------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

streampos streambuf::seekoff(streamoff, ios::seek_dir, int)
{
    return EOF;
}
