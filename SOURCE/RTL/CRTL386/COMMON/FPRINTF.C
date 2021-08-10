/*-----------------------------------------------------------------------*
 * filename - fprintf.c
 *
 * function(s)
 *    fprintf - sends formatted output to a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>
#include <_printf.h>

/*---------------------------------------------------------------------*

Name            fprintf - sends formatted output to a stream

Usage           int fprintf(FILE *stream, const char *format [,argument, ...]);

Prototype in    stdio.h

Description     member of the printf family.  fprintf send its output
                to the named stream.

Return value    success : the number of bytes output.
                error : EOF

*------------------------------------------------------------------------*/

int _cdecl _EXPFUNC fprintf (FILE *F, const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    _lock_stream(F);
    ret =  __vprinter ((putnF *)__fputn, F, fmt, ap);
    _unlock_stream(F);
    va_end(ap);
    return (ret);
}
