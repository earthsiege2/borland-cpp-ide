/*-----------------------------------------------------------------------*
 * filename - mbscspn.c
 *
 * function(s)
 *        _mbscspn - Return the number of characters for the initial
 *                   segment not containing any subset of a given set
 *                   of characters.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbscspn - Return the number of characters for the initial
                           segment not containing any subset of a given
                           set of characters.

Usage           size_t _mbscspn(const unsigned char *str1,
                                const unsigned char *str2);

Prototype in    mbstring.h

Description     _mbscspn scans str1,and counts the number of characters
                for the initial segment of str1 not containig any subset
                of str2.

                If the second byte of 2-bytes character is null,
                that character is regarded as null.  

Return value    _mbscspn searchs str2 until any one of the characters
                contained in str1 is found. The number of characters which
                were read in str2 is is the return value.The string
                termination character is not counted.Neither string is
                altered during the search.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

size_t _RTLENTRY _EXPFUNC _mbscspn(const unsigned char *s1, const unsigned char *s2)
{
    const unsigned char *p, *q;

    for (p = s1; *p; p++)
    {
        for (q = s2; *q; q++)
        {
            if (_ismbblead(*q))
            {
                if (*p == *q && p[1] == q[1])
                    break;
                q++;
                if (*q == '\0')
                    break;
            }
            else
            {
                if (*p == *q)
                    break;
            }
        }
        if (*q) break;
        if (_ismbblead(*p))
        {
            p++;
            if (*p == '\0')
                break;
        }
    }
    return (size_t)(p - s1);
}
