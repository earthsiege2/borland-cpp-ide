/*-----------------------------------------------------------------------*
 * filename - mbsncpy.c
 *
 * function(s)
 *        _mbsncpy - Copies a given number of bytes from one string
 *                   into another.
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

Name            _mbsncpy -  Copies a given number of bytes from one string
                            into another.

Usage           unsigned char *_mbsncpy(unsigned char *dest,
                                        const unsigned char *src,
                                        size_t n);

Prototype in    mbstring.h

Description     _mbsncpy copies up to n characters from src into dest,
                truncating or null-padding dest.

                _mbsnbcpy doesn't check whether it is a null pointer or
                not, so don't pass it.

                If the second byte of 2-bytes character is null,
                that character is regarded as null.

Return value    Returns a pointer to dest.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsncpy(unsigned char *s1, const unsigned char *s2, size_t n)
{
    unsigned char *p;

    p = s1;
    for ( ; n > 0; n--)
    {
        if (_ismbblead(*s2))
        {
            if (s2[1] == '\0')
                break;
            *p++ = *s2++;
            *p++ = *s2++;
        }
        else
        {
            if (*s2 == '\0')
                break;
            *p++ = *s2++;
        }
    }
    for ( ; n > 0; n--)
        *p++ = '\0';
    return s1;
}
