/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbdtr.cpp                                               |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          strstreambuf::~strstreambuf()                       |*/
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


#define expandable ((ssbflags&(dynamic|frozen))==dynamic)

strstreambuf::~strstreambuf()
{
    if( expandable )
        {
        if( freef )
            (*freef)((void*)base());
        else
            delete[] base();
        }
}


