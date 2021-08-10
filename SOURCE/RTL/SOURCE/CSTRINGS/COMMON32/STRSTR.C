/*-----------------------------------------------------------------------*
 * filename - strstr.c
 *
 * function(s)
 *        strstr - scans a string for the occurrence of a given string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline
#include <string.h>

/*-----------------------------------------------------------------------*

Name            strstr - scans a string for the occurrence of a given string

Usage           char *strstr(const char *str1, const char *str2);

Prototype in    string.h

Description     strstr scans str1 for the first occurrence of the substring
                  str2.

Return value     strstr returns a pointer to the element in str1 that contains
                  str2 (points to str2 in str1). If str2 does not occur in str1,
                  strstr returns NULL.

*------------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC strstr(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i,j,k;

    if (!len2)
        return (char *)str1;    /* return str1 if str2 empty */
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
            return (char *)str1+k;
        if (i == len1)
            return 0;
        i = k+1;
        }
}

