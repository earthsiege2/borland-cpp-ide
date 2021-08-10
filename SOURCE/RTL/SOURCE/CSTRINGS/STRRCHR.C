/*-----------------------------------------------------------------------*
 * filename - strrchr.c
 *
 * function(s)
 *        strrchr, wcsrchr - scans an ASCII/wide-character string for the
 *		last occurrence of a given ASCII/wide-character
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#pragma inline

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strrchr, wcsrchr - scans a string for the last occurrence of a
                    given character

Usage           char *strrchr(const char *str, int c);
		wchar_t *wcsrchr(const wchar_t *str, wchar_t c);

Prototype in    string.h

Description     strrchr and wcsrchr scan an ASCII/wide-character string in the
		reverse direction, looking for a specific ASCII/wide-character.
		strrchr and wcsrchr find the last occurrence of the ASCII/wide-
		character ch in the string str. The null-terminator is considered
                to be part of the string.

Return value    strrchr and wcsrchr return a pointer to the last occurrence of the
                character ch. If ch does not occur in str, strrchr returns
                NULL.

*---------------------------------------------------------------------*/

#ifdef strrchr
#  undef strrchr
#  define INTRINSIC
#endif

#ifndef _UNICODE
_TCHAR * _RTLENTRY _EXPFUNC _tcsrchr( const _TCHAR *p, int c )
#else
_TCHAR * _RTLENTRY _EXPFUNC _tcsrchr( const _TCHAR *p, _TCHAR c )
#endif
{

#ifdef INTRINSIC
    return __strrchr__(p, c);
#else
    _TCHAR *q;

    for (q = (_TCHAR *)(p + _tcslen(p)); *q != (_TCHAR)c; q--)
        if (q == p)
            return (NULL);
    return (q);
#endif

}
