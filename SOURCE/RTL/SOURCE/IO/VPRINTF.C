/*-----------------------------------------------------------------------*
 * filename - vprintf.c
 *
 * function(s)
 *    vprintf - send formatted output to stdout
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4 $        */

#include <stdio.h>
#include <_printf.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            vprintf - send formatted output to stdout

Usage           int vprintf(const char *format, va_list param);

Prototype in    stdio.h

Description     see printf

*---------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _vtprintf (const _TCHAR *fmt, va_list ap)
{
    int ret;

    _lock_stream(stdout);
     ret =  __vprintert ((putnF *)__fputnt, stdout, fmt, 0, 0, ap);
    _unlock_stream(stdout);
    return (ret);
}
