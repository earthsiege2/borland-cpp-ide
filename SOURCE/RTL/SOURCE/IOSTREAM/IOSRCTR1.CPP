/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     iosrctr1.cpp                                             |*/
/*|                                                              |*/
/*|     Class strstream                                          |*/
/*|      strstream::strstream()                                  |*/
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
#include <strstrea.h>

strstream::strstream() :
        strstreambase(),
        iostream(strstreambase::rdbuf())
{
}


