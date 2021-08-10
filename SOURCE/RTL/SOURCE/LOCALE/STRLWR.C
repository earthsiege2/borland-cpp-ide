/*-----------------------------------------------------------------------*
 * filename - strlwr.c
 *
 * function(s)
 *        strlwr - converts an ASCII string to lower-case according to the
 *                 "C" locale
 *        _wcslwr - converts a wide-character string to lower-case according
 *			to the "C" locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6.2.1 $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#include <string.h>
#include <ctype.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strlwr, _wcslwr - converts a string to lower-case

Usage           char *strlwr(char *str);
                wchar_t *_wcslwr(wchar_t *str);

Prototype in    string.h

Description     strlwr converts upper-case letters in string str to lower-case.
                No other changes occur.

Return value    pointer to the converted string

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRYF _EXPFUNC _tcslwr(_TCHAR *s)
{
    _TCHAR *p = s;
    while ( (*p = (_TCHAR)_totlower(*p)) != _TEXT('\0'))
         p++;
    return s;
}
