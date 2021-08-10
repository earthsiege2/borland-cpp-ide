/*-----------------------------------------------------------------------*
 * filename - freopen.c
 *
 * function(s)
 *        freopen       - replaces a stream
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
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _tfreopen used as freopen and _wfreopen
                freopen   -  replaces a stream
                _wfreopen -  replaces a stream

Usage           FILE *freopen(const char *filename, const char *type,
                              FILE *stream);
                FILE *_wfreopen(const wchar_t *filename, const wchar_t *type,
                              FILE *stream);

Prototype in    stdio.h

Description     See description of fopen() in fopen.c

*---------------------------------------------------------------------*/

FILE * _RTLENTRY _EXPFUNC _tfreopen(const _TCHAR *filename,
                                    const _TCHAR *type, FILE *fp)
{
    FILE *rc;

    if (fp->token != (unsigned char) fp)
        return NULL;    /* validate pointer */

    _lock_all_streams();
    _lock_stream(fp);

    fclose (fp);

    rc = __topenfp (fp, filename, type, 0);

    _unlock_stream(fp);
    _unlock_all_streams();

    return (rc);
}
