/*-----------------------------------------------------------------------*
 * filename - strdup.c
 *
 * function(s)
 *        strdup - copies a string into a newly-created location
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
#include <tchar.h>
#include <stddef.h>
#include <alloc.h>

/*---------------------------------------------------------------------*

Name            strdup, wcsdup - copies a string into a newly-created location

Usage           char *strdup(const char *str);
		wchar_t *_wcsdup(const wchar_t *str);

Prototype in    string.h

Description     strdup and wcsdup make a duplicate of string str, obtaining space
		with a call to malloc. The allocated space is (strlen (str) + 1)
                bytes long.

Return value    strdup and wcsdup return a pointer to the storage location
		containing the duplicated str, or returns NULL if space could
		not be allocated.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tcsdup(const _TCHAR *s)
{
    _TCHAR    *p;
    unsigned n;

    n = (_tcslen(s) + 1) * (sizeof(_TCHAR));
    if ((p = (_TCHAR *)malloc(n)) != NULL)
        memcpy(p, s, n);
    return (p);
}

