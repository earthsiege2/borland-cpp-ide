/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostmflush.cpp                                            |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& flush( ostream& )                          |*/
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

// flush the ostream
ostream _FAR & _RTLENTRY _EXPFUNC flush(ostream _FAR & os)
{
    os.flush();
    return os;
}
