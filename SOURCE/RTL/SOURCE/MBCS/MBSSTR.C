/*-----------------------------------------------------------------------*
 * filename - mbsstr.c
 *
 * function(s)
 *        _mbsstr - Scans a string for the occurrence of a given substrings.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <string.h>
#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsstr - Scans a string for the occurrence of
                          a given substrings.

Usage           unsigned char *_mbsstr(const unsigned char *str1,
                                       const unsigned char *str2);

Prototype in    mbstring.h

Description     _mbsstr scans str1 for the first occurrence of
                the substring str2.

Return value    _mbsstr returns a pointer to the element in str1 where
                str2 begins(points to str2 in str1).
                If str2 does not occur in str1, _mbsstr returns null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsstr(const unsigned char *s1, const unsigned char *s2)
{
    size_t n1, n2;
    const unsigned char *e;

    n2 = strlen((const char *)s2);
    if (n2 <= 0)
        return (unsigned char *)s1;
    n1 = strlen((const char *)s1);
    if (n1 == 0 || n2 > n1)
        return NULL;

    for (e = s1 + n1 - n2; s1 <= e; s1++)
    {
        const unsigned char *p = s1;
        const unsigned char *q = s2;
        while (*p && *p == *q)
            p++, q++;
        if (*q == '\0')
            return (unsigned char *)s1;
        if (_ismbblead(*s1) && s1[1])
            s1++;
    }
    return NULL;
}
