/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     iosrctr1.cpp                                             |*/
/*|                                                              |*/
/*|     Class strstream                                          |*/
/*|      strstream::strstream()                                  |*/
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
#include <strstrea.h>

strstream::strstream() :
        strstreambase(),
        iostream(strstreambase::rdbuf())
{
}


