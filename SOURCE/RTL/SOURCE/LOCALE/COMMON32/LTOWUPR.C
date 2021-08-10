/*-----------------------------------------------------------------------*
 * filename - ltowupper.c
 *
 * function(s)
 *        _ltowupper - translates wice-characters to upper-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $        */

#define _UNICODE
#include <stdio.h>
#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _ltowupper - translates wide-characters to upper-case

Usage           wchar_t _ltowupper(wchar_t c);

Prototype in    _ltowupper is a function that converts a wide-character c
                to its upper-case value according to the current locale

Return value    returns the converted value of c, on success, and
                nothing on failure.

*---------------------------------------------------------------------*/

wchar_t _RTLENTRYF _EXPFUNC _ltowupper( wchar_t ch )
{
    LPWIN32LOCALE locale = __locale;
    wchar_t result;

    /* check for EOF */
    if( ch == WEOF )
        return( WEOF );

    if (locale->isCLocale)
        return _upper[ ch & 0x00ff];

    LCMapString(locale->handle, LCMAP_UPPERCASE, (LPCSTR) &ch, 1, (LPTSTR)&result, sizeof(result));
    return result;
}
