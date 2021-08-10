/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stboflow.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::overflow( int )                      |*/
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

// streambuf can't do anything about overflow -- no place to put chars

int streambuf::overflow(int)
{
    return EOF;
}


