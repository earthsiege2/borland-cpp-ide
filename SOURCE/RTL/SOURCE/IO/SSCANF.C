/*-----------------------------------------------------------------------*
 * filename - sscanf.c
 *
 * function(s)
 *        Get     - gets a character from a string
 *        UnGet   - ungets a character from a string
 *        sscanf  - gets formatted input from a string
 *        vsscanf - gets formatted input from a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4 $        */

#include <stdarg.h>
#include <stdio.h>
#include <_scanf.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            Get - gets a character from a string

Usage           static  int    Get(char **strPP)

Description     gets a character from a string

Return value    the character read or -1 of the null character

*---------------------------------------------------------------------*/

static int Get(_TCHAR **strPP)
{
    register    _TUCHAR  c;

    return  ((c = *((*strPP) ++)) == _TEXT('\0')) ? _TEOF : c;
}


/*---------------------------------------------------------------------*

Name            UnGet - ungets a character from a string

Usage           static  void    UnGet(char c, char **strPP)

Description     decrements a character pointer

*---------------------------------------------------------------------*/

#pragma warn -par

static void UnGet(_TCHAR c, _TCHAR **strPP)
{
    --(*strPP);         /* ignore c, we don't allow the string to change */
}

#pragma warn .par

/*---------------------------------------------------------------------*

Name            sscanf - gets formatted input from a string

Usage           int sscanf(const char *string,
                    const char *format[, argument ...])

Prototype in    stdio.h

Description     gets formatted input from a string

Return value    number of fields scanned and stored.  sscanf returns EOF
        if an attempt is made to read at end-of-string

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _stscanf(const _TCHAR *buf, const _TCHAR *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    ret =  _scannert (
        (int (*)(void *))Get,
        (void (*)(int, void *))UnGet,
        &buf,
        fmt,
        ap
        );
    va_end(ap);
    return (ret);
}


/*---------------------------------------------------------------------*

Name        vsscanf - gets formatted input from a string

Usage       int vsscanf(const char *string,const char *format,
                va_list argp)

Prototype in    stdio.h

Description gets formatted input from a string

Return value    number of fields scanned and stored.  vsscanf returns EOF
        if an attempt is made to read at end-of-string

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _vstscanf(const _TCHAR *buf, const _TCHAR *fmt, va_list ap)
{
    return  _scannert(
        (int (*)(void *))Get,
        (void (*)(int, void *))UnGet,
        &buf,
        fmt,
        ap
        );
}
