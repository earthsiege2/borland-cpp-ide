/*-----------------------------------------------------------------------*
 * filename - ismbgrph.c
 *
 * function(s)
 *        _ismbcgraph -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <_locale.h>
#include <mbstring.h>
#include <windows.h>

/*------------------------------------------------------------------------*

Name            _ismbcgraph

Usage           int _RTLENTRY _EXPFUNC _ismbcgraph( unsigned int c );

Prototype in    mbstring.h

Description     _ismbcgraph returns TRUE if c is a single byte representation of
                an ASCII or Katakana printable character except a white space
*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcgraph( unsigned int c )
{

   char  CharBuffer[2];
   unsigned short CharTypeBuffer[2];

   if ( c <= 0xFF )
      return _ismbbgraph( c );

   CharBuffer[0] = (c >> 8 ) & 0xFF;
   CharBuffer[1] =  c & 0xFF;

   GetStringTypeA( __locale->handle, CT_CTYPE1, CharBuffer, 2, CharTypeBuffer);
   return ( (CharTypeBuffer[1] == 0) && ( CharTypeBuffer[0] &
                                        (C1_ALPHA|C1_UPPER|C1_LOWER|C1_DIGIT|C1_PUNCT) ) );

}

