/*-----------------------------------------------------------------------*
 * filename - ltolower.c
 *
 * function(s)
 *        _ltolower - translates characters to lower-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */


#include <ctype.h>
#include <stdio.h>
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
    LPWIN32LOCALE locale = __locale;        // for future use.
    int result = 0; // Initialize it to zero since the LCMapString might only
                    // write one char into these four bytes.

    /* check for EOF */
    if( ch == EOF )
        return( EOF );

    if (locale->isCLocale)
        return _lower[ ch & 0x00ff];

    LCMapString(locale->handle, LCMAP_LOWERCASE, (LPCSTR) &ch, 1, (LPTSTR)&result, sizeof(result));
    return result;
}
