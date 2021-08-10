/*-----------------------------------------------------------------------*
 * filename - strupr.c
 *
 * function(s)
 *        strupr - converts a string to upper-case according to the
 *                 "C" locale
 *        _wcsupr - converts a wide-character string to upper-case according
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

Name            strupr, _wcsupr - converts lower-case letters in a string
			to upper-case

Usage           char *strupr(char *str);
                wchar_t *strupr(wchar_t *str);

Prototype in    string.h

Description     strupr converts lower-case letters in string str to upper-case.
                No other changes occur.

Return value    pointer to str

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRYF _EXPFUNC _tcsupr(_TCHAR *str)
{
    _TCHAR *p = str;

    while ( (*p = (_TCHAR)_totupper(*p)) != _TEXT('\0') )
         p++;

    return str;
}

