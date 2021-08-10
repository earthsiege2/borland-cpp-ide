/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream::istream()                                  |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

istream::istream()
{
    gcount_ = 0;
}


