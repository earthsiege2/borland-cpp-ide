/*-----------------------------------------------------------------------*
 * filename - ltowlower.c
 *
 * function(s)
 *        _ltowlower - translates wice-characters to lower-case according to the
 *                    current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#define _UNICODE
#include <stdio.h>
#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _ltowlower - translates wide-characters to lower-case

Usage           wchar_t _ltowlower(wchar_t c);

Prototype in    _ltowlower is a function that converts a wide-character c
                to its lower-case value according to the current locale

Return value    returns the converted value of c, on success, and
                nothing on failure.

*---------------------------------------------------------------------*/

wchar_t _RTLENTRYF _EXPFUNC _ltowlower( wchar_t ch )
{
    LPWIN32LOCALE locale = __locale;
    wchar_t result;

    /* check for EOF */
    if( ch == WEOF )
        return( WEOF );

    if (locale->isCLocale)
        return _lower[ ch & 0x00ff];

    LCMapString(locale->handle, LCMAP_LOWERCASE, (LPCSTR) &ch, 1, (LPTSTR)&result, sizeof(result));
    return result;
}

