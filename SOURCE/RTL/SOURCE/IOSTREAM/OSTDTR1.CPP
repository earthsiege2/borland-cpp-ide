/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostdtr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream::~ostream()                                 |*/
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

ostream::~ostream()
{
    if (bp)
        flush();
}
