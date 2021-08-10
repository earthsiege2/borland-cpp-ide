/*-----------------------------------------------------------------------*
 * filename - strset.c
 *
 * function(s)
 *        strset - sets all characters in a string to a given
 *                 character
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

Name            strset - sets all characters in a string to a given
                         character

Usage           char *strset(char *str, int ch);

Prototype in    string.h

Description     strset sets all characters in the string str to the
                character ch.

Return value    pointer to str

*---------------------------------------------------------------------*/

#ifdef strset
#  undef strset
#  define INTRINSIC
#endif

char * _RTLENTRY _EXPFUNC strset(char *s, int ch)
{
#ifdef INTRINSIC
    return __strset__(s, ch);
#else
     memset(s, ch, strlen(s));
     return (s);
#endif
}
