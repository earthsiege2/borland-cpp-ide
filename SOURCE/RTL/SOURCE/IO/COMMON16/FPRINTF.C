/*-----------------------------------------------------------------------*
 * filename - fprintf.c
 *
 * function(s)
 *        fprintf - sends formatted output to a stream
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
#include <_stdio.h>
#include <_printf.h>

/*---------------------------------------------------------------------*

Name            fprintf - sends formatted output to a stream

Usage           int fprintf(FILE *stream, const char *format [,argument, ...]);

Prototype in    stdio.h

Description     member of the printf family.  fprintf send its output
                to the named stream.

Return value    success : the number of bytes output.
                error : EOF

*------------------------------------------------------------------------*/
int _RTLENTRY _FARFUNC fprintf (FILE *F, const char *fmt, ...)
  {
  return( __vprinter ((putnF *)__fputn, F, fmt, (void _ss *) _va_ptr ) );
  }
