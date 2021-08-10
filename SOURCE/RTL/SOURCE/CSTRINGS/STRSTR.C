/*-----------------------------------------------------------------------*
 * filename - strstr.c
 *
 * function(s)
 *        strstr - scans a string for the occurrence of a given string
 *        wcsstr - scans a wide-character string for the occurrence of a
 *        given wide-characterstring
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.8.2.1 $        */

#include <string.h>
#include <tchar.h>

/*-----------------------------------------------------------------------*

Name            strstr, wcsstr - scans a string for the occurrence of a
                                 given string.

Usage           char *strstr(const char *str1, const char *str2);
        wchar_t *strstr(const wchar_t *str1, const wchar_t *str2);

Prototype in    string.h

Description     strstr and wcsstr scan str1 for the first occurrence of the
                substring str2.

Return value    strstr and wcsstr return a pointer to the element in str1
                that contains str2 (points to str2 in str1). If str2 does
                not occur in str1, strstr returns NULL.


*------------------------------------------------------------------------*/

/* This routine works better without any extra optimization at this point */
#pragma option push -Od -r

_TCHAR * _RTLENTRY _EXPFUNC _tcsstr(const _TCHAR *str1, const _TCHAR *str2)
{
    _TCHAR *c1, *c2, *s = (_TCHAR *)str1;

    if (!*str2)
        return (_TCHAR *)str1;    /* return str1 if str2 is empty */

    if (!*str1)
        return NULL;              /* return NULL if str1 is empty */

    while(*s)
    {
        if (*s == *str2)          /* wait for the first matching char */
        {
            c1 = s;
            c2 = (_TCHAR*)str2;
                                  /* continue matching chars in the sub-str */
            while (*c1 && *c2 && (!(*c2 - *c1)))
            {
                c2++;
                c1++;
            }
            if (!*c2)             /* if we've run off the end of str2 */
                return s;         /* then we've found the first substr match */
        }
        s++;                      /* otherwise try the next char */
    }

    return NULL;                  /* didn't find anything */
}
#pragma option pop
