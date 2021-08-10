/*-----------------------------------------------------------------------*
 * filename - snprntf.c
 *
 * function(s)
 *    strputn   - copies an n element string
 *    snprintf  - sends formatted output to a string
 *    vsnprintf - sends formatted output to a string
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
#include <mem.h>
#include <string.h>
#include <_printf.h>
#include <_tchar.h>
/*---------------------------------------------------------------------*

Name            strputn - copies an n element string

Usage           static size_t strputn(char *S, size_t n, char **bufPP,
                                      int eos_flag)

Description     copies n bytes from block pointed to by S to the block
                pointed to by bufPP.  bufPP is incremented by n.

Return value    returns the value n.

*---------------------------------------------------------------------*/

static size_t strputn(_TCHAR *S, size_t n, _TCHAR **bufPP, int eos_flag)
{
    memcpy (*bufPP, S, (n * sizeof (_TCHAR)));
    if (eos_flag)
        *(*bufPP += n) = _TEXT('\0');
    return n;
}


/*---------------------------------------------------------------------*

Name            snprintf - sends formatted output to a string

Usage           int snprintf(char *string, size_t nsize,
                             const char *format[, argument, ...]);

Prototype in    stdio.h

Description     sends formatted output to a string (of specified max length)

Return value    number of bytes output
                if return value < nsize, then all of the chars have been
                written (including the null char: eos).
                if return value == nsize, then nsize chars are written with no
                eos null char.
                if return value > nsize, then only nsize chars are written
                again, with no null eos.
                If nsize is 0, then the string will not be written to (and may
                be NULL)

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _sntprintf(_TCHAR *bufP, size_t nsize,
                                  const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    if (nsize >= 1)
        *bufP = _TEXT('\0');

    va_start(ap,fmt);
    ret = __vprintert ((putnF *)strputn, &bufP, fmt, 1, nsize, ap);
    va_end(ap);
    return (ret);
}

/*---------------------------------------------------------------------*

Name            vsnprintf - sends formatted output to a string

Usage           int vsnprintf(char *string, size_t nsize, const char *format,
                              va_list param);

Prototype in    stdio.h

Description     sends formatted output to a string (of specified max length)

Return value    number of bytes output
                if return value < nsize, then all of the chars have been
                written (including the null char: eos).
                if return value == nsize, then nsize chars are written with no
                eos null char.
                if return value > nsize, then only nsize chars are written
                again, with no null eos.
                If nsize is 0, then the string will not be written to (and may
                be NULL)

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _vsntprintf(_TCHAR *bufP, size_t nsize,
                                   const _TCHAR *fmt, va_list ap)
{
    if (nsize >= 1)
        *bufP = _TEXT('\0');

    return  __vprintert ((putnF *)strputn, &bufP, fmt, 1, nsize, ap);
}


/*---------------------------------------------------------------------*

Name            _snprintf - sends formatted output to a string

Usage           int _snprintf(char *string, size_t nsize,
                              const char *format[, argument, ...]);

Prototype in    stdio.h


Description     sends formatted output to a string (of specified max length)
                These are Microsoft compatible _snprintf & _snprintfw
                functions

Return value    number of bytes output (or -1 if is nsize too small)
                if return value < nsize, then all of the chars have been
                written (including the null char: eos).
                if return value == nsize, then nsize chars are written with no
                eos null char.
                if return value == -1, then only nsize chars are written,
                again, with no null eos.
                If nsize is 0, then the string will not be written to (and may
                be NULL)

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC __sntprintf(_TCHAR *bufP, size_t nsize,
                                   const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    if (nsize >= 1)
        *bufP = _TEXT('\0');

    va_start(ap,fmt);
    ret = __vprintert ((putnF *)strputn, &bufP, fmt, 1, nsize, ap);
    va_end(ap);

    if ((size_t)ret > nsize)
      ret = -1;

    return (ret);
}

/*---------------------------------------------------------------------*

Name            _vsnprintf - sends formatted output to a string

Usage           int _vsnprintf(char *string, size_t nsize, const char *format,
                               va_list param);

Prototype in    stdio.h

Description     sends formatted output to a string (of specified max length)
                These are Microsoft compatible _vsnprintf & _vsnprintfw
                functions

Return value    number of bytes output (or -1 if is nsize too small)
                if return value < nsize, then all of the chars have been
                written (including the null char: eos).
                if return value == nsize, then nsize chars are written with no
                eos null char.
                if return value == -1, then only nsize chars are written,
                again, with no null eos.
                If nsize is 0, then the string will not be written to (and may
                be NULL)

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC __vsntprintf(_TCHAR *bufP, size_t nsize,
                                   const _TCHAR *fmt, va_list ap)
{
    int ret;

    if (nsize >= 1)
        *bufP = _TEXT('\0');

    ret = __vprintert ((putnF *)strputn, &bufP, fmt, 1, nsize, ap);
    if ((size_t)ret > nsize)
      ret = -1;

    return (ret);
}
