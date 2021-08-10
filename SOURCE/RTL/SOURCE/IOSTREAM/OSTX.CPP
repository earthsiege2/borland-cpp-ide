/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostx.cpp                                                 |*/
/*|                                                              |*/
/*|     Obsolete class ostream constructors                      |*/
/*|          ostream::ostream(int fd)                            |*/
/*|          ostream::ostream(int sz, char* b)                   |*/
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

#include <strstrea.h>
#include <fstream.h>


// Obsolete constructor, for streams 1.2 compatibility
ostream::ostream(int fd)
{
    ios::init(new filebuf(fd));
    delbuf(2);  // 2 is special value to indicate that the streambuf passed
                // to ios::init() needs to be deleted upon exit.  We don't
                // do this in the new (not obsolete) constructors since there
                // is a static instance of streambuf who's address is passed
                // into ios::init()

}


// Obsolete constructor, for streams 1.2 compatibility
ostream::ostream(int sz, char* b)
{
    ios::init(new strstreambuf(b, sz, b));
    delbuf(2);  // 2 is special value to indicate that the streambuf passed
                // to ios::init() needs to be deleted upon exit.  We don't
                // do this in the new (not obsolete) constructors since there
                // is a static instance of streambuf who's address is passed
                // into ios::init()
}
