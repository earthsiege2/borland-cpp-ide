/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stskip.cpp                                               |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          int ios::skip( i )                                  |*/
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

int ios::skip(int i)
{
    int x = (ispecial & skipping);
    if( i )
        {
        ispecial |= skipping;
        x_flags |= skipws;
        }
    else
        {
        ispecial &= ~skipping;
        x_flags &= ~skipws;
        }
    return x != 0;
}


