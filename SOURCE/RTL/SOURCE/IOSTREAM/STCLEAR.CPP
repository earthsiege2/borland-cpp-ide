/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stclear.cpp                                              |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          void ios::clear( int )                              |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

void ios::clear(int i)
{
    state = (i & 0xFF) | (state & hardfail);
    ispecial = (ispecial & ~0xFF) | state;
    ospecial = (ospecial & ~0xFF) | state;
}

