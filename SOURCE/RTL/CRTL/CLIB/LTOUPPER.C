/*-----------------------------------------------------------------------*
 * filename - ltoupper.c
 *
 * function(s)
 *        _ltoupper - translates characters to lower-case according to
 *                    the current locale.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#include <ctype.h>
#include <RtlData.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _ltoupper - translates characters to lower-case

Usage           int _ltoupper(int c);

Prototype in    ctype.h

Description     _ltoupper is a function that converts an integer c (in the range
                EOF to 255) to its upper-case value (if it was upper-case): all
                others are left unchanged.

Return value    returns the converted value of c, on success, and nothing
                on failure.

*---------------------------------------------------------------------*/
#if defined(__FARFUNCS__)
#include <_farfunc.h>
#endif

int _CType _FARFUNC _ltoupper( int ch )

{
	_QRTLDataBlock;


	/* check for EOF */
	if( ch == -1 )
		return( -1 );

	return( _QRTLInstanceData(_pLocale)->pToUpper[ ( ch & 0x00ff ) ] );
}
