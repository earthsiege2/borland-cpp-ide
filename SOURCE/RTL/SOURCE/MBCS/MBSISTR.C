/*-----------------------------------------------------------------------*
 * filename - mbsistr.c
 *
 * function(s)
 *        _ismbstrail - Tests a character whether it is the second byte 
 *                      of 2-bytes character or not.
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

Name            _ismbstrail - Tests a character whether it is the second
                              byte of 2-bytes character or not.

Usage           int _ismbstrail(const unsigned char *str1,
                                const unsigned char *str2);

Prototype in    mbctype.h

Description     Tests a byte data positioned str2 which starting from
                str1 whether it is the second byte of 2-bytes character
                or not. 

Return value    Returns the value excepting 0 if the byte data of ser2
                is the second byte of 2-bytes character, and return 0
                if it is not.

                Returns 0 if null character exists between str1 to str2.

                If the second byte of 2-bytes character is null character,
                the character is regarded as null character.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

int _RTLENTRY _EXPFUNC _ismbstrail(const unsigned char *s1, const unsigned char *s2)
{
    for ( ; s1 <= s2 && *s1; s1++)
    {
        if (_ismbblead(*s1))
        {
            s1++;
            if (s1 == s2)
                return 1;
            if (*s1 == 0)
                break;
        }
    }
    return 0;
}
