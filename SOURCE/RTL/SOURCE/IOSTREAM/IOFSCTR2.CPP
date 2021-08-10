/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     iofsctr2.cpp                                             |*/
/*|                                                              |*/
/*|     Class fstream                                            |*/
/*|          fstream::fstream( const char *, int, int )          |*/
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

fstream::fstream(const char* name, int omode, int prot) :
        fstreambase(name, omode, prot),
        iostream()
{
}


