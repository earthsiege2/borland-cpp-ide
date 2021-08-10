/*-----------------------------------------------------------------------*
 * filename - _wcspcpy.c
 *
 * function(s)
 *        _wcspcpy - copies one wide-character string to another
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _wcspcpy - copies one wide-character string to another,
		returning the address of the end of the destination string

Usage           wchar_t *_wcspcpy(wchar _t*destin, const wchar_t *source)

Prototype in    string.h

Description     _wcspcpy copies the wide-character string pointed to by source
                (including the terminating `\0' character) to the array
                pointed  to by destin.  The strings may not overlap, and the
                destination string destin must be large enough to receive
                the copy. _wcspcpy (a, b) is the same as wcscpy (a, b) except
                that the return values differ.  wcscpy(a, b) returns a,
                while _wcspcpy (a, b) returns a + wcslen (b).

Return value    _wcspcpy returns a pointer to the end of the string destin
                (that is, the address of the terminating null  character) rather
                than the beginning.

*---------------------------------------------------------------------*/

wchar_t *_wcspcpy(wchar_t *to, const wchar_t *from)
{
#ifdef stpcpy       /* intrinsics enabled? */
    return stpcpy(to, from);
#else
    register unsigned len;

    len = wcslen(from);
    _wmemcpy(to, from, (len+1));
    return (to+len);
#endif
}


