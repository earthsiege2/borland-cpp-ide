/*-----------------------------------------------------------------------*
 * filename - scanf.c
 *
 * function(s)
 *        scanf - gets formatted input from stdin
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdarg.h>
#include <stdio.h>
#include <_stdio.h>
#include <_scanf.h>
#include <_tchar.h>

#undef   ungetc     /* remove the macro version */

/*---------------------------------------------------------------------*

Name            scanf - gets formatted input from stdin

Usage           int scanf(const char *format[, argument ...])

Prototype in    stdio.h

Description     gets formatted input from stdin

Return value    number of fields scanned and stored.  scanf returns EOF
                if an attempt is made to read at end-of-file

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tscanf(const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    _lock_stream(stdin);
    ret =  _scannert( (int (*)(void *))_fgettc,
                    (void (*)(int, void *))_ungettc,
                    stdin,
                    fmt,
                    ap);
    _unlock_stream(stdin);
    va_end(ap);
    return (ret);
}
