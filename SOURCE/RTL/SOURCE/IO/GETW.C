/*-----------------------------------------------------------------------*
 * filename - _getw.c
 *
 * function(s)
 *        _getw - gets a word from a stream
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

Name            _getw - gets a word from a stream

Usage           #include <stdio.h>
                int _getw(FILE * stream);

Prototype in    stdio.h

Description     see getc

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _getw(FILE *fp)
{
    int c, res, i;
    char *p;

    for (i = 0, p = (char *)&res; i < sizeof(int); i++, p++)
        if ((c = getc(fp)) == EOF)
            return (EOF);
        else
            *p = (char)c;
    return(res);
}
