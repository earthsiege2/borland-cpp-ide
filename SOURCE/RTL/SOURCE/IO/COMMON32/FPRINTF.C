/*-----------------------------------------------------------------------*
 * filename - fprintf.c
 *
 * function(s)
 *    fprintf - sends formatted output to a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_printf.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            fprintf - sends formatted output to a stream

Usage           int fprintf(FILE *stream, const char *format [,argument, ...]);

Prototype in    stdio.h

Description     member of the printf family.  fprintf send its output
                to the named stream.

Return value    success : the number of bytes output.
                error : EOF

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ftprintf (FILE *F, const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    _lock_stream(F);
    ret =  __vprintert ((putnF *)__fputnt, F, fmt, ap);
    _unlock_stream(F);
    va_end(ap);
    return (ret);
}
