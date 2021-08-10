/*-----------------------------------------------------------------------*
 * filename - strrchr.c
 *
 * function(s)
 *        strrchr - scans a string for the last occurrence of a
 *          given character
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
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
                character ch in the string str. The null-terminator is
                considered to be part of the string.

Return value    strrchr returns a pointer to the last occurrence of the
                character ch. If ch does not occur in str, strrchr returns
                NULL.

*---------------------------------------------------------------------*/
#undef strrchr            /* not an intrinsic */

/* alias records for C++ emplimentation of strrchr() */

#if !defined(__FARFUNCS__)

#if defined(__LARGE__) || defined(__COMPACT__) || defined(__HUGE__)
asm alias <@strrchr$qnxci> = <_strrchr>
asm alias <@strrchr$qnci>  = <_strrchr>

#else /* defined __TINY__ or __SMALL__ or __MEDIUM__ or __FLAT__ */

asm alias <@strrchr$qpxci> = <_strrchr>
asm alias <@strrchr$qpci>  = <_strrchr>
#endif

#endif

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#endif

char * _FARFUNC _CType strrchr( const char _FAR *s, int c )
{
    register const char *ss;
    register size_t i;

    for(i = strlen( s ) + 1, ss = s+i; i; i--)
        {
        if( *(--ss) == (char)c )  return( (char *)ss );
        }

    return( 0 );
}
