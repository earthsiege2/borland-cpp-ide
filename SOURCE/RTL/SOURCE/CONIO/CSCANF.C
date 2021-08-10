/*------------------------------------------------------------------------
 * filename - cscanf.c
 *
 * function(s)
 *        cscanf - performs formatted input from console
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <conio.h>
#include <stdio.h>
#include <_stdio.h>
#include <_scanf.h>

/*--------------------------------------------------------------------------*

Name            cscanf - performs formatted input from console

Usage           int cscanf(char *format[,argument, ...]);

Prototype in    conio.h

Description     cscanf,  as  all  ...scanf  family  functions,  scans input
                fields,  one  character  at   a  time,  and  converts  them
                according to a given format; these functions all:

                - accept  a format  string  that  determines how  the input
                fields are  to be interpreted.

                - apply  the format  string to  a variable  number of input
                fields in order to format the input

                - store  the  formatted  input  in  the  addresses given as
                arguments  after  the  format  string.


Return value    cscanf  returns  the  number  of  input fields successfully
                scanned, converted  and stored. If cscanf  attempts to read
                an end-of-file, the return value  is EOF. If no fields were
                stored, the return value is 0.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC cscanf (const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap,fmt);
    ret = _scanner ((int (*)(void *))getche,
                    (void (*)(int, void *))ungetch,
                    NULL,
                    fmt,
                    ap);
    va_end(ap);
    return (ret);
}
