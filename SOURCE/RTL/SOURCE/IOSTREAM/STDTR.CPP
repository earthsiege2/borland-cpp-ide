/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stdtr.cpp                                                |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          ios::~ios()                                         |*/
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
#include "user.h"

ios::~ios()
{
    if( userwords )
        delete[] userwords;
    if (delbuf() == 2)
    {
        delete bp;
        bp = 0;
    }
}

// static members of ios

const long ios::basefield = ios::dec | ios::oct | ios::hex;
const long ios::adjustfield = ios::left | ios::right | ios::internal;
const long ios::floatfield = ios::scientific | ios::fixed;
long ios::nextbit = 16;
int ios::usercount = 0;
void _Cdecl (*ios::stdioflush)();

