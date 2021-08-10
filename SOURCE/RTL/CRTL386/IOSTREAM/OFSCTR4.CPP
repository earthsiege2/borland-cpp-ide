/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ofsctr4.cpp                                              |*/
/*|                                                              |*/
/*|     Class ofstream                                           |*/
/*|          ofstream::ofstream( int, char *, int )              |*/
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

ofstream::ofstream(int f, char* b, int len) :
        fstreambase(f, b, len),
        ostream()
{
}


