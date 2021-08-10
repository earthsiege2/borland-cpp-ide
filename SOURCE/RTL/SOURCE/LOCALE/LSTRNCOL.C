/*-----------------------------------------------------------------------*
 * filename - lstrcoln.c
 *
 * function(s)
 *        _lstrncoll - compares two strings
 *        _lwcsncoll - compares two wide-character strings
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>
#include <_locale.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _lstrncoll, _lwcsncoll - compares two strings within the
                maximum length specified

Usage           int _lstrncoll(const char *s1, const char *s2, const int );
                int _lwcsncoll(const wchar_t *s1, const wchar_t *s2, const int );

Prototype in    string.h

Description     _lstrncoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ltcsncoll( const _TCHAR *s1, const _TCHAR *s2, const int len )
{
    LPWIN32LOCALE locale = __locale;
    int len1 = len;
    int len2 = len;

    if (locale->isCLocale)
        return _tcsncmp(s1, s2, len);

    if ((unsigned)len > _tcslen(s1))
        len1 = _tcslen(s1);
    if ((unsigned)len > _tcslen(s2))
        len2 = _tcslen(s2);

    return CompareString(locale->handle, 0, s1, len1, s2, len2) - 2;
}
