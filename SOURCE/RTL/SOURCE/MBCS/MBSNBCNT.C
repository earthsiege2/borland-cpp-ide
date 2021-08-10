/*-----------------------------------------------------------------------*
 * filename - mbsnbcnt.c
 *
 * function(s)
 *        _mbsnbcnt - Counts the byte size of the portion of a string,
 *                    starting the first to Nth charachter in a
 *                    string.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsnbcnt - Counts the byte size of the portion of a
                            string, starting the first to Nth charachter
                            in a string.

Usage           size_t _mbsnbcnt(const char *s, size_t n);

Prototype in    mbstring.h

Description     _mbsnbcnt counts the number of characters from a heading
                of string s to specified number by N untill occurance of
                null-character.

                If the second byte of 2-byte character is null,the first
                byte of this character is not included to the number of
                characters.

                _mbsnbcnt ignores the second byte of 2-bytes code even if
                it is a illegal value.(that character is counted as same
                as legal characters.)

Return value    Returns the number of characters in specified potion.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

size_t _RTLENTRY _EXPFUNC _mbsnbcnt(const unsigned char *s, size_t n)
{
    const unsigned char *p;

    for (p = s; n > 0 && *p; n--, p++)
    {
        if (_ismbblead(*p))
        {
            if (p[1] == '\0')
                break;
            p++;
        }
    }
    return (size_t)(p - s);
}
