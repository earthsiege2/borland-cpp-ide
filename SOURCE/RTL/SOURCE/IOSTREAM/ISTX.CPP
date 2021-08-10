/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istx.cpp                                      |*/
/*|                                                              |*/
/*|     Obsolete class istream constructors                      |*/
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
#include <strstrea.h>
#include <fstream.h>


// Obsolete constructor, for streams 1.2 compatibility
#pragma warn -par
istream::istream(int sz, char* b, int sk)
{
    ios::init(new strstreambuf(b, 0, 0));
    skip(sk);
    delbuf(2);  // 2 is special value to indicate that the streambuf passed
                // to ios::init() needs to be deleted upon exit.  We don't
                // do this in the new (not obsolete) constructors since there
                // is a static instance of streambuf who's address is passed
                // into ios::init()

}
#pragma warn .par


// Obsolete constructor, for streams 1.2 compatibility
istream::istream(int fd, int sk, ostream* t)
{
    ios::init(new filebuf(fd));
    skip(sk);
    tie(t);
    delbuf(2);  // 2 is special value to indicate that the streambuf passed
                // to ios::init() needs to be deleted upon exit.  We don't
                // do this in the new (not obsolete) constructors since there
                // is a static instance of streambuf who's address is passed
                // into ios::init()

}
