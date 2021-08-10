/*-----------------------------------------------------------------------*
 * filename - vscanf.c
 *
 * function(s)
 *        vscanf - performs formatted input from stdin
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include <_stdio.h>
#include <_scanf.h>

#undef   ungetc     /* remove the macro version */

/*---------------------------------------------------------------------*

Name            vscanf - performs formatted input from stdin

Usage           int vscanf(const char *format, va_list param);

Prototype in    stdio.h

Description     see ...scanf

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC vscanf (const char *fmt, va_list ap)
{
    int ret;

    _lock_stream(stdin);
    ret = _scanner( (int (*)(void *))fgetc,
                    (void (*)(int, void *))ungetc,
                    stdin,
                    fmt,
                    ap );
    _unlock_stream(stdin);
    return (ret);
}
