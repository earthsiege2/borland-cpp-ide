/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR4.CPP                                                             */
/*                                                                        */
/*  string::string( const char *pstr, size_t n );                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1992, 1996 by Borland International
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

string::string( const char _FAR *pstr, size_t orig, size_t n )
    throw( xalloc, string::lengtherror )
{
    unsigned slen = strlen( pstr );
    size_t loc = min(orig,slen);
    size_t len = min(slen-loc,n);
    p = new TStringRef( pstr+loc, len, 0, 0, 0 );
}


