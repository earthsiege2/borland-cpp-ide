/*---------------------------------------------------------------------------
 * filename - is.c
 *
 * function(s)     - replacements for macros in ctype.h, stdio.h
 *    isalnum
 *    isascii
 *    isalpha
 *    iscntrl
 *    isdigit
 *    isgraph
 *    islower
 *    isprint
 *    ispunct
 *    isspace
 *    isupper
 *    isxdigit
 *    getc
 *    getchar
 *    putc
 *    putchar
 *    feof
 *    ferror
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <_locale.h>


int _RTLENTRY _EXPFUNC __isctype( int c, int type )
{
    if ( c == EOF )
        return( 0 );

    return( (_pLocale->pCtype[ (((c) & 0x00ff) +1) ] & (type)) );
}

int (_RTLENTRY _EXPFUNC isalnum)( int c )
{
    return( __isctype( c, _IS_ALNUM ) );
}

int (_RTLENTRY _EXPFUNC isascii)( int c )
  {
  return( isascii( c ) );
  }

int (_RTLENTRY _EXPFUNC isalpha)( int c )
{
    return( __isctype( c, _IS_ALPHA ) );
}

int (_RTLENTRY _EXPFUNC iscntrl)( int c )
{
    return( __isctype( c, _IS_CTL ) );
}

int (_RTLENTRY _EXPFUNC isdigit)( int c )
{
    return( __isctype( c, _IS_DIG ) );
}

int (_RTLENTRY _EXPFUNC isgraph)( int c )
{
    return( __isctype( c, _IS_GRAPH ) );
}

int (_RTLENTRY _EXPFUNC islower)( int c )
{
    return( __isctype( c, _IS_LOW ) );
}

int (_RTLENTRY _EXPFUNC isprint)( int c )
{
    return( __isctype( c, (_IS_GRAPH) ) || (c & 0x00ff) == ' ' );
}

int (_RTLENTRY _EXPFUNC ispunct)( int c )
{
    return( __isctype( c, _IS_PUN ) );
}

int (_RTLENTRY _EXPFUNC isspace)( int c )
{
    return( __isctype( c, _IS_SP ) );
}

int (_RTLENTRY _EXPFUNC isupper)( int c )
{
    return( __isctype( c, _IS_UPP ) );
}

int (_RTLENTRY _EXPFUNC isxdigit)( int c )
{
    return( __isctype( c, _IS_HEX ) );
}

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
