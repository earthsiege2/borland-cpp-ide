/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR10.CPP                                                            */
/*                                                                        */
/*  string::string( signed char c );                                      */
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

#if (defined(__TINY__)|| defined(__SMALL__)|| defined(__MEDIUM__)) && !defined(__DLL__)
// Far string ctors make a near string from a far string

string::string( const char __far *cp )
    throw( xalloc, string::lengtherror )
{
    p = new TStringRef(cp);
}

#endif

