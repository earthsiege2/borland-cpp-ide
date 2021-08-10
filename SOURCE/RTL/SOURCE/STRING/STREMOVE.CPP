/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REMOVE.CPP                                                            */
/*                                                                        */
/*  string& string::remove( size_t pos, size_t n );                       */
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


string _FAR &string::remove( size_t pos, size_t n )
    throw( xalloc, string::outofrange )
{
    if( pos > length() )
        throw outofrange();
    cow();
    p->splice( pos, min(n,length()-pos), 0, 0 );
    return *this;
}


