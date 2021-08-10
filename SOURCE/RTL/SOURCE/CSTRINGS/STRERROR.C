/*-----------------------------------------------------------------------*
 * filename - strerror.c
 *
 * function(s)
 *    strerror  - returns pointer to error message string
 *    _strerror - builds a customized error message
 *    _maperror - internal function
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#ifdef _MT
#include <_thread.h>
#endif
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* Local buffer for constructed error messages:
 *
 * 94 bytes  Max User string
 *  2 bytes  semicolon and space
 * 64 bytes  Max sys_errlist string
 *  2 bytes  \n and NULL terminator
 */
#define STRBUFSIZE (94 + 2 + 64 + 1)

#ifdef _MT

#define strbuf (char *)THREAD_BUF(strbuf,STRBUFSIZE)

#else

static char strbuf[STRBUFSIZE];

#endif

/*---------------------------------------------------------------------*

Name            _maperror - builds a customized error message

Usage           char *_maperror(int errnum, const char *str);

Prototype in    local

Description     _maperror is a helper function for _strerror and strerror
                that is used to construct an error message; it returns a
                pointer to a null-terminated string containing an error message.

                If str is NULL, the return value contains the system error
                message corresponding to the error code errnum; this string
                is null-terminated.

                If str is not NULL, the return value contains str (the
                customized error message), a colon, a space, the system error
                message corresponding to the error code errnum, and a newline.

                The length of str should be 94 characters or less.

Return value    _maperror returns a pointer to a constructed error
                string. The error message string is constructed in a static
                buffer that is overwritten with each call to _maperror.

*---------------------------------------------------------------------*/

static char * _maperror(int errnum, const char *s)
{
    char    *cp;
    char    *buf;

    if (errnum < _sys_nerr && errnum >= 0)
        cp = _sys_errlist[errnum];
    else
        cp = "Unknown error";
    buf = strbuf;
    if (s && *s)
    {
        strcpy(buf, s);
        strcat(buf, ": ");
    }
    else
        buf[0] = '\0';
    strcat(buf,cp);
    strcat(buf,"\n");
    return buf;
}


/*---------------------------------------------------------------------*

Name            _strerror - builds a customized error message

Usage           char *_strerror(const char *str);

Prototype in    string.h

Description     _strerror allows you to generate customized error
                messages; it returns a pointer to a null-terminated string
                containing an error message.

                If str is NULL, the return value contains the most recently
                generated system error message; this string is null-terminated.

                If str is not NULL, the return value contains str (your
                customized error message), a colon, a space, the most recently
                generated system error message, and a newline.

                The length of str should be 94 characters or less.

                _strerror is different from perror in that it does not print
                error messages.

                For accurate error handling, _strerror should be called as
                soon as a library routine generates an error return.

Return value    _strerror returns a pointer to a constructed error
                string. The error message string is constructed in a static
                buffer that is overwritten with each call to _strerror
                or strerror.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC _strerror(const char *s)
{
    return _maperror(errno, s);
}

/*---------------------------------------------------------------------*

Name            strerror - returns pointer to error message string

Usage           char *strerror(int errnum);

Prototype in    string.h

Description     strerror takes an int parameter errnum, and returns a
                pointer to an error messae string associated with errnum.

Return value    _strerror returns a pointer to a constructed error
                string. The error message string is constructed in a static
                buffer that is overwritten with each call to strerror
                or _strerror.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC strerror(int errnum)
{
    return  _maperror(errnum, NULL);
}
