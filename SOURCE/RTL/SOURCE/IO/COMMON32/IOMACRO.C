/*---------------------------------------------------------------------------
 * filename - iomacro.c
 *
 * function(s)     - replacements for macros in stdio.h
 *    getc
 *    getchar
 *    putc
 *    putchar
 *    feof
 *    ferror
 *    fileno
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>

int (_RTLENTRY _EXPFUNC getc)( FILE *fp )
  {
  return( fgetc( fp ) );
  }

int (_RTLENTRY _EXPFUNC getchar)( void )
  {
  return( getchar() );
  }

int (_RTLENTRY _EXPFUNC putc)( const int c, FILE *fp )
  {
  return( fputc( c, fp ) );
  }

int (_RTLENTRY _EXPFUNC putchar)( const int c )
  {
  return( putchar( c ) );
  }

int (_RTLENTRY _EXPFUNC feof)( FILE *fp )
  {
  return( feof( fp ) );
  }

int (_RTLENTRY _EXPFUNC ferror)( FILE *fp )
  {
  return( ferror( fp ) );
  }

int (_RTLENTRY _EXPFUNC fileno)( FILE *fp )
  {
  return( fileno( fp ) );
  }
