/*------------------------------------------------------------------------
 * filename - assert.c
 *
 * function(s)
 *        _vstrcat    - concatenates a variable list of strings
 *        _assert     - displays error message and aborts
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <_printf.h>
#include <_io.h>

/*---------------------------------------------------------------------*

Name            _vstrcat - concatenates a variable list of strings

Usage           static void _vstrcat (char *buf, int maxlen, ...);

Prototype in    local

Description     This function is used by _assert to concatenate a
                large number of strings.  The concatenated string is
                stored in buf; no more than maxlen characters are stored,
                including a null terminator (which is always appended).
                The pointers to the strings appear after maxlen
                in the call, and the last string pointer must be NULL.

Return value    None.

*---------------------------------------------------------------------*/

static void _vstrcat(char *buf, int maxlen, ...)
{
    int rem;
    va_list ap;
    char *s;

    buf[0] = '\0';          /* assume buffer can hold at least the null */
    va_start(ap, maxlen);
    while ((s = va_arg(ap, char *)) != NULL)
    {
        /* Calculate the remaining number of bytes in the buffer,
         * and exit if it's gotten too small to store even a null..
         */
        if ((rem = maxlen - strlen(buf) - 1) <= 0)
            break;
        strncat(buf, s, rem);
    }
    va_end(ap);
}

/*---------------------------------------------------------------------*

Name            _assert - displays error message and aborts

Usage           void _assert (char *cond, char *file, int line);

Prototype in    assert.h

Description     This function is used by the assert macro to display
                an error message and abort the program.  The message
                is of the form

                    Assertion failed: <cond>, file <file>, line <line>

                where <cond> and <file> are the strings pointed to by
                cond and file, and <line> is line converted to decimal.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC
_assert(char *cond, char *file, int line)
{
    static char buffer[256];

    _vstrcat(buffer, sizeof(buffer) - 10,
             "Assertion failed: ", cond, ", file ", file, ", line ", NULL);
    __utoa((unsigned)line, &buffer[strlen(buffer)]);
    _ErrorMessage(buffer);
    abort();
}
