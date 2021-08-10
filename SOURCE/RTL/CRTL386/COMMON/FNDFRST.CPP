/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FNDFRST.CPP                                                           */
/*                                                                        */
/*  size_t string::find_first_of( const string& s, size_t pos ) const;    */
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

size_t string::find_first_of( const string _FAR &s, size_t pos ) const throw()
{
    if( !valid_element(pos) )
        return NPOS;
    char _FAR * f = strpbrk( p->array+pos, s.c_str() );
    return f ? f-p->array : NPOS;
}


