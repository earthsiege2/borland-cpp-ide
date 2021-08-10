/*-----------------------------------------------------------------------*
 * filename - fputc.c
 *
 * function(s)
 *      fputc    - puts a character on a stream with locking
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            fputc - puts a character on a stream with locking

Usage           #include <stdio.h>
                int fputc(int ch, FILE *stream);

Related
functions usage int _lputc(int ch, FILE *stream);

Prototype in    stdio.h

Description     see _lputc in lputc.c

Return value    see _lputc.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fputc (int ch, FILE *fp)
{
    int ret;

    _lock_stream(fp);
    ret = _lputc(ch,fp);
    _unlock_stream(fp);
    return (ret);
}
