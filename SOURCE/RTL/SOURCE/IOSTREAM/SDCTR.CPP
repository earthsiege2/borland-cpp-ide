/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     sdctr.cpp                                                |*/
/*|                                                              |*/
/*|     Class stdiostream                                        |*/
/*|          stdiostream::stdiostream( FILE * )                  |*/
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

stdiostream::stdiostream(FILE _FAR * f) : buf(f)
{
    ios::init(&buf);
}


