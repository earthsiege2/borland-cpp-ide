/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ifsctr4.cpp                                              |*/
/*|                                                              |*/
/*|     Class ifstream                                           |*/
/*|          ifstream::ifstream( int, char *, int )              |*/
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

ifstream::ifstream(int f, char* b, int len) :
        fstreambase(f, b, len),
        istream()
{
}


