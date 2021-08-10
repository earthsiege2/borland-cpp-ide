/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ifsctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class ifstream                                           |*/
/*|          ifstream::ifstream( const char *, int, int )        |*/
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

ifstream::ifstream(const char* name, int omode, int prot) :
        fstreambase(name, omode | ios::in, prot),
        istream()
{
}


