/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostmflush.cpp                                            |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& flush( ostream& )                          |*/
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

// flush the ostream
ostream _FAR & _RTLENTRY flush(ostream _FAR & os)
{
    if (os.delbuf())
        os.flush();
    return os;
}
