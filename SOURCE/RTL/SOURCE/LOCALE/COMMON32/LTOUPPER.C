/*-----------------------------------------------------------------------*
 * filename - ltoupper.c
 *
 * function(s)
 *        _ltoupper - translates characters to upper-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _ltoupper - translates characters to upper-case

Usage           int _ltoupper(int c);

Prototype in    _ltoupper is a function that converts an integer c (in the range
                EOF to 255) to its upper-case value according to the
                current locale

Return value    returns the converted value of c, on success, and
                nothing on failure.

*---------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _ltoupper( int ch )

{
	/* check for EOF */
	if( ch == -1 )
		return( -1 );

	return( _pLocale->pToUpper[ ( ch & 0x00ff ) ] );
}
