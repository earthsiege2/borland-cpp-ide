/*-----------------------------------------------------------------------*
 * filename - vfscanf.c
 *
 * function(s)
 *        vfscanf - performs formatted input from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <stdarg.h>
#include <stdio.h>
#include <_stdio.h>
#include <_scanf.h>
#include <_tchar.h>

#undef   ungetc     /* remove the macro version */

/*---------------------------------------------------------------------*

Name            vfscanf - performs formatted input from a stream

Usage           #include <stdio.h>
                int vfscanf(FILE *stream, char *format, va_list param);

Prototype in    stdio.h

Description     see ...scanf

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _vftscanf( FILE *fp, const _TCHAR *fmt, va_list ap )
{
    int ret;

    _lock_stream(fp);
    ret =  _scannert( (int (*)(void *))_fgettc,
                    (void (*)(int, void *))_ungettc,
                    fp,
                    fmt,
                    ap );
    _unlock_stream(fp);
    return (ret);
}
