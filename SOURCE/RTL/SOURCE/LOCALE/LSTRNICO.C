/*-----------------------------------------------------------------------*
 * filename - lstrnico.c
 *
 * function(s)
 *        _lstrnicoll - compares two strings
 *        _lwcsnicoll - compares two wide-character strings
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <ntbc.h>
#include <_locale.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _lstrnicoll, _lwcsnicoll - compares two strings within the
		maximum length specified (ignore case)

Usage           int _lstrnicoll(const char *s1, const char *s2, const int );
                int _lwcsnicoll(const wchar_t *s1, const wchar_t *s2, const int );

Prototype in    string.h

Description     _lstrnicoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ltcsnicoll( const _TCHAR *s1, const _TCHAR *s2, const int len )
{
    LPWIN32LOCALE locale = __locale;
    int len1 = len;
    int len2 = len;
    if (locale->isCLocale)
        return _tcsnicmp(s1, s2, len);


    if ((unsigned)len > _tcslen(s1))
        len1 = _tcslen(s1);
    if ((unsigned)len > _tcslen(s2))
        len2 = _tcslen(s2);

    return CompareString(locale->handle, NORM_IGNORECASE, s1, len1, s2, len2) - 2;
}


