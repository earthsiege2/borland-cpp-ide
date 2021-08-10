/*-----------------------------------------------------------------------*
 * filename - mbsisle.c
 *
 * function(s)
 *        _ismbslead - Tests a character whether it is the first byte of
 *                     2-bytes character or not.
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

Name            _ismbslead - Tests a character whether it is the first
                             byte of 2-byte character or not.

Usage           int _ismbslead(const unsigned char *str1,
                               const unsigned char *str2);

Prototype in    mbctype.h

Description     Tests a byte data positioned str2 which starting from
                str1 whether it is the first byte of 2-bytes character
                or not.

Return value    Returns the value excepting 0 if the byte data of ser2
                is the first byte of 2-bytes character, and return 0
                if it is not.

                Returns 0 if there is null character between str1
                and str2.

                If the second byte of 2-bytes character is null,
                that character is regarded as null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

int _RTLENTRY _EXPFUNC _ismbslead(const unsigned char *s1, const unsigned char *s2)
{
    for ( ; s1 <= s2 && *s1; s1++)
    {
        if (_ismbblead(*s1))
        {
            if (s2 == s1)
                return 1;
            s1++;
            if (*s1 == 0)
                break;
        }
    }
    return 0;
}

