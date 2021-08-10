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
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

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

    while ( (*p = (_TCHAR)toupper(*p)) != _TEXT('\0') )
         p++;

    return str;
}

