/*------------------------------------------------------------------------*/
/*                                                                        */
/*  APPEND1.CPP                                                           */
/*                                                                        */
/*  string& string::append( const string& s, size_t n );                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

/* $Copyright: 1992$ */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif


#include <string.h>
#include <cstring.h>


string _FAR & string::append( const string _FAR &s, size_t orig, size_t n )
    throw( xalloc, string::lengtherror )
{
    cow();
    size_t loc = min(orig,s.length());
    size_t len = min(s.length()-loc,n);
    p->splice( p->nchars, 0, s.c_str()+loc, len );
    return *this;
}


