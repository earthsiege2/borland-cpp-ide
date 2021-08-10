/*------------------------------------------------------------------------*/
/*                                                                        */
/*  INSERT1.CPP                                                           */
/*                                                                        */
/*  string& string::insert( size_t pos, const string& s );                */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

string _FAR &string::insert( size_t pos, const string _FAR &s )
    throw( xalloc, string::outofrange, string::lengtherror )
{
    if( pos > length() )
        throw outofrange();
    cow();
    p->splice( pos, 0, s.c_str(), s.length() );
    return *this;
}


