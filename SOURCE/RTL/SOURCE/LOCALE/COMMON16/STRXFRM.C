/*-----------------------------------------------------------------------*
 * filename - strxfrm.c
 *
 * function(s)
 *        strxfrm - transforms a "C" locale only string by coping
 *                  one string into another
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <string.h>

size_t _CType strxfrm(char *dest, const char *src, size_t n)
{
    int l = strlen( src );

    if (n > l)      // Only touch string if full transformation is possible
        memcpy(dest, src, l+1);

    return l;       // Always return length needed to tranform string
}


