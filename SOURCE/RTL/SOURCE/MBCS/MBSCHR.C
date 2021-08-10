/*-----------------------------------------------------------------------*
 * filename - mbschr.c
 *
 * function(s)
 *        _mbschr - Scans a string for the first occurrence of a given
 *                  character.
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

Name            _mbschr - Scans a string for the first occurrence of
                          a given character.

Usage           unsigned char *_mbschr(const unsigned char *str,
                                       unsigned int c);

Prototype in    mbstring.h

Description     _mbschr scans stirng s and returns a pointer for
                the first occurrence of the character c in s.

                The null-terminator is considered to be part of
                the string, for example;

                        _mbschr(strs, 0)

                returns a pointer to the terminating null character
                of the string strs.

                If the second byte of 2-bytes character is null, the first
                byte character is regarded as null.

Return value    Returns a pointer to the first occurrence of the character
                c in s,if c does not occur in s, _mbschr returns null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbschr(const unsigned char *s, unsigned int c)
{
    for ( ; ; s++)
    {
        if (_ismbblead(*s))
        {
            if (s[1] == '\0')
            {
                if (c == 0)
                {
                    s++;
                    return (unsigned char *)s;
                }
                break;
            }
            if ((((unsigned int)*s << 8) | s[1]) == c)
                return (unsigned char *)s;
            s++;
        }
        else
        {
            if (*s == c)
                return (unsigned char *)s;
            if (*s == '\0')
                break;
        }
    }
    return NULL;
}
