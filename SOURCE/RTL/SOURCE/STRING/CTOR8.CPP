/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR8.CPP                                                             */
/*                                                                        */
/*  TStringRef::TStringRef( char c, size_t n );                           */
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


#include <string.h>
#include <cstring.h>

extern xalloc __xalloc;

TStringRef::TStringRef( char c, size_t n ) : TReference(1), flags(0)
{
    nchars = n;
    capacity = round_capacity( nchars );
    array = (char _FAR *)malloc( capacity + 1 );
    if( array == 0 )
        __xalloc.raise();
    memset( array, c, nchars );
    array[nchars] = '\0';
}


