/*-----------------------------------------------------------------------*
 * filename - mbccmp.c
 *
 * function(s)
 *        _mbccmp - Compares one character to another.
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

Name            _mbccmp - Compares one character to another.

Usage           int _mbccmp(const unsigned char *str1,
                            const unsigned char *str2);

Prototype in    mbstring.h

Description     Returns a value(<0, 0 or >0) based on the result of
                comparing the first character of str1 to the first
                character of str2.

Return value    _mbccmp returns a int value as following;

                        < 0  str1 is less than str2
                        = 0  str1 is the same as str2
                        > 0  str1 is the same as str2

                The relation for conparison is, 

                ASCII < 1 byte Kana < 2 bytes character			 

                If the second byte of 2-bytes character is null,
		that character is regarded as null.    

*---------------------------------------------------------------------*/

#ifdef _mbccmp
#undef _mbccmp
#endif

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

int _RTLENTRY _EXPFUNC (_mbccmp)(const unsigned char *s1, const unsigned char *s2)
{
    unsigned int c1, c2;

    c1 = *s1;
    if (_ismbblead(c1))
    {
        if (s1[1] == '\0')
            c1 = 0;
        else
            c1 = (c1 << 8) | s1[1];
    }
    c2 = *s2;
    if (_ismbblead(c2))
    {
        if (s2[1] == '\0')
            c2 = 0;
        else
            c2 = (c2 << 8) | s2[1];
    }
    if (c1 != c2)
        return (c1 < c2) ? -1 : 1;
    return 0;
}
