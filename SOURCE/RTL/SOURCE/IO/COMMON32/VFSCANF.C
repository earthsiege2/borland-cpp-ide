/*-----------------------------------------------------------------------*
 * filename - vfscanf.c
 *
 * function(s)
 *        vfscanf - performs formatted input from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include <_stdio.h>
#include <_scanf.h>

#undef   ungetc     /* remove the macro version */

/*---------------------------------------------------------------------*

Name            vfscanf - performs formatted input from a stream

Usage           #include <stdio.h>
                int vfscanf(FILE *stream, char *format, va_list param);

Prototype in    stdio.h

Description     see ...scanf

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC vfscanf( FILE *fp, const char *fmt, va_list ap )
{
    int ret;

    _lock_stream(fp);
    ret =  _scanner( (int (*)(void *))fgetc,
                    (void (*)(int, void *))ungetc,
                    fp,
                    fmt,
                    ap );
    _unlock_stream(fp);
    return (ret);
}
