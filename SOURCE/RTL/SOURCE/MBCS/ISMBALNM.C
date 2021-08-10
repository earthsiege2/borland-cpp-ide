/*-----------------------------------------------------------------------*
 * filename - ismbalnm.c
 *
 * function(s)
 *        _ismbcalnum -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <_locale.h>
#include <mbctype.h>
#include <mbstring.h>
#include <windows.h>

/*------------------------------------------------------------------------*

Name            _ismbcalnum

Usage           int _RTLENTRY _EXPFUNC _ismbcalnum( unsigned int c );

Prototype in    mbstring.h

Description     _ismbcalnum returns TRUE if c is a single byte representation of
                an ASCII English character
*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcalnum( unsigned int c )
{

   char  CharBuffer[2];
   unsigned short CharTypeBuffer[2];

   if ( c <= 0xFF )
      return _ismbbalnum( c );

   CharBuffer[0] = (c >> 8 ) & 0xFF;
   CharBuffer[1] =  c & 0xFF;

   GetStringTypeA( __locale->handle, CT_CTYPE1, CharBuffer, 2, CharTypeBuffer);
   return ( (CharTypeBuffer[1] == 0) && ( CharTypeBuffer[0] &
                                        (C1_ALPHA|C1_UPPER|C1_LOWER|C1_DIGIT)));

}

