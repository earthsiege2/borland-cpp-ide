/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsctr1.cpp                                               |*/
/*|                                                              |*/
/*|     Class fstreambase                                        |*/
/*|          fstreambase::fstreambase()                          |*/
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
#include "filesys.h"
#include <fstream.h>

fstreambase::fstreambase()
        : buf()
{
    ios::init(&buf);
}


