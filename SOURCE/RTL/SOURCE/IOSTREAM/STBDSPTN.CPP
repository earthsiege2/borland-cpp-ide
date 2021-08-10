/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbdsptn.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::do_sputn( const char *, int )        |*/
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
#include <iostream.h>

// called by sputn when more chars are needed than are in the buffer

int streambuf::do_sputn(const char* s, int n)
{
    int i;

    i = (int)(epptr_ - pptr_);
	
    if( i > 0 )
        {
// Note that check is never true, sputn() does check first		
//		if (i > n)
//			i = n;
        memcpy(pptr_, s, i);
        s += i;
        pbump(i);
        }
    while( i < (unsigned) n  &&  sputc(*s++) != EOF )
        ++i;
    return i;
}


