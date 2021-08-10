/*-----------------------------------------------------------------------*
 * filename - _putw.c
 *
 * function(s)
 *        _putw - puts word on a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <stdio.h>

/*---------------------------------------------------------------------*

Name            _putw - puts a character or word on a stream

Usage           #include <stdio.h>
                int _putw(int w, FILE *stream);

Prototype in    stdio.h

Description     _putw outputs the integer w to the output stream. _putw neither
                expects nor causes special alignment in the file.

Return value    On success _putw returns the integer w.

                On error, _putw returns EOF.

                Since EOF is a legitimate integer, ferror
                should be used to detect errors with _putw.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _putw(int w, FILE *fp)
{
    int i;
    char *p;

    for (i = 0, p = (char *)&w; i < sizeof(int); i++, p++)
        if (putc(*p,fp) == EOF)
            return (EOF);
    return(w);
}
