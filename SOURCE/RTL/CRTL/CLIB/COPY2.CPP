/*------------------------------------------------------------------------*/
/*                                                                        */
/*  COPY2.CPP                                                             */
/*                                                                        */
/*  size_t string::copy( char *cb, size_t n, size_t pos );                */
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

size_t string::copy( char _FAR *cb, size_t n, size_t pos )
    throw( string::outofrange )
{
    if( n > length()-pos )
        n = length()-pos;
    memcpy( cb, c_str()+pos, n+1 );
    return n;
}
