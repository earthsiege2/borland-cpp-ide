/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fssbuf.cpp                                               |*/
/*|                                                              |*/
/*|     Class fstreambase                                        |*/
/*|          void fstreambase::setbuf( char *, int )             |*/
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

void fstreambase::setbuf(char* b, int len)
{
    if( buf.setbuf(b, len) )
        clear(ios::goodbit);
    else
        setstate(ios::failbit);
}


