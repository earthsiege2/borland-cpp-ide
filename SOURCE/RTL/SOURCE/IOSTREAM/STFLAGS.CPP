/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stflags.cpp                                              |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          long ios::flags( long )                             |*/
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


long ios::flags(long l)
{
    long x = x_flags;
    x_flags = l;
    if( l & ios::skipws )
        ispecial |= skipping;
    else
        ispecial &= ~skipping;
    return x;
}


