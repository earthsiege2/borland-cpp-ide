/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsclose.cpp                                              |*/
/*|                                                              |*/
/*|     Class fstreambase                                        |*/
/*|          void fstreambase::close()                           |*/
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

void fstreambase::close()
{
    if( buf.close() )
        clear(ios::goodbit);
    else
        setstate(ios::failbit);
}


