/*-----------------------------------------------------------------------*
 * filename - mbsdup.c
 *
 * function(s)
 *        _mbsdup - Copies a string into a newly created location.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsdup - Copies a string into a newly created location.

Usage           unsigned char *_mbsdup(const unsigned char *str);

Prototype in    mbstring.h

Description     _mdsdup makes a duplicate of strings str with null-
                terminating character, obtaining space with a call to
                malloc.The allocated space is (strlen(str + 1)) byte long.

Return value	Return null pointer if space could not be allocated
                with a call to malloc.

                The user is responcible for freeing the space allocated
                by _mbsdup to use free(or _ffree for _fmbsdup)
                when it is no longer needed.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsdup(const unsigned char *s)
{
    return (unsigned char *)strdup((const char *)s);
}
