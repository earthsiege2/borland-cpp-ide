/*-----------------------------------------------------------------------*
 * filename - mbsrchr.c
 *
 * function(s)
 *        _mbsrchr - Scans a string for the last occurrence of a given
 *                   character.
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

Name            _mbsrchr - Scans a string for the last occurrence of
                           a given character.

Usage           unsigned char *_mbsrchr(const unsigned char *str,
                                        unsigned int c);

Prototype in    mbstring.h

Description     _mbsrchr finds the last occurrence of the character c
                in the string str.

                The null character is considered to be passed to
                character c.

                If the second byte of 2-bytes character is null character,
                this character is regarded as null character.

Return value    _mbsrchr returns a pointer to the last occurrence of the
                character c. If c does not occur in s, _mbsrchr returns
                null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsrchr(const unsigned char *s, unsigned int c)
{
    const unsigned char *p;

    p = NULL;
    do {
        if (_ismbblead(*s))
        {
            if (s[1] == '\0')
            {
                s++;
                if (c == 0)
                    p = s;
                break;
            }
            else
            {
                if ((((unsigned int)*s << 8) | s[1]) == c)
                    p = s;
                s++;
            }
        }
        else
        {
            if (*s == c)
                p = s;
        }
    } while (*s++) ;
    return (unsigned char *)p;
}
