/*-----------------------------------------------------------------------*
 * filename - strspn.c
 *
 * function(s)
 *        strspn, wcsspn - scans a string for the first segment that is a
 *                 subset of a given set of characters
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strspn - scans a string for the first segment that is a
                         subset of a given set of characters

Usage           size_t strspn(const char *str1, const char *str2);
                size_t wcsspn(const wchar_t *str1, const wchar_t *str2);

Prototype in    string.h

Description     strspn returns the length of the initial segment of string
                  str1 that consists entirely of characters from string str2.

Return value    strspn returns the length of the initial segment of string
                str1 that consists entirely of characters from string str2.


*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC _tcsspn(const _TCHAR *s1, const _TCHAR *s2)
{
    register const _TCHAR *srchs2;
    int         len;

    for (len = 0; *s1; s1++, len++)
    {
        for (srchs2 = s2; *srchs2; srchs2++)
            if (*s1 == *srchs2)
                break;
        if (*srchs2 == 0)
            break;
    }
    return (len);
}
