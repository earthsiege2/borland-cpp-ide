/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REPLACE.CPP                                                           */
/*                                                                        */
/*  string& string::replace( size_t pos,                                  */
/*                           size_t n1,                                   */
/*                           const string& s,                             */
/*                           size_t n2 );                                 */
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


string _FAR &string::replace( size_t pos,
                              size_t n1,
                              const string _FAR &s,
                              size_t orig,
                              size_t n2 )
    throw( xalloc, string::outofrange, string::lengtherror )
{
    if( pos > length() )
        throw outofrange();
    cow();
    size_t loc = min(orig,s.length());
    size_t len = min(s.length()-loc,n2);
    p->splice( pos, min(n1,length()-pos), s.c_str()+loc, len );
    return *this;
}


