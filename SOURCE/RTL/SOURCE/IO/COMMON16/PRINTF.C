/*-----------------------------------------------------------------------*
 * filename - printf.c
 *
 * function(s)
 *        printf - send formatted output to stdout
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stdio.h>
#include <_printf.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            printf - send formatted output to stdout

Usage           int printf(const char *format, ...);

Prototype in    stdio.h

Description     sends formatted output to stdout

Return value    the number of bytes output.  In the event of an
                error, printf returns EOF.

*---------------------------------------------------------------------*/
int _RTLENTRY _FARFUNC printf(const char *fmt, ...)
  {
  return( __vprinter ((putnF *)__fputn, stdout, fmt, (void _ss *) _va_ptr) );
  }

