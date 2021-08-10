/*-----------------------------------------------------------------------*
 * filename - strstr.c
 *
 * function(s)
 *        strstr - scans a string for the occurrence of a given string
 *        wcsstr - scans a wide-character string for the occurrence of a
 *			given wide-characterstring
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#pragma inline
#include <string.h>
#include <tchar.h>

/*-----------------------------------------------------------------------*

Name            strstr, wcsstr - scans a string for the occurrence of a given string

Usage           char *strstr(const char *str1, const char *str2);
		wchar_t *strstr(const wchar_t *str1, const wchar_t *str2);

Prototype in    string.h

Description     strstr and wcsstr scan str1 for the first occurrence of the substring
                  str2.

Return value     strstr and wcsstr return a pointer to the element in str1 that contains
                  str2 (points to str2 in str1). If str2 does not occur in str1,
                  strstr returns NULL.

*------------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tcsstr(const _TCHAR *str1, const _TCHAR *str2)
{
    int len1 = _tcslen(str1);
    int len2 = _tcslen(str2);
    int i,j,k;

    if (!len2)
        return (_TCHAR *)str1;    /* return str1 if str2 empty */
    if (!len1)
        return 0;               /* return NULL if str1 empty */
    i = 0;
    for(;;)
        {
        while(i < len1 && str1[i] != str2[0])
             ++i;
        if (i == len1)
            return 0;
        j = 0;
        k = i;
        while (i < len1 && j < len2 && str1[i] == str2[j])
            {
            ++i;
            ++j;
            }
        if (j == len2)
            return (_TCHAR *)str1+k;
        if (i == len1)
            return 0;
        i = k+1;
        }
}

