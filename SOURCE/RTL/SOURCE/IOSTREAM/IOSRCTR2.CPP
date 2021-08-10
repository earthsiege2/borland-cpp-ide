/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     iosrctr2.cpp                                             |*/
/*|                                                              |*/
/*|     Class strstream                                          |*/
/*|          strstream::strstream( char *, int, int )            |*/
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

strstream::strstream(char* str, int size, int omode) :
        strstreambase(str, size, str),
        iostream(strstreambase::rdbuf())
{
    if( omode & (ios::ate | ios::app) )
        {
        strstreambase::rdbuf()->seekoff(strlen(str), ios::beg, ios::out);
		// Need to set egptr correctly (any other way?)
        strstreambase::rdbuf()->seekoff(strlen(str), ios::beg, ios::in);
		// Now reset gptr back
        strstreambase::rdbuf()->seekoff(0, ios::beg, ios::in);
        }
}


