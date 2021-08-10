/*-----------------------------------------------------------------------*
 * filename - srchpath.c
 *
 * function(s)
 *        searchpath   - searches the PATH environment variable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef _MT
#include <_thread.h>
#endif
#include <dir.h>
#include <stdlib.h>

#ifdef _MT

#define pathbuf (char *)THREAD_BUF(pathbuf,_MAX_PATH)

#else

static char pathbuf[_MAX_PATH];

#endif  /* _MT */

/*-----------------------------------------------------------------------*

Name            searchpath - searches the DOS path

Usage           char *searchpath(const char *filename);

Prototype in    dir.h

Description     searchpath simply calls _searchenv to search the current
                directory and PATH for filename.

Return value    A pointer to the filename string if the file is successfully
                found; this string is stored in a static array that is
                overwritten with each call.  NULL is returned if the
                file is not found.

*------------------------------------------------------------------------*/

char * _RTLENTRYF searchpath(const char *file)
{
    char *buf = pathbuf;

    _searchenv(file, "PATH", buf);
    return (buf[0] == '\0' ? NULL : buf);
}
