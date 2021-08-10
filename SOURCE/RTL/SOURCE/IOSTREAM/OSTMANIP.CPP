/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostmanip.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::operator<< ( ios& (*)(ios&) )     |*/
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

// manipulators
ostream _FAR & ostream::operator<< (ios _FAR & (*f)(ios _FAR &))
{
    (*f)(*((ios*)this));
    return *this;
}


