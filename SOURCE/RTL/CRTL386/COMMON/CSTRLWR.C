/*-----------------------------------------------------------------------*
 * filename - strlwr.c
 *
 * function(s)
 *        strlwr - converts a string to lower-case
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#ifndef __OS2__

#include <string.h>
#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            cstrlwr - converts a string to lower-case according to
								  the 'C' locale.

Usage           char *cstrlwr(char *str);

Prototype in    _string.h

Description     cstrlwr converts upper-case letters in string str to
			  		 lower-case. No other changes occur.

Return value    pointer to the converted string

*---------------------------------------------------------------------*/


char * _RTLENTRYF _EXPFUNC cstrlwr( char *s )
{
	unsigned char *p = (unsigned char *) s;

	while ( ( *p = (unsigned char) _lower[ *p ] ) != '\0' )
		p++;

	return( s );
}

#endif /* __OS2__ */

