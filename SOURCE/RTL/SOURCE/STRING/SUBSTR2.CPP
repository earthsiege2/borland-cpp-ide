/*------------------------------------------------------------------------*/
/*                                                                        */
/*  SUBSTR2.CPP                                                           */
/*                                                                        */
/*  string string::substr( size_t pos, size_t n ) const;                  */
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

string string::substr( size_t pos, size_t n )
    const throw( xalloc, string::outofrange )
{
    assert_index(pos);
    return string( c_str(), pos, n );
}


