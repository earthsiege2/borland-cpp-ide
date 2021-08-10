/*-----------------------------------------------------------------------*
 * filename - ltoupper.c
 *
 * function(s)
 *        _ltoupper - translates characters to upper-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */


#include <ctype.h>
#include <stdio.h>
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
    LPWIN32LOCALE locale = __locale;        // for future use.
    int result = 0; // Initialize it to zero since the LCMapString might only
                    // write one char into these four bytes.

    /* check for EOF */
    if( ch == EOF )
        return( EOF );

    if (locale->isCLocale)
        return _upper[ ch & 0x00ff];

    LCMapString(locale->handle, LCMAP_UPPERCASE, (LPCSTR) &ch, 1, (LPTSTR)&result, sizeof(result));
    return result;
}
