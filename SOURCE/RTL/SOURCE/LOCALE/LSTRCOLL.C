/*-----------------------------------------------------------------------*
 * filename - lstrcoll.c
 *
 * function(s)
 *        _lstrcoll - compares two strings
 *        _lwcscoll - compares wide-character two strings
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>
#include <winbase.h>
#include <_locale.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _lstrcoll, _lwcscoll - compares two strings

Usage           int _lstrcoll(const char *s1, const char *s2);
                int _lwcscoll(const wchar_t *s1, const wchar_t *s2);

Prototype in    string.h

Description     _lstrcoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC _ltcscoll( const _TCHAR *s1, const _TCHAR *s2 )
{
    LPWIN32LOCALE locale = __locale;
    if (locale->isCLocale)
        return _tcscmp(s1, s2);

    return CompareString(locale->handle, 0, s1, -1, s2, -1) - 2;
}
