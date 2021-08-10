/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srbfreez.cpp                                             |*/
/*|                                                              |*/
/*|     Class strstreambuf                                       |*/
/*|          void strstreambuf::freeze( int )                    |*/
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


