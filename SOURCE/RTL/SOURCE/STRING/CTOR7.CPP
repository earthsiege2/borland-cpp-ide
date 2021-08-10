/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR7.CPP                                                             */
/*                                                                        */
/*  TStringRef::TStringRef( const char __far *pstr, size_t n );           */
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

#if defined( __TINY__ ) || defined( __SMALL__ ) || defined( __MEDIUM__ )
// Special far TStringRef ctor for small & medium model

extern xalloc __xalloc;

TStringRef::TStringRef( const char __far* pstr, size_t n ) :
    TReference(1),
    flags(0)
{
    if( pstr == 0 )
        pstr = "";
    unsigned strl = _fstrlen(pstr);
    nchars = strl < n ? strl : n;
    capacity = round_capacity(nchars);
    array = (char far*)malloc( capacity + 1 );
    if( array == 0 )
        __xalloc.raise();
    _fmemcpy( array, pstr, nchars );
    array[nchars] = '\0';
}

#endif  // __TINY__ || __SMALL__ || __MEDIUM__


