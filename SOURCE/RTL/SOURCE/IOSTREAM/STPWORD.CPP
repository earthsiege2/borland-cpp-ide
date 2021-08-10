/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stpword.cpp                                              |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          void*& ios::pword( int )                            |*/
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

// return user word as a void pointer

void _FAR * _FAR & ios::pword(int i)
{
    static void* p = 0;     // for error return
    if( i < 1  ||  usercount < i )
        return p;       // no such entry
    if( i > nwords )
        usersize(i);
    return (i > nwords) ? p : userwords[i-1].pword;
}
