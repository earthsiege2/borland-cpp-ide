/*-----------------------------------------------------------------------*
 * filename - strrchr.c
 *
 * function(s)
 *        strrchr - scans a string for the last occurrence of a
 *          given character
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline

#include <string.h>

/*---------------------------------------------------------------------*

Name            strrchr - scans a string for the last occurrence of a
                    given character

Usage           char *strrchr(const char *str, int c);

Prototype in    string.h

Description     strrchr scans a string in the reverse direction, looking for a
                specific character. strrchr finds the last occurrence of the
                character ch in the string str. The null-terminator is considered
                to be part of the string.

Return value    strrchr returns a pointer to the last occurrence of the
                character ch. If ch does not occur in str, strrchr returns
                NULL.

*---------------------------------------------------------------------*/

#ifdef strrchr
#  undef strrchr
#  define INTRINSIC
#endif


char * _RTLENTRYF _EXPFUNC strrchr( const char *p, int c )
{

#ifdef INTRINSIC
    return __strrchr__(p, c);
#else
    char *q;

for (q = (char *)(p + strlen(p)); *q != (char)c; q--)
        if (q == p)
            return (NULL);
    return (q);
#endif

}
