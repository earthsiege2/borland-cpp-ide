/*-----------------------------------------------------------------------*
 * filename - ltoupper.c
 *
 * function(s)
 *        _ltoupper - translates characters to upper-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */


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
    int result;

    /* check for EOF */
    if( ch == EOF )
        return( EOF );

    if (locale->isCLocale)
        return _upper[ ch & 0x00ff];

    LCMapString(locale->handle, LCMAP_UPPERCASE, (LPCSTR) &ch, 1, (LPTSTR)&result, sizeof(result));
    return result;
}
