/*-----------------------------------------------------------------------*
 * filename - fscanf.c
 *
 * function(s)
 *        fscanf - performs formatted input from a stream
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

#undef   ungetc         /* remove the macro version */

/*---------------------------------------------------------------------*

Name            fscanf - performs formatted input from a stream

Usage           #include <stdio.h>
                int fscanf(FILE *stream, const char *format[, argument,...]);

Prototype in    stdio.h

Description     reads data from the named input stream into the locations
                given by the address arguments

Return value    the number of input fields successfully scanned, converted
                and stored; the return value does not include scanned
                fields that were not stored.

                If an attempt is made to read at end-of-file, the return
                value is EOF.

                If no fields were stored, the return value is 0

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ftscanf (FILE *fp, const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    _lock_stream(fp);
    ret =  _scannert ( (int (*)(void *))_fgettc,
                     (void (*)(int, void *))_ungettc,
                     fp,
                     fmt,
                     ap);
    _unlock_stream(fp);
    va_end(ap);
    return (ret);
}
