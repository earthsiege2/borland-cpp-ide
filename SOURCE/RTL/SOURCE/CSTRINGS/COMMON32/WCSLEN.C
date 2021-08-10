/*-----------------------------------------------------------------------*
 * filename - wcslen.c
 *
 * function(s)
 *        wcslen - returns the length of an array of wchar_t's
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1995, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>

/*---------------------------------------------------------------------*

Name            wcslen - returns the length of an array of wchar_t's

Usage           size_t wcslen(wchar_t *__s);

Prototype in    string.h

Description     wcslen calculates the length of the string by counting
                each element until it finds a 0 value.

Return value    returns the length of the string

*---------------------------------------------------------------------*/

size_t      _RTLENTRY  _EXPFUNC wcslen(const wchar_t *__s)
{
    wchar_t c;
    size_t len = 0;

    do
    {
        c = __s[len++];
    } while (c != 0);
    return len;
}
