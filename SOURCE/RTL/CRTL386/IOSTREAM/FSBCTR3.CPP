/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsbctr3.cpp                                              |*/
/*|                                                              |*/
/*|     Class filebuf                                            |*/
/*|          filebuf::filebuf( int, char *, int )                |*/
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

// make a filebuf attached to an open fd -- assume fd is actually open
// use buf as the buffer area

filebuf::filebuf(int f, char* buf, int len)
{
    xfd = f;        // assumed to be valid
    opened = 1;     // unless we can find out otherwise
    mode = 0;       // unless we can find out otherwise
    last_seek = 0;
    setbuf(buf, len);
}


