/*-----------------------------------------------------------------------*
 * filename - wcscat.c
 *
 * function(s)
 *        wcscat - appends one wide-character string to another
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $ */

#include <string.h>

/*---------------------------------------------------------------------*

Name            wcscat - appends one wide-character string to another

Usage           wchar_t *wcscat(wchar_t *dest, const wchar_t *src);

Prototype in    string.h

Description     wcscat appends a copy of src to the end of dest. The
                length of the resulting string is wcslen(dest) +
                wcslen(src).

Return value    returns a pointer to the dest string

*---------------------------------------------------------------------*/

wchar_t *	_RTLENTRYF _EXPFUNC wcscat(wchar_t *__dest, const wchar_t *__src)
{
	size_t len;

	len = wcslen (__dest);
	wcscpy (__dest+len, __src);
	return __dest;
}

