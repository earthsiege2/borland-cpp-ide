/*-----------------------------------------------------------------------*
 * filename - mbsrev.c
 *
 * function(s)
 *        _mbsrev - Reverses a string.
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

Name            _mbsrev - Reverses a string.

Usage           unsigned char *_mbsrev(unsigned char *str);

Prototype in    mbstring.h

Description     _mbsrev changes all characters in a string str to
                reverese order, except the terminating null character.

Return value    _mbsrev returns a pointer to the reversed string(the same
                as str).

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsrev(unsigned char *s)
{
    unsigned char *p, *q;
    unsigned char t;

    /* first, reverse 1st and 2nd byte couple of double byte code */
    for (p = s; *p; p++)
    {
        if (_ismbblead(*p))
        {
            p++;
            if (*p == '\0')
                break;
            t = *p;
            *p = p[-1];
            p[-1] = t;
        }
    }
    /* second, reverse byte stream */
    for (q = s, p--; q < p; q++, p--)
    {
        t = *q;
        *q = *p;
        *p = t;
    }
    return s;
}
