/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stctr2.cpp                                               |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios::ios( streambuf * )                             |*/
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

ios::ios(streambuf* sb)
{
    userwords = 0;
    init(sb);
}

