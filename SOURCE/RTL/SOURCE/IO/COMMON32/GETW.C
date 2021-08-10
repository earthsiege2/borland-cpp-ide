/*-----------------------------------------------------------------------*
 * filename - getw.c
 *
 * function(s)
 *        getw - gets a word from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>

/*---------------------------------------------------------------------*

Name            getw - gets a word from a stream

Usage           #include <stdio.h>
                int getw(FILE * stream);

Prototype in    stdio.h

Description     see getc

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC getw(FILE *fp)
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
