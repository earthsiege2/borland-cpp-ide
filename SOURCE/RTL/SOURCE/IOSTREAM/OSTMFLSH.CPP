/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostmflush.cpp                                            |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& flush( ostream& )                          |*/
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

// flush the ostream
ostream _FAR & _RTLENTRY flush(ostream _FAR & os)
{
    if (os.delbuf())
        os.flush();
    return os;
}
