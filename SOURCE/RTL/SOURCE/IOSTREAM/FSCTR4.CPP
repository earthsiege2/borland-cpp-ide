/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsctr4.cpp                                               |*/
/*|                                                              |*/
/*|     Class fstreambase                                        |*/
/*|          fstreambase::fstreambase( int, char *, int )        |*/
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
#include "filesys.h"
#include <fstream.h>

fstreambase::fstreambase(int f, char* b, int len)
        : buf(f, b, len)
{
    ios::init(&buf);
}


