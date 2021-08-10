/*-----------------------------------------------------------------------*
 * filename - mbsnicmp.c
 *
 * function(s)
 *        _mbsnicmp - Compares one string to another,without case
 *                    sensitivity.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>

#if 0
extern int _mbascii;
#endif

/*---------------------------------------------------------------------*

Name            _mbsnicmp - Compares one string to another,without case
                            sensitivity.

Usage           int _mbsnicmp(const unsigned char *str1,
                              const unsigned char *str2, size_t maxlen);

Prototype in    mbstring.h

Description     Compares str1 to str2, it starts with the first character
                in each string and continues with subsequent characters
                differ or until it has examined maxlen characters.
                The comparison is not sensitive.

Return value    _mbsnicmp returns an int value based on the result of
                comparing str1 to str2;

                        < 0  if str1 is less than str2
                        = 0  if str1 is the same as str2
                        > 0  if str1 is greater than str2

                The relation for conparison is,

                        ASCII <  1 byte Kana <  2 bytes character

                If the second byte of 2-bytes character is null,
		that character is regarded as null. 

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

int _RTLENTRY _EXPFUNC _mbsnicmp(const unsigned char *s1, const unsigned char *s2, size_t n)
{
    unsigned int c1, c2;

    for ( ; n > 0; n--)
    {
        c1 = *s1++;
        if (_ismbblead(c1))
        {
            if (*s1 == '\0')
                c1 = 0;
            else
            {
                c1 = (c1 << 8) | *s1++;
#if 0
                if (_mbascii && c1 >= 0x8281 && c1 <= 0x829A)
                    c1 -= 0x21;
#endif
            }
        }
        else
        {
            if (islower(c1))
                c1 -= 0x20;
        }
        c2 = *s2++;
        if (_ismbblead(c2))
        {
            if (*s2 == '\0')
                c2 = 0;
            else
            {
                c2 = (c2 << 8) | *s2++;
#if 0
                if (_mbascii && c2 >= 0x8281 && c2 <= 0x829A)
                    c2 -= 0x21;
#endif
            }
        }
        else
        {
            if (islower(c2))
                c2 -= 0x20;
        }
        if (c1 != c2)
            return (c1 < c2) ? -1 : 1;
        if (c1 == 0)
            break;
    }
    return 0;
}
