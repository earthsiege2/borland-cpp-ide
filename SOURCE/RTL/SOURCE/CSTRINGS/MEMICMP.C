/*-----------------------------------------------------------------------*
 * filename - memicmp.c
 *
 * function(s)
 *        memicmp - compares two memory areas
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <mem.h>
#include <ctype.h>

/*------------------------------------------------------------------------*

Name            memicmp - compares two memory areas

Usage           int memicmp(const void *s1, const void *s2, size_t n);

Prototype in    mem.h & string.h

Description     memicmp compares the  first n bytes of s1  and s2, ignoring
                character case (upper or lower).

Return value    < 0 if s1 is less than s2
                = 0 if s1 is the same as s2
                > 0 if s1 is greater than s2

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC memicmp(const void *s1, const void *s2, size_t n)
{
    int dif;
    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;

    for (; n-- >0; p1++, p2++ )
    {
        dif = toupper(*p1) - toupper(*p2);
        if (dif != 0)
            return(dif);
    }
    return(0);
}
