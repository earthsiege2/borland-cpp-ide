/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     osrctr1.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostrstream                                         |*/
/*|          ostrstream::ostrstream( char *, int, int )          |*/
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
#include <string.h>

ostrstream::ostrstream(char* str, int len, int omode) :
        strstreambase(str, len, str),
        ostream(strstreambase::rdbuf())
{
    if( omode & (ios::ate | ios::app) )
    strstreambase::rdbuf()->seekoff(strlen(str), ios::beg, ios::out);
}

ostrstream::ostrstream(signed char* str, int len, int omode) :
        strstreambase((char *)str, len, (char *)str),
        ostream(strstreambase::rdbuf())
{
    if( omode & (ios::ate | ios::app) )
    strstreambase::rdbuf()->seekoff(strlen((char *)str), ios::beg, ios::out);
}

ostrstream::ostrstream(unsigned char* str, int len, int omode) :
        strstreambase((char *)str, len, (char *)str),
        ostream(strstreambase::rdbuf())
{
    if( omode & (ios::ate | ios::app) )
    strstreambase::rdbuf()->seekoff(strlen((char *)str), ios::beg, ios::out);
}

