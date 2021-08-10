/*-----------------------------------------------------------------------*
 * filename - sprintf.c
 *
 * function(s)
 *    strputn  - copies an n element string
 *    sprintf  - sends formatted output to a string
 *    vsprintf - sends formatted output to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <stdio.h>
#include <mem.h>
#include <string.h>
#include <_printf.h>
#include <_tchar.h>
/*---------------------------------------------------------------------*

Name            strputn - copies an n element string

Usage           static size_t strputn(char *S, size_t n, char **bufPP)

Description     copies n bytes from block pointed to by S to the block
                pointed to by bufPP.  bufPP is incremented by n.

Return value    0

*---------------------------------------------------------------------*/

static size_t strputn(_TCHAR *S, size_t n, _TCHAR **bufPP)
{
    memcpy (*bufPP, S, (n * sizeof (_TCHAR)));
    *(*bufPP += n) = _TEXT('\0');
    return n;
}


/*---------------------------------------------------------------------*

Name            sprintf - sends formatted output to a string

Usage           int sprintf(char *string, const char *format[, argument, ...]);

Prototype in    stdio.h

Description     sends formatted output to a string

Return value    number of bytes output

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _stprintf(_TCHAR *bufP, const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    *bufP = _TEXT('\0');
    va_start(ap,fmt);
    ret = __vprintert ((putnF *)strputn, &bufP, fmt, 0, 0, ap);
    va_end(ap);
    return (ret);
}

/*---------------------------------------------------------------------*

Name            vsprintf - sends formatted output to a string

Usage           int vsprintf(char *string, const char *format, va_list param);

Prototype in    stdio.h

Description     sends formatted output to a string

Return value    number of bytes output

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _vstprintf(_TCHAR *bufP, const _TCHAR *fmt, va_list ap)
{
    *bufP = _TEXT('\0');
    return  __vprintert ((putnF *)strputn, &bufP, fmt, 0, 0, ap);
}

