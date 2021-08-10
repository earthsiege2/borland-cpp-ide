/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     isrctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class istrstream                                          |*/
/*|          istrstream::istrstream( char * )                    |*/
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

istrstream::istrstream(char* str) :
        strstreambase(str, 0, 0),
        istream(strstreambase::rdbuf())
{
}

istrstream::istrstream(signed char* str) :
        strstreambase((char *)str, 0, 0),
        istream(strstreambase::rdbuf())
{
}

istrstream::istrstream(unsigned char* str) :
        strstreambase((char *)str, 0, 0),
        istream(strstreambase::rdbuf())
{
}

