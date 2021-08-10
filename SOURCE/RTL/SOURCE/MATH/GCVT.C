/*------------------------------------------------------------------------
 * filename - gcvt.c
 *
 * function(s)
 *        _gcvt - converts floating-point number to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdlib.h>
#include <_printf.h>

/*--------------------------------------------------------------------------*

Name            _gcvt - converts floating-point number to a string

Usage           char *_gcvt(double value, int ndec, char *bufP);

Prototype in    stdlib.h

Description     _gcvt converts  value to a  null-terminated ASCII string  in
                bufP and returns a pointer  to bufP. It attempts to produce
                ndec  significant digits  in FORTRAN  F-format if possible;
                otherwise,  E-format  (ready  for  printing)  is  returned.
                Trailing zeros may be suppressed.

Return value    _gcvt returns the string pointed to by bufP.

*---------------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC _gcvt (double value, int ndec, char *bufP )
{
    __realcvt (&value, ndec, bufP, 'g', 0, F_8byteFloat);
    return bufP;
}
