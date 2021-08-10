/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stclear.cpp                                              |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          void ios::clear( int )                              |*/
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

void ios::clear(int i)
{
    state = (i & 0xFF) | (state & hardfail);
    ispecial = (ispecial & ~0xFF) | state;
    ospecial = (ospecial & ~0xFF) | state;
}

