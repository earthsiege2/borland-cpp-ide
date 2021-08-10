/*-----------------------------------------------------------------------*
 * filename - ismbpunc.c
 *
 * function(s)
 *        _ismbpunc -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <_locale.h>
#include <mbstring.h>
#include <windows.h>

/*------------------------------------------------------------------------*

Name            _ismbpunc

Usage           int _RTLENTRY _EXPFUNC _ismbcpunct( unsigned int c );

Prototype in    mbstring.h

Description     _ismbcpunct returns TRUE if c is a single byte representation of
                an ASCII or Katakana punctuation  character
*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcpunct( unsigned int c )
{

   char  CharBuffer[2];
   unsigned short CharTypeBuffer[2];

   if ( c <= 0xFF )
      return _ismbbpunct( c );

   CharBuffer[0] = (c >> 8 ) & 0xFF;
   CharBuffer[1] =  c & 0xFF;

   GetStringTypeA( __locale->handle, CT_CTYPE1, CharBuffer, 2, CharTypeBuffer);
   return ( (CharTypeBuffer[1] == 0) && ( CharTypeBuffer[0] &  C1_PUNCT ) );

}

