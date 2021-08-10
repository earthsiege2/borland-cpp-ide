/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     iofsctr4.cpp                                             |*/
/*|                                                              |*/
/*|     Class fstream                                            |*/
/*|          fstream::fstream( int, char *, int )                |*/
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
#include "filesys.h"
#include <fstream.h>

fstream::fstream(int f, char* b, int len) :
        fstreambase(f, b, len),
        iostream()
{
}


