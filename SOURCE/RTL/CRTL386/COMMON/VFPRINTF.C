/*-----------------------------------------------------------------------*
 * filename - vfprintf.c
 *
 * function(s)
 *    vfprintf - sends formatted output to a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_printf.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            vfprintf - sends formatted output to a stream

Usage           #include <stdio.h>
                #include <stdarg.h>
                int vfprintf(FILE *stream, const char *format, va_list param);

Prototype in    stdio.h
                stdarg.h

Description     see printf

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC vfprintf( FILE *F, const char *fmt, va_list ap )
{
    int ret;

    _lock_stream(F);
    ret = __vprinter( (putnF *)__fputn, F, fmt, ap );
    _unlock_stream(F);
    return (ret);
}

