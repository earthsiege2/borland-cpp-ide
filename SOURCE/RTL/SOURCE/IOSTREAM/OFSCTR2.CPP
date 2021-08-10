/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ofsctr2.cpp                                              |*/
/*|                                                              |*/
/*|     Class ofstream                                           |*/
/*|          ofstream::ofstream( const char *, int, int )        |*/
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

ofstream::ofstream(const char* name, int omode, int prot) :
        fstreambase(name, omode | ios::out, prot),
        ostream()
{
}


