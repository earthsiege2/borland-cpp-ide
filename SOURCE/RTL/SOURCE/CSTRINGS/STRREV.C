/*-----------------------------------------------------------------------*
 * filename - strrev.c
 *
 * function(s)
 *        strrev, _wcsrev - reverses an ASCII/wide-character string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strrev, _wcsrev - reverses an ASCII/wide-character string

Usage           char *strrev(char * str);
		wchar_t *_wcsrev(wchar_t * str);

Prototype in    string.h

Description     strrev and _wcsrev reverse all ASCII/wide-characters in a
		an ASCII/wide-character string (except the terminating null
		character).

Return value    strrev and _wcsrev return a pointer to the reversed string.
		There is no error return.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tcsrev(_TCHAR *str)
{
     _TCHAR *p, *q, r;

     if (!*str)
        return str;
     p = str + _tcslen(str) - 1;
     q = str;
     while( p > q )
     {
         if (*p == *q)
         {
             --p;
             ++q;
         }
         else
         {
             r = *p;
             *p-- = *q;
             *q++ = r;
         }
     }
     return(str);
}
