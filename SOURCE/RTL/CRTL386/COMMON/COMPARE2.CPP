/*------------------------------------------------------------------------*/
/*                                                                        */
/*  COMPARE2.CPP                                                          */
/*                                                                        */
/*  int string::compare( const string& s, size_t n ) const;               */
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

int string::compare( const string _FAR &s, size_t orig, size_t n ) const throw()
{
    size_t loc = min(orig,s.length());
    size_t len = min(s.length()-loc,n);
    if( get_case_sensitive_flag() )
        return strncmp( c_str(), s.c_str()+loc, len );
    else
        return strnicmp( c_str(), s.c_str()+loc, len );
}


