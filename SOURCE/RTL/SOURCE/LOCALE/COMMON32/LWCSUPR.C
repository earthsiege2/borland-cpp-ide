/*-----------------------------------------------------------------------*
 * filename - lwcsupr.c
 *
 * function(s)
 *        _lwcsupr - converts lower-case letters in a wide-character string to
 *                   upper-case according to the current locale
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
#include <string.h>
#include <ctype.h>
#include <_locale.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _lwcsupr - converts lower-case letters in a wide-character
			    string to upper-case

Usage           wchar_t *_lwcsupr(wchar_t *str);

Prototype in    string.h

Description     _lwcsupr converts lower-case letters in a wide-character string
		         str to upper-case.  No other changes occur.

Return value    pointer to str

*---------------------------------------------------------------------*/

wchar_t * _RTLENTRYF _EXPFUNC _lwcsupr(wchar_t *str)
{
    wchar_t *p = (wchar_t *) str;

    while ( (*p = (wchar_t) _ltowupper( *p ) ) != L'\0' )
         p++;

    return str;
}


