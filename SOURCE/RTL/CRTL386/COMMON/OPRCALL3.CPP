/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OPRCALL3.CPP                                                          */
/*                                                                        */
/*  TSubString string::operator()( const TRegexp& r, size_t start );      */
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



#include <regexp.h>
#include <cstring.h>
#include <string.h>
#include <checks.h>

TSubString string::operator()( const TRegexp _FAR &r, size_t start ) throw()
{
    size_t len;
    size_t begin = find( r, &len, start );
    return TSubString( this, begin, len );
}


