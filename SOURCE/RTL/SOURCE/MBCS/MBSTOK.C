/*-----------------------------------------------------------------------*
 * filename - mbstok.c
 *
 * function(s)
 *        _mbstok - Searches one string for tokens.
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

static unsigned char *Ss = NULL;

/*---------------------------------------------------------------------*

Name            _mbstok - Searches one string for tokens.

Usage           unsigned char *_mbstok(unsigned char *str1,
                                       const unsigned char *str2);

Prototype in    mbstring.h

Description     _mbstok consideres the string str1 to consist of sequence
                of zero or more text tokens,separated by spans of one or
                more characters from the separator string str2.

                The first call to _mbstok returns a pointer to the first
                character of the first token in str1 and writes a null
                character into str1 immediately following the returned
                token.Subsequent calls with null forthe first argument
                will work through the string str1 in this way,until
                no tokens remain.

                The separator string, str2, can be different from call
                to call.

Return value    Returns a pointer to the token found in str1.
                A null pointer is returned when there are no more tokens.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbstok(unsigned char *s1, const unsigned char *s2)
{
    unsigned char *p, *q;

    if (s1)
        p = _mbsspnp(s1, s2);
    else if (Ss)
        p = _mbsspnp(Ss, s2);
    else
        return NULL;
    if (!p || *p == '\0' || (_ismbblead(*p) && p[1] == '\0') )
        return NULL;
    q = _mbspbrk(p, s2);
    if (!q || *q == '\0')
        Ss = NULL;
    else
    {
        if (_ismbblead(*q))
            *q++ = '\0';
        *q++ = '\0';
        Ss = q;
    }
    return p;
}
