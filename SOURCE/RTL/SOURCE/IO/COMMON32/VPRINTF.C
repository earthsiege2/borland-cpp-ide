/*-----------------------------------------------------------------------*
 * filename - vprintf.c
 *
 * function(s)
 *    vprintf - send formatted output to stdout
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_printf.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            vprintf - send formatted output to stdout

Usage           int vprintf(const char *format, va_list param);

Prototype in    stdio.h

Description     see printf

*---------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC vprintf (const char *fmt, va_list ap)
{
    int ret;

    _lock_stream(stdout);
     ret =  __vprinter ((putnF *)__fputn, stdout, fmt, ap);
    _unlock_stream(stdout);
    return (ret);
}
