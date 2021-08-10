/*-----------------------------------------------------------------------*
 * filename - mbsnbcat.c
 *
 * function(s)
 *        _mbsnbcat - Appends a portion(spesified N) of one string
 *                    to another.
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

Name            _mbsnbcat - Appends a portion(spesified N) of one string
                            to another.

Usage           unsigned char *_mbsnbcat(unsigned char *dest,
                                         const unsigned char *src,
                                         size_t maxlen);

Prototype in    mbstring.h

Description     _mbsnbcat copies at most maxlen characters of src to the
                end of dest and then appends a null character.
                The maximam length of the resulting string is maxlen.

                If the second byte of 2-bytes character is null,
                the first byte of this character is regarded as null

Return value    Returns a pointer to dest

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsnbcat(unsigned char *s1, const unsigned char *s2, size_t n)
{
    unsigned char *p;

    if (n <= 0)
        return s1;
    p = s1;
    while (*p)
        p++;
    if (p > s1 && _mbsbtype(s1, (size_t)(p - s1) - 1) == _MBC_LEAD)
        p--;

    while (n > 0 && *s2)
    {
        if (_ismbblead(*s2))
        {
            if (n < 2 || s2[1] == '\0')
                break;
            *p++ = *s2++;
            n--;
        }
        *p++ = *s2++;
        n--;
    }
    *p = '\0';
    return s1;
}
