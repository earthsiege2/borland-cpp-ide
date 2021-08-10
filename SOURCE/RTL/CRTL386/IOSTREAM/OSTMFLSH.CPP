/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostmflush.cpp                                            |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& flush( ostream& )                          |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
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
