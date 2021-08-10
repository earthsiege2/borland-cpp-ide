/*-----------------------------------------------------------------------*
 * filename - printf.c
 *
 * function(s)
 *        printf - send formatted output to stdout
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
#include <_printf.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            printf - send formatted output to stdout

Usage           int printf(const char *format, ...);

Prototype in    stdio.h

Description     sends formatted output to stdout

Return value    the number of bytes output.  In the event of an
                error, printf returns EOF.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tprintf(const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    _lock_stream(stdout);
    ret = __vprintert ((putnF *)__fputnt, stdout, fmt, ap);
    _unlock_stream(stdout);
    va_end(ap);
    return (ret);
}
