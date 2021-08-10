/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     sdbctr.cpp                                               |*/
/*|                                                              |*/
/*|     Class stdiobuf                                           |*/
/*|          stdiobuf::stdiobuf( FILE* )                         |*/
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
#include <filesys.h>
#include <stdiostr.h>


stdiobuf::stdiobuf(FILE* f)
{
    sio = f;
    char  *p = new char [B_size];
    if( p )
        {
        setb(p, p+B_size, 1); // ~streambuf() will delete it
        setp(p+4, p+4);
        setg(p, p+4, p+4);
        }
}


