/*-----------------------------------------------------------------------*
 * filename - mbscpy.c
 *
 * function(s)
 *        _mbscpy - Copies one string to another.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <string.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbscpy - Copies one string to another.

Usage           unsigned char *_mbscpy(unsigned char *dest,
                                       const unsigned char *src);

Prototype in    mbstring.h

Description     _mbscpy copies string src to dest,stopping after the
                terminating null character. dest is requied the size
                for the length of src and null character at least.

                It doesn't check whether null pointer or not,so dont't
                pass it.

                If the second byte of 2-bytes character is null,the first
                byte character isn't regarded as null.It is equal with strcpy().

Return value    Returns a pointer to dest.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbscpy(unsigned char *s1, const unsigned char *s2)
{
    return (unsigned char *)strcpy((char *)s1, (const char *)s2);
}
