/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsbsbuf.cpp                                              |*/
/*|                                                              |*/
/*|     Class filebuf                                            |*/
/*|          streambuf* filebuf::setbuf( char *, int )           |*/
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

streambuf* filebuf::setbuf(char* b, int len)
{
    if( opened  &&  base() )
        return 0;       // already open with a buffer -- no change
    
    int pb;         // putback area size
    if( b  &&  len > 0 )    // use b as the new buffer
        pb = (len > 8) ? 4 : 1; // guard against tiny buffers
    else
        {         // unbuffered
        len = pb = 0;
        b = 0;
        }
    setb(b, b+len, 0);      // will delete old buffer if needed
    setp(b+pb, b+pb);
    setg(b, b+pb, b+pb);
    return this;
}


