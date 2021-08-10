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
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#pragma inline
#include <stdio.h>

int (getc)( FILE *fp )
  {
  return( getc( fp ) );
  }

int (getchar)( void )
  {
  return( getchar() );
  }

int (putchar)( const int c )
  {
  return( putchar( c ) );
  }

int (putc)( const int c, FILE *fp )
  {
  return( putc( c, fp ) );
  }

int (feof)( FILE *fp )
  {
  return( feof( fp ) );
  }

int (ferror)( FILE *fp )
  {
  return( ferror( fp ) );
  }
