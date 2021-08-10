/*-----------------------------------------------------------------------*
 * filename - sprintf.c
 *
 * function(s)
 *    strputn  - copies an n element string
 *    sprintf  - sends formatted output to a string
 *    vsprintf - sends formatted output to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <mem.h>
#include <string.h>
#include <_printf.h>

/*---------------------------------------------------------------------*

Name            strputn - copies an n element string

Usage           static size_t strputn(char *S, size_t n,
                         char **bufPP)

Description     copies n bytes from block pointed to by S to the block
                pointed to by bufPP.  bufPP is incremented by n.

Return value    0

*---------------------------------------------------------------------*/

static size_t strputn(char *S, size_t n, char **bufPP)
{
    memcpy (*bufPP, S, n);
    *(*bufPP += n) = 0;
    return n;
}


/*---------------------------------------------------------------------*

Name            sprintf - sends formatted output to a string

Usage           int sprintf(char *string, const char *format[, argument, ...]);

Prototype in    stdio.h

Description     sends formatted output to a string

Return value    number of bytes output

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC sprintf(char *bufP, const char *fmt, ...)
{
    va_list ap;
    int ret;

    *bufP = 0;
    va_start(ap,fmt);
    ret = __vprinter ((putnF *)strputn, &bufP, fmt, ap);
    va_end(ap);
    return (ret);
}

/*---------------------------------------------------------------------*

Name            swprintf - sends formatted output to a string of wchar_t

Usage           int swprintf(wchar_t *string, const wchar_t *format[, argument, ...]);

Prototype in    stdio.h

Description     sends formatted output to a string of wchar_t

Return value    number of characters output

NOTE:           This function DOES NOT handle wide chars correctly yet.
                This is just to satisfy some other internal routines.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC swprintf(wchar_t *wb, const wchar_t *wf, ...)
{
    char *bufP, *fmt;
    va_list ap;
    int ret;

    bufP = (char *)wb;
    fmt  = (char *)wf;

    *bufP = 0;
    va_start(ap,fmt);
    ret = __vprinter ((putnF *)strputn, &bufP, fmt, ap);
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

int _RTLENTRY _EXPFUNC vsprintf(char *bufP, const char *fmt, va_list ap)
{
    *bufP = 0;
    return  __vprinter ((putnF *)strputn, &bufP, fmt, ap);
}

