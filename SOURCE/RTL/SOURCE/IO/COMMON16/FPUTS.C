/*-----------------------------------------------------------------------*
 * filename - fputs.c
 *
 * function(s)
 *        fputs - puts a string on a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stdio.h>
#include <_stdio.h>
#include <string.h>

/*---------------------------------------------------------------------*

Name            fputs - puts a string on a stream

Usage           #include <stdio.h>
                int fputs(const char *string, FILE *stream);

Prototype in    stdio.h

Description     copies the null-terminated string string to the named
                output stream; it does not append a newline character.

Return value    success : the last character written
                else    : EOF

*---------------------------------------------------------------------*/
int _FARFUNC fputs (const register char *s, FILE *fp)
{
    register int len;

    if (s == NULL)
        return (0);
    if ((len = strlen(s)) == 0)
        return (0);
    return  __fputn (s, len, fp)  ?  *(unsigned char *)(s+len-1) : EOF;
}
