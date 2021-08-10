/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostmanip.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::operator<< ( ios& (*)(ios&) )     |*/
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

// manipulators
ostream _FAR & ostream::operator<< (ios _FAR & (*f)(ios _FAR &))
{
    (*f)(*((ios*)this));
    return *this;
}


