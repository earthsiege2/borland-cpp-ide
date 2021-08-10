/*-----------------------------------------------------------------------*
 * filename - strupr.c
 *
 * function(s)
 *        strupr - converts lower-case letters in a string to upper-case
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

/*---------------------------------------------------------------------*

Name            cstrupr - converts s string to upper-case according to
							     the 'C' locale.



Usage           char *cstrupr(char *str);

Prototype in    _string.h

Description     cstrupr converts a string str to upper-case.
                No other changes occur.

Return value    pointer to str

*---------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC cstrupr( char *s )
{
	unsigned char *p = (unsigned char *) s;

	while ( (*p = (unsigned char) _upper[ *p ] ) != '\0' )
		p++;

    return( s );
}

#endif /* __OS2__ */
