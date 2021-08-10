/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR5.CPP                                                             */
/*                                                                        */
/*  string::string( const string& s, size_t n );                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992, 1993 by Borland International
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

string::string( const string _FAR &s, size_t orig, size_t n )
    throw( xalloc )
{
    if( orig != 0 || n < s.length() )
        {
        size_t loc = min(orig,s.length());
        size_t len = min(s.length()-loc,n);
        p = new TStringRef( s.c_str()+loc, len, 0, 0, 0 );
        }
    else
        {
        p = s.p;
        p->AddReference();
        }
}


