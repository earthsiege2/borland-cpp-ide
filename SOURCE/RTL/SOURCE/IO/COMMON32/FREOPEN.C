/*-----------------------------------------------------------------------*
 * filename - freopen.c
 *
 * function(s)
 *        freopen       - replaces a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            freopen -  replaces a stream

Usage           FILE *freopen(const char *filename, const char *type,
                              FILE *stream);

Prototype in    stdio.h

Description     See description of fopen() in fopen.c

*---------------------------------------------------------------------*/

FILE * _RTLENTRY _EXPFUNC freopen(const char *filename, const char *type, FILE *fp)
{
    FILE *rc;

    if (fp->token != (short) fp)
        return NULL;    /* validate pointer */

    _lock_all_streams();
    _lock_stream(fp);

    fclose (fp);

    rc = __openfp (fp, filename, type, 0);

    _unlock_stream(fp);
    _unlock_all_streams();

    return (rc);
}
