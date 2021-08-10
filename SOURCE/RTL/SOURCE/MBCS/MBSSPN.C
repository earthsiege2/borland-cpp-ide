/*-----------------------------------------------------------------------*
 * filename - mbsspn.c
 *
 * function(s)
 *        _mbsspn - Scans a string for the first segment that is a subset
 *                  of a given set of characters.
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

Name            _mbsspn - Scans a string for the first segment that is
                          a subset of a given set of characters.                         

Usage           size_t _mbsspn(const unsigned char *str1,
                               const unsigned char *str2);

Prototype in    mbstring.h

Description     _mbsspn finds the initial segment of string str1
                that consists entirely of characters from str2.

                The second byte of 2-bytes character is null character,
                this character is regarded as null character.

Return value    _mbsspn returns the length of the initial segment of
                str1 that consists entirely of characters from str2.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

size_t _RTLENTRY _EXPFUNC _mbsspn(const unsigned char *s1, const unsigned char *s2)
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
        if (*q == '\0')
            break;
        if (_ismbblead(*p))
        {
            p++;
            if (*p == '\0')
                break;
        }
    }
    return (size_t)(p - s1);
}

