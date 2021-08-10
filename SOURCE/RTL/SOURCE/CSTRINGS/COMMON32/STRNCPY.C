/*-----------------------------------------------------------------------*
 * filename - strncpy.c
 *
 * function(s)
 *        strncpy - copy string src to string dest
 *        wcsncpy - copy wide-character string src to wide-character string dest
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#include <string.h>
#include <tchar.h>
#include <mem.h>

/*-----------------------------------------------------------------------*

Name            strncpy, wcsncpy - copy string src to string dest

Usage           char *strncpy (char *dest, const char *src, size_t maxlen);
		wchar_t *wcsncpy (wchar_t *dest, const wchar_t *src, size_t maxlen);

Prototype in    string.h

Description     Copy the ASCIIZ/wide-character string *src to the buffer *dest.
		It is the callers responsibility to ensure that the dest buffer
                is large enough to contain the string, and to guard against
                supplying NULL arguments.

                The length of source copied will be trimmed to maxlen
                characters, including terminator.  If *src is shorter than
                maxlen, then the target buffer is zero filled up to the
                maxlen.

                If the source needs to be truncated then the target is NOT
                zero terminated.

Return value    strncpy and wcsncpy return dest.

*------------------------------------------------------------------------*/

#ifdef strncpy
#  undef strncpy
#  define INTRINSIC
#endif

_TCHAR * _RTLENTRYF _EXPFUNC _tcsncpy(_TCHAR *dest, const _TCHAR *src, size_t maxlen)
{
#ifdef INTRINSIC
    return __strncpy__(dest, src, maxlen);
#else
    size_t len;

    len = _tcslen(src);
    if (len > maxlen)
        memcpy(dest,src,maxlen * sizeof(_TCHAR));
    else
    {
        memcpy(dest,src,len * sizeof(_TCHAR));
        _tmemset(dest+len,0,maxlen-len);
    }
    return (dest);
#endif
}
