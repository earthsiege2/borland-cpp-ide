/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream::istream()                                  |*/
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

istream::istream()
{
    gcount_ = 0;
}


