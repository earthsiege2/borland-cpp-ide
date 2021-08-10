/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FIND3.CPP                                                             */
/*                                                                        */
/*  size_t string::find( const TRegexp& r, size_t start ) const;          */
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

size_t string::find( const TRegexp _FAR &r, size_t start ) const throw()
{
    size_t len;
    return r.find( *this, &len, start ); // len not used
}


