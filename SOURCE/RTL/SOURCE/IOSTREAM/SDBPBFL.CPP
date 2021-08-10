/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     sdbpbfl.cpp                                              |*/
/*|                                                              |*/
/*|     Class stdiobuf                                           |*/
/*|          int stdiobuf::pbackfail( int )                      |*/
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
#include <filesys.h>
#include <stdiostr.h>

int stdiobuf::pbackfail(int c)
{
    return ungetc(c, sio);
}


