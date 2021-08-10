/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stboflow.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::overflow( int )                      |*/
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

// streambuf can't do anything about overflow -- no place to put chars

int streambuf::overflow(int)
{
    return EOF;
}


