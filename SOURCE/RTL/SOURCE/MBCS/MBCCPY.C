/*-----------------------------------------------------------------------*
 * filename - mbccpy.c
 *
 * function(s)
 *        _mbccpy - Copies one character into another.
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

Name            _mbccpy - Copies one character into another.

Usage           void _mbccpy(unsigned char *dest,
                             const unsigned char *src);

Prototype in    mbstring.h

Description     _mbccpy copies the first character of src to dest.
                dest should be the same size with the first character
                of scr.

                It doesn't check whether null pointer or not,so don't
                pass it.

                It doesn't regard the character of the first byte as NULL
                character even if the second byte of 2 byte character is
                NULL character.

Return value    None.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

void _RTLENTRY _EXPFUNC _mbccpy(unsigned char *dest, const unsigned char *src)
{
    *dest = *src;
    if (_ismbblead(*src))
        dest[1] = src[1];
}
