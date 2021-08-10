/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stctr2.cpp                                               |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios::ios( streambuf * )                             |*/
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

ios::ios(streambuf* sb)
{
    userwords = 0;
    init(sb);
}

