/*-----------------------------------------------------------------------*
 * filename - strxfrm.c
 *
 * function(s)
 *        strxfrm - copies one string into another
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>

/*---------------------------------------------------------------------*

Name            strxfrm - transforms a portion of a string

Usage           size_t strxfrm( char *dest, const char *src, size_t n )

Prototype in    string.h

Description     strxfrm transforms the string pointed to by src into the
                string dest for no more than n characters.

Return value    Number of characters copied

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC strxfrm( char *dest, const char *src, size_t n )

{
    int l = strlen( src );

    if (n > l)
        memcpy(dest, src, l+1);
  
    return l;
}

