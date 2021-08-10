/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR6.CPP                                                             */
/*                                                                        */
/*  string::string( const TSubString& ss );                               */
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

string::string( const TSubString _FAR &ss )
    throw( xalloc )
{
    p = new TStringRef( ss.s->c_str()+ss.start(),
                        ss.is_null()?0:ss.length(), 0, 0, 0 );
}


