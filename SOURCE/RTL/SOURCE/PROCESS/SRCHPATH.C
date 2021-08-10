/*-----------------------------------------------------------------------*
 * filename - srchpath.c
 *
 * function(s)
 *        searchpath   - searches the PATH environment variable
 *        wsearchpath  - searches the wide-character PATH environment variable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#ifdef _MT
#include <_thread.h>
#endif
#include <dir.h>
#include <stdlib.h>
#include <_tchar.h>

#ifdef _MT

#define pathbuf (_TCHAR *)THREAD_BUF(pathbuf,_MAX_PATH*sizeof(wchar_t))

#else

static _TCHAR pathbuf[_MAX_PATH];

#endif  /* _MT */

/*-----------------------------------------------------------------------*

Name            searchpath, wsearchpath - searches the DOS path

Usage           char *searchpath(const char *filename);
                wchar_t *searchpath(const wchar_t *filename);

Prototype in    dir.h

Description     searchpath simply calls _searchenv to search the current
                directory and PATH for filename.

Return value    A pointer to the filename string if the file is successfully
                found; this string is stored in a static array that is
                overwritten with each call.  NULL is returned if the
                file is not found.

*------------------------------------------------------------------------*/

_TCHAR * _RTLENTRYF _EXPFUNC _tsearchpath(const _TCHAR *file)
{
    _TCHAR *buf = pathbuf;

    _tsearchenv(file, _TEXT("PATH"), buf);
    return (buf[0] == _TEXT('\0') ? NULL : buf);
}
