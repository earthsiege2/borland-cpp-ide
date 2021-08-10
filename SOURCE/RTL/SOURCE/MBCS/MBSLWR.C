/*-----------------------------------------------------------------------*
 * filename - mbslwr.c
 *
 * function(s)
 *        _mbslwr - Converts uppercase letters in a string to lowercase.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbslwr - Converts uppercase letters in a string to
                          lowercase.

Usage           unsigned char *_mbslwr(unsigned char *s);

Prototype in    mbstring.h

Description     Converts all uppercase lettes in string s to lowercase

Return value    _mbslwr returns a value of pointer same as argument s.

                If the second byte of 2-bytes character is null,
                the first byte of this character is regarded as null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbslwr(unsigned char *s)
{
    unsigned char *p;

    for (p = s; *p; p++)
    {
        if (_ismbblead(*p) && p[1])
            p++;
        else
            *p = _ltolower(*p);
    }
    return s;
}
