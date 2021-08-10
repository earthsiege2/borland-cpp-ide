/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbdsgtn.cpp                                             |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          int streambuf::do_sgetn( char *, int )              |*/
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
#include <iostream.h>

// called when sgetn finds not enough chars in the get area

int streambuf::do_sgetn(char* s, int n)
{
    int c, i;

    i = in_avail();
    if( i > 0 )
        {
// Note that check is never true, sgetn() does check first		
//		if (i > n)
//			i = n;
		memcpy(s, gptr_, i);
        s += i;
        gbump(i);
        }
    while( i < n  &&  (c = sbumpc()) != EOF )
        {
        *s++ = c;
        ++i;
        }
    return i;
}


