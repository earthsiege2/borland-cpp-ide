/*-----------------------------------------------------------------------*
 * filename - stricoll.c
 *
 * function(s)
 *        _stricoll - compares two strings without case sensitivity
 *        _wcsicoll - compares two wide-character strings without case
 *                  sensitivity
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _stricoll, _wcsicoll - compares two strings without case
                                     sensitivity

Usage           int _stricoll(const char *s1, const char *s2);
                int _wcsicoll(const wchar_t *s1, const wchar_t *s2);

Prototype in    string.h

Description     _stricoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC _tcsicoll( const _TCHAR *s1, const _TCHAR *s2 )

{
    return( _tcsicmp( s1, s2 ) );
}

