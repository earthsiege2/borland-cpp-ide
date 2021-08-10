/*-----------------------------------------------------------------------*
 * filename - puts.c
 *
 * function(s)
 *        puts - puts a string on a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            puts - outputs a string to stdout

Usage           int puts(const char *string);

Prototype in    stdio.h

Description     puts copies the null-terminated string string to the
                standard output stream stdout and appends a newline character.

Return value    On successful completion, puts returns the
                last character written. Otherwise, a value of EOF is
                returned.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC puts (const char *s)
{
    int len, rc;

    _lock_stream(stdout);

    if (s == NULL)
        rc = 0;
    else
    {
        len = strlen(s);
        if ((int)__fputn(s,len,stdout) == len && _lputc('\n',stdout) == '\n')
            rc = '\n';
        else
            rc = EOF;
    }

    _unlock_stream(stdout);

    return (rc);
}
