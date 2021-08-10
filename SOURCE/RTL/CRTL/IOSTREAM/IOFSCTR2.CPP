/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     iofsctr2.cpp                                             |*/
/*|                                                              |*/
/*|     Class fstream                                            |*/
/*|          fstream::fstream( const char *, int, int )          |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1992 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include "filesys.h"
#include <fstream.h>

fstream::fstream(const char* name, int omode, int prot) :
        fstreambase(name, omode, prot),
        iostream()
{
}

#if 0
fstream::fstream(const unsigned char* name, int omode, int prot) :
        fstreambase((const signed char *)name, omode, prot),
        iostream()
{
}
#endif
