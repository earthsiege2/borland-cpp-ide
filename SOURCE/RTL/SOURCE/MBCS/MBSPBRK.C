/*-----------------------------------------------------------------------*
 * filename - mbspbrk.c
 *
 * function(s)
 *        _mbspbrk - Scans a string for the first accurrence of
 *                   any character from a given set.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbspbrk - Scans a string for the first accurrence of
                           any character from a given set.

Usage           unsigned char *_mbspbrk(const unsigned char *str1,
                                        const unsigned char *str2);

Prototype in    mbstring.h

Description     _mbspbrk scans a string str1, for the first occurrence of
                any character appearing in str2

                If the second byte of 2-bytes character is null,
                this character is regarded as null.

Return value    _mbspbrk returns a pointer to the first occurrence of
                any of the characters in str2. If none of the str2
                characters occur in str1, _mbspbrk returns null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbspbrk(const unsigned char *s1, const unsigned char *s2)
{
    const unsigned char *p;
    const unsigned char *q;

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
        if (*q != '\0')
            return (unsigned char*)p;
        if (_ismbblead(*p))
        {
            p++;
            if (*p == '\0')
                break;
        }
    }
    return NULL;
}
