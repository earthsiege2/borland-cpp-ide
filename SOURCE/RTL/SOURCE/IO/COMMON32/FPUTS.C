/*-----------------------------------------------------------------------*
 * filename - fputs.c
 *
 * function(s)
 *        fputs - puts a string on a stream
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
#include <string.h>
#include <_io.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _fputts used as fputs and fputws
                fputs  - puts a string on a stream
                fputws - puts a wide string on a stream

Usage           #include <stdio.h>
                int fputs(const char *string, FILE *stream);
                int fputws(const wchar_t *string, FILE *stream);

Prototype in    stdio.h

Description     copies the null-terminated string string to the named
                output stream; it does not append a newline character.

Return value    success : the last character written
                else    : EOF

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _fputts (const _TCHAR *s, FILE *fp)
{
    int len, rc;
#ifdef _UNICODE
    int i;
#endif

    _lock_stream(fp);

    if (s != NULL && (len = _tcslen(s)) != 0)
#ifndef _UNICODE
    {
      rc = __fputn (s, len, fp) ? *(unsigned char *)(s+len-1) : EOF;
    }
#else
    {
      for (i=0; i<len; i++)
      {
        rc = s[i];
        if (rc != _lputwc (rc, fp))
            RETURN(EOF);
      }
    }
#endif
    else
        rc = 0;

#ifdef _UNICODE
exit:
#endif
    _unlock_stream(fp);
    return (rc);
}
