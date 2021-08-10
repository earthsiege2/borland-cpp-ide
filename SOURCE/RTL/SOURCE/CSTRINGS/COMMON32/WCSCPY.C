/*-----------------------------------------------------------------------*
 * filename - wcscpy.c
 *
 * function(s)
 *        wcscpy - copies one wchar_t array into another
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <string.h>

/*---------------------------------------------------------------------*

Name            wcscpy - copies one wchar_t array into another

Usage           wchar_t *wcscpy(wchar_t *__dst, wchar_t *__src);

Prototype in    string.h

Description     wcscpy copies the source string into the dest string.

Return value    returns the address of the dest string.

*---------------------------------------------------------------------*/

wchar_t * _RTLENTRY  _EXPFUNC wcscpy(wchar_t *__dst, const wchar_t *__src)
{
    size_t len, j;

    len = wcslen (__src);

    for (j = 0;j< len;j++)
    {
        __dst[j] = __src[j];
    }
    __dst[len] = 0;
    return __dst;
}
