/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ifsctr3.cpp                                              |*/
/*|                                                              |*/
/*|     Class ifstream                                           |*/
/*|          ifstream::ifstream( int )                           |*/
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
#include "filesys.h"
#include <fstream.h>

ifstream::ifstream(int f) :
        fstreambase(f),
        istream()
{
}


