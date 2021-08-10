/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FNDFRSTN.CPP                                                          */
/*                                                                        */
/*  size_t string::find_first_not_of( const string& s, size_t pos ) const;*/
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

size_t string::find_first_not_of( const string _FAR &s, size_t pos ) const
    throw()
{
    if( pos >= length() )
        return NPOS;
    size_t res = strspn( p->array+pos, s.c_str() );
    if( res == length() )
        return NPOS;
    else
        return res+pos;
}


