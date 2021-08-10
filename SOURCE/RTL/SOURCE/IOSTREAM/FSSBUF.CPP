/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fssbuf.cpp                                               |*/
/*|                                                              |*/
/*|     Class fstreambase                                        |*/
/*|          void fstreambase::setbuf( char *, int )             |*/
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

void fstreambase::setbuf(char* b, int len)
{
    if( buf.setbuf(b, len) )
        clear(ios::goodbit);
    else
        setstate(ios::failbit);
}


