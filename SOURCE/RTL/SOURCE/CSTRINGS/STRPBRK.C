/*-----------------------------------------------------------------------*
 * filename - strpbrk.c
 *
 * function(s)
 *        strpbrk, wspbrk - scans an ASCII/wide_character  string for the first
 *                  occurrence of any ASCII/wide-character a given set
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

//#pragma inline

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strpbrk, wcspbrk - scans an ASCII/wide_character string for
			the first occurrence of any ASCII/wide-character
			in a given set

Usage           char *strpbrk(const char *str1, const char *str2);
		wchar_t *wcspbrk(const wchar_t *str1, const wchar_t *str2);

Prototype in    string.h

Description     strpbrk and wcspbrk scan an ASCII/wide-character string, str1,
		for the first occurrence of any character appearing in str2.

Return value    strpbrk and wcspbrk return a pointer to the first occurrence of
		any of the characters in str2; if none of the str2 characters
		occurs in str1, it returns NULL.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tcspbrk(const _TCHAR *s1, const _TCHAR *s2)
{
     register const _TCHAR *srchs2;

     while (*s1)
     {
             for (srchs2 = s2; *srchs2; srchs2++)
                     if (*s1 == *srchs2) return((_TCHAR *)s1);
             s1++;
     }
     return (0);
}
