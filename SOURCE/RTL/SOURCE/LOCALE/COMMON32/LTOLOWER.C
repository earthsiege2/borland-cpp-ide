/*-----------------------------------------------------------------------*
 * filename - ltolower.c
 *
 * function(s)
 *        _ltolower - translates characters to lower-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _ltolower - translates characters to lower-case

Usage           int _ltolower(int c);

Prototype in    ctype.h

Description     _ltolower is a function that converts an integer c (in the range
                EOF to 255) to its lower-case value according to the
                current locale.

Return value    returns the converted value of c, on success, and nothing
                on failure.

*---------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _ltolower( int ch )

{
	/* check for EOF */
	if( ch == -1 )
		return( -1 );

	return( _pLocale->pToLower[ ( ch & 0x00ff ) ] );
}
