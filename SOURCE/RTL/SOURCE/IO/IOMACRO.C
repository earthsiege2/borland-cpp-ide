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
 *    _fileno
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdio.h>
#include <_tchar.h>

_TINT (_RTLENTRY _EXPFUNC _gettc)( FILE *fp )
  {
  return( _fgettc( fp ) );
  }

_TINT (_RTLENTRY _EXPFUNC _gettchar)( void )
  {
  return( _gettchar() );
  }

_TINT (_RTLENTRY _EXPFUNC _puttc)( const _TINT c, FILE *fp )
  {
  return( _fputtc( c, fp ) );
  }

_TINT (_RTLENTRY _EXPFUNC _puttchar)( const _TINT c )
  {
  return( _puttchar( c ) );
  }

#ifndef _UNICODE

int (_RTLENTRY _EXPFUNC feof)( FILE *fp )
  {
  return( feof( fp ) );
  }

int (_RTLENTRY _EXPFUNC ferror)( FILE *fp )
  {
  return( ferror( fp ) );
  }

int (_RTLENTRY _EXPFUNC _fileno)( FILE *fp )
  {
  return( _fileno( fp ) );
  }

#endif  // _UNICODE
