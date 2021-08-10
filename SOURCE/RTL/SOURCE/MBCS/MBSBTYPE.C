/*-----------------------------------------------------------------------*
 * filename - mbsbtype.c
 *
 * function(s)
 *        _mbsbtype - Returns a type of character of Nth byte from the
 *                    beginning of a string
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

Name            _mbsbtype - Returns the type of character of Nth byte
                            from the beginning of a string.

Usage           #include <mbctype.h>
                int _mbsbtype(const unsigned char *c, size_t nbyte);

Prototype in    mbstring.h

Description     _mbsbtype returns the type of character of  Nth byte
                from the beginning of a string inculuding 2-bytes code.

Return value    Returns any type of character as following;

                 symbol      value  meaning
                --------------------------------------------------------
                 _MBC_SINGLE    0   1-byte code(excepting 2-bytes code)
                 _MBC_LEAD      1   the first byte of 2-bytes code
                 _MBC_TRAIL     2   the second byte of 2-bytes code
                 _MBC_ILLEGAL  -1   others

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

int _RTLENTRY _EXPFUNC _mbsbtype(const unsigned char *s, size_t n)
{
    int t;

    t = _MBC_ILLEGAL;
    for (;;)
    {
        if (*s == '\0')
            return _MBC_ILLEGAL;
        t = _mbbtype(*s, t);
        if (n == 0)
            break;
        s++;
        n--;
    }
    return t;
}
