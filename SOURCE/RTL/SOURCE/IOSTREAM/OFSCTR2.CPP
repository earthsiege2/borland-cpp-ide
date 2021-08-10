/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ofsctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class ofstream                                           |*/
/*|          ofstream::ofstream( const char *, int, int )        |*/
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

ofstream::ofstream(const char* name, int omode, int prot) :
        fstreambase(name, omode | ios::out, prot),
        ostream()
{
}


