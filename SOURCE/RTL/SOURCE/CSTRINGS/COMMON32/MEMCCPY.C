/*-----------------------------------------------------------------------*
 * filename - memccpy.c
 *
 * function(s)
 *        memccpy - copy bytes from src to dst
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mem.h>

/*-----------------------------------------------------------------------*

Name            memccpy - copy bytes from src to dst

Usage           void *memccpy(void *dst, const void *src,
                              int val, size_t n);

Prototype in    string.h & mem.h

Description     memccpy copies characters  from src to dst, until  either n
                characters are  moved or the  character val is  matched and
                copied,  without checks  and as  fast as  possible. If  the
                source  and  target  arrays  overlap,  the  effect  is  not
                defined.

Return value    If val  was matched then the  return value is a  pointer to
                the character  position following val in  dst, otherwise it
                is NULL.

*------------------------------------------------------------------------*/

void * _RTLENTRY _EXPFUNC memccpy(void *dst, const void *src, int val, size_t n)
{
    char *ps = (char *)src;
    char *pd = (char *)dst;
    if (!n)
       return 0;
    while ( n-- )
        {
        if (*ps != (char)val)
            *pd++ = *ps++;
        else
            {
            *pd++ = (char)val;
            return pd;
            }
        }
    return 0;
}
