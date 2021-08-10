/*-----------------------------------------------------------------------*
 * filename - strcspn.c
 *
 * function(s)
 *        strcspn - scans a string for the first segment not containing
 *                  any subset of a given set of characters
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

/*---------------------------------------------------------------------*

Name            strcspn, wcscspn - scans a string for the first segment
                          not containing any subset of a given set of
                          characters

Usage           size_t strcspn(const char *str1, const char *str2);
		size_t wcscspn(const wchar_t *str1, const wchar_t *str2);

Prototype in    string.h

Description     strcspn and wcscspn return the length of the initial segment
                of string str1 that consists entirely of characters not
                from string str2.

Return value    strcspn and wcscspn return the length of the initial segment
                of string str1 that consists entirely of characters not
                from string str2.

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC _tcscspn(const _TCHAR *s1, const _TCHAR *s2)
{
    register const _TCHAR *srchs2;
    int len;

    for (len = 0; *s1; s1++, len++)
        for (srchs2 = s2; *srchs2; srchs2++)
            if (*s1 == *srchs2) goto bye;
bye:
    return (len);
}

