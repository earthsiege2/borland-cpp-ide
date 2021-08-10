/*-----------------------------------------------------------------------*
 * filename - strnicol.c
 *
 * function(s)
 *        _strnicol - compares two strings without case sensitivity
 *        _wcsnicol - compares two wide-character strings without case
 *                  sensitivity
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _strnicol, _wcsnicol - compares two strings

Usage           int _strnicol(const char *s1, const char *s2, size_t maxlen);
                int _wcsnicol(const wchar_t *s1, const wchar_t *s2, size_t maxlen);

Prototype in    string.h

Description     _strnicol compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

                At most "maxlen" characters will be compared. A "maxlen" of zero
                results in an equal compare, i.e. returns a zero.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC _tcsnicoll( const _TCHAR *s1, const _TCHAR *s2, int len )

{
    return( _tcsnicmp( s1, s2, len ) );
}

