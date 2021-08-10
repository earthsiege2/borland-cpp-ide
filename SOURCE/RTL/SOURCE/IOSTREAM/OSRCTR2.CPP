/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     osrctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostrstream                                         |*/
/*|          ostrstream::ostrstream()                            |*/
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
#include <strstrea.h>

ostrstream::ostrstream() :
        strstreambase(),
        ostream(strstreambase::rdbuf())
{
}


