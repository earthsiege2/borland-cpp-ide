/*-----------------------------------------------------------------------*
 * filename - vfprintf.c
 *
 * function(s)
 *        vfprintf - sends formatted output to a stream
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

Name            vfprintf - sends formatted output to a stream

Usage           #include <stdio.h>
                #include <stdarg.h>
                int vfprintf(FILE *stream, const char *format, va_list param);

Prototype in    stdio.h
                stdarg.h

Description     see printf

*---------------------------------------------------------------------*/
int cdecl _FARFUNC vfprintf( FILE *F, const char *fmt, va_list ap )
  {
  return( __vprinter( (putnF *)__fputn, F, fmt, (void _ss *) ap ) );
  }

