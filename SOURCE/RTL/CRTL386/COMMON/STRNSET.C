/*-----------------------------------------------------------------------*
 * filename - strnset.c
 *
 * function(s)
 *        strnset - sets all characters in a string to a given
 *              character
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <mem.h>

/*---------------------------------------------------------------------*

Name            strnset - sets all characters in a string to a given
                  character

Usage           char *strnset(char *str, int ch, size_t n);

Prototype in    string.h

Description     strnset sets up to the first n bytes of the string str to the
                character ch. If n > strlen(str), then strlen(str) replaces n.

Return value    pointer to str

*---------------------------------------------------------------------*/

#ifdef strnset
#  undef strnset
#  define INTRINSIC
#endif

char * _RTLENTRY _EXPFUNC strnset(char *s, int ch, size_t n)
{
#ifdef INTRINSIC
    return __strnset__(s, ch, n);
#else
    unsigned len;

    len = strlen(s);
    if (len < n)
        n = len;
    memset(s, ch, n);
    return (s);
#endif
}
