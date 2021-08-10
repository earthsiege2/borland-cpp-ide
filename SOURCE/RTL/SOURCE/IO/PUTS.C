/*-----------------------------------------------------------------------*
 * filename - puts.c
 *
 * function(s)
 *        puts - puts a string on a stream
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
#include <string.h>
#include <_stdio.h>
#include <_io.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _putts used as puts and _putws
                puts   - outputs a string to stdout
                _putws - outputs a wide string to stdout

Usage           int puts(const char *string);
                int _putws(const wchar_t *string);

Prototype in    stdio.h

Description     _putts copies the null-terminated string string to the
                standard output stream stdout and appends a newline character.

Return value    On successful completion, _putts returns the
                last character written. Otherwise, a value of EOF is
                returned.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _putts (const _TCHAR *s)
{
    int len, rc;
#ifdef _UNICODE
    int i;
#endif

    _lock_stream(stdout);

    if (s == NULL)
        rc = 0;
    else
    {
        len = _tcslen(s);
#ifndef _UNICODE
        if ((int)__fputn(s,len,stdout) == len && _lputc('\n',stdout) == '\n')
            rc = '\n';
        else
            rc = EOF;
#else
        for (i=0; i<len; i++)
        {
          if (s[i] != _lputwc(s[i], stdout))
              RETURN(EOF);
        }
        if (L'\n' != _lputwc(L'\n', stdout))
            rc = EOF;
        else
            rc = L'\n';
#endif
    }

#ifdef _UNICODE
exit:
#endif
    _unlock_stream(stdout);

    return (rc);
}
