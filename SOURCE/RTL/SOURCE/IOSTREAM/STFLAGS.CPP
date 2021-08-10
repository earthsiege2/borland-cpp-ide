/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stflags.cpp                                              |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          long ios::flags( long )                             |*/
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


