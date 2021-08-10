/*-----------------------------------------------------------------------*
 * MBYTE1.C
 *
 * single byte "multi-byte" locale only conversion functions
 *
 * function(s)
 *        mblen     - determines number of bytes in multibyte character
 *        mbtowc    - converts multibyte character to wide character
 *        wctomb    - converts wide character to multibyte character
 *        mbstowcs  - converts a multibyte string to a wide character string
 *        wcstombs  - converts a wide character string to a multibyte string
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stdlib.h>

#if ( sizeof( wchar_t ) == 1 )
#error *** size of wchar_t is incorrect ***
#endif

/*
	single byte "multi-byte" locale code set

	ASSUMPTION: multi-byte char size is sizeof( char )
*/


int _RTLENTRY _EXPFUNC mblen( const char *s, size_t n )
{

	if ( s == NULL )
		return( 0 );

	if ( *s == 0 )
		return( 0 );

	if ( n == 0 )
		return( -1 );

	return( sizeof( char ) );
}

/*
	single byte "multi-byte" locale code set

	ASSUMPTION: each char is zero extended into wchar_t
*/

int _RTLENTRY _EXPFUNC mbtowc( wchar_t *pwc, const char *s, size_t n )

{
	/* return "no state-dependent encodings" */
	if ( s == NULL )
		return( 0 );

	if ( n == 0 )
		return( -1 );
	
	if ( pwc != NULL )
		/* zero extend */
		*pwc = (wchar_t) (unsigned char) *s;

	if ( *s == 0 )
		return( 0 );

	return( sizeof( char ) );
}

/*
	single byte "multi-byte" locale code set

	ASSUMPTION: each wchar_t has zero in high byte
*/

int _RTLENTRY _EXPFUNC wctomb( char *s, wchar_t wc )

{
	/* return "no state-dependent encodings" */
	if ( s == NULL )
		return( 0 );

	/* is valid wide char value: must be zero extended */
	if ( ( wc & 0xff00 ) != 0 )
	 	return( -1 );
		
	/* take only lower byte value */
	*s = (char) wc;

	return( sizeof( char ) );

}

size_t _RTLENTRY _EXPFUNC mbstowcs( wchar_t _FAR *pwcs, const char _FAR *s, size_t n )
{
	int i;

	for ( i = 0; i < n && *s; i++ )
		/* zero extend */
		*pwcs++ = (wchar_t) (unsigned char) *s++;

	if ( i < n )
		*pwcs = 0;

	return( i );
		
}


size_t _RTLENTRY _EXPFUNC wcstombs(char _FAR *s, const wchar_t _FAR *pwcs, size_t n)
{

	int i;

	for ( i = 0; i < n && *pwcs; i++ )
	{
		/* is valid wide char value: must be zero extended */
		if ( ( *pwcs & 0xff00 ) != 0 )
	 		return( -1 );
		
		/* take only lower byte value */
		*s++ = (char) *pwcs++;
	}

	if ( i < n )
		*s = 0;

	return( i );
}
