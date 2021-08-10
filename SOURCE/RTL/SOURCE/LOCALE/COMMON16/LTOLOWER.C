/*-----------------------------------------------------------------------*
 * filename - ltolower.c
 *
 * function(s)
 *        _ltolower - translates characters to lower-case according to
 *                    the current locale.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <ctype.h>
#include <RtlData.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _ltolower - translates characters to lower-case

Usage           int _ltolower(int c);

Prototype in    ctype.h

Description     _ltolower is a function that converts an integer c (in the range
                EOF to 255) to its lower-case value (if it was upper-case): all
                others are left unchanged.

Return value    returns the converted value of c, on success, and nothing
                on failure.

*---------------------------------------------------------------------*/
#if defined(__FARFUNCS__)
#include <_farfunc.h>
#endif

int _CType _FARFUNC _ltolower( int ch )

{
	_QRTLDataBlock;


	/* check for EOF */
	if( ch == -1 )
		return( -1 );

	return( _QRTLInstanceData(_pLocale)->pToLower[ ( ch & 0x00ff ) ] );
}

