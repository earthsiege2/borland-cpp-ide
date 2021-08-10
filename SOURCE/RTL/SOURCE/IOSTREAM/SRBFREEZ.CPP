/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbfreez.cpp                                             |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          void strstreambuf::freeze( int )                    |*/
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

void strstreambuf::freeze( int n )
{
    if( ssbflags & dynamic )
        {
        if( n )
            ssbflags |= frozen;
        else
            ssbflags &= ~frozen;
        }
}


