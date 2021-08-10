/*------------------------------------------------------------------------*/
/*                                                                        */
/*  COPY1.CPP                                                             */
/*                                                                        */
/*  size_t string::copy( char *cb, size_t n );                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

size_t string::copy( char _FAR *cb, size_t n ) throw( string::outofrange )
{
    if( n > length() )
        n = length();
    memcpy( cb, c_str(), n );
    return n;
}
