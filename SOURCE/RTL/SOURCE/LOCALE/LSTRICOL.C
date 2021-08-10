/*-----------------------------------------------------------------------*
 * filename - lstricol.c
 *
 * function(s)
 *        _lstricoll - compares two strings without case sensitivity
 *        _lwcsicoll - compares two strings without case sensitivity
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

Name            _lstricoll, _lwcsicoll - compares two strings (ignoring case)

Usage           int _lstricoll(const char *s1, const char *s2);
Usage           int _lwcsicoll(const wchar_t *s1, const wchar_t *s2);

Prototype in    string.h

Description     _lstricoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ltcsicoll( const _TCHAR *s1, const _TCHAR *s2 )
{
    LPWIN32LOCALE locale = __locale;

    if (locale->isCLocale)
        return _tcsicmp(s1, s2);

    return CompareString(locale->handle, NORM_IGNORECASE, s1, -1, s2, -1) - 2;
}

