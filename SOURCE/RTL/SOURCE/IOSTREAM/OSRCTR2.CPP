/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     osrctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostrstream                                         |*/
/*|          ostrstream::ostrstream()                            |*/
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
#include <strstrea.h>

ostrstream::ostrstream() :
        strstreambase(),
        ostream(strstreambase::rdbuf())
{
}


