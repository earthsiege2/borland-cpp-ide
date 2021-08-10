/*-----------------------------------------------------------------------*
 * filename - strpbrk.c
 *
 * function(s)
 *        strpbrk - scans a string for the first occurrence of
 *                  any character a given set
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline

#include <string.h>

/*---------------------------------------------------------------------*

Name            strpbrk - scans a string for the first occurrence of
                          any character a given set

Usage           char *strpbrk(const char *str1, const char *str2);

Prototype in    string.h

Description     strpbrk scans a string, str1, for the first occurrence of any
                character appearing in str2.

Return value    strpbrk returns a pointer to the first occurrence of any of
                the characters in str2; if none of the str2 characters occurs
                in str1, it returns NULL.

*---------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC strpbrk(const char *s1, const char *s2)
{
     register const char *srchs2;

     while (*s1)
     {
             for (srchs2 = s2; *srchs2; srchs2++)
                     if (*s1 == *srchs2) return((char *)s1);
             s1++;
     }
     return (0);
}
