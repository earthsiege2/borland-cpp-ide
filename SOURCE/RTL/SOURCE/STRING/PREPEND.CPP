/*------------------------------------------------------------------------*/
/*                                                                        */
/*  PREPEND.CPP                                                           */
/*                                                                        */
/*  string& string::prepend( const char *cp, size_t n );                  */
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


string _FAR & string::prepend( const char _FAR *cp, size_t orig, size_t n )
    throw( xalloc, string::lengtherror )
{
    if( cp != 0 )
        {
        cow();
        size_t slen = strlen(cp);
        size_t loc = min(orig,slen);
        size_t len = min(slen-loc,n);
        p->splice( 0, 0, cp+loc, len );
        }
    return *this;
}


