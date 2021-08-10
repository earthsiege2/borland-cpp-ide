/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     isrctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class istrstream                                          |*/
/*|          istrstream::istrstream( char * )                    |*/
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

