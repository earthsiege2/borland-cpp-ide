/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsclose.cpp                                              |*/
/*|                                                              |*/
/*|     Class fstreambase                                        |*/
/*|          void fstreambase::close()                           |*/
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

void fstreambase::close()
{
    if( buf.close() )
        clear(ios::goodbit);
    else
        setstate(ios::failbit);
}


