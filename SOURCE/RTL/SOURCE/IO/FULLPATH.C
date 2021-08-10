/*-----------------------------------------------------------------------*
 * filename - fullpath.c
 *
 * function(s)
 *        _fullpath - make an absolute path name from a relative path name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <ntbc.h>

#include <stdlib.h>
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _tfullpath used as _fullpath and _wfullpath
                _fullpath  - makes new file name
                _wfullpath - makes new wide file name

Usage           #include <dir.h>
                char *_fullpath(char *buffer, const char * pathname,
                                size_t maxlen);
                char *_wfullpath(wchar_t *buffer, const wchar_t * pathname,
                                size_t maxlen);

Prototype in    stdlib.h

Description     Converts the relative path name name 'pathname'
                to a fully qualified pathname, stored in 'buffer'.  The
                relative path can contain ".\" and "..".

                The maximum size of the supplied buffer is 'maxlen'.
                If the fully qualified path is longer than 'maxlen',
                NULL is returned.  The buffer should be at least _MAX_PATH
                bytes long (this constant is defined in stdlib.h).

                If 'buffer' is NULL, a buffer to store the fully qualified
                path is allocated and is returned.  The calling program
                must free this buffer with free() when it is no longer needed.

                If the pathname does not specify a disk drive, the current
                drive is used.

Return value    A pointer to the buffer containing the fully qualified
                path is returned.  If there is an error, NULL is returned.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRYF _EXPFUNC
_tfullpath(_TCHAR *buffer, const _TCHAR *pathname, size_t maxlen)
{
    _TCHAR *tempbuf;
    _TCHAR *lastpart;
    size_t len;

    /* Allocate a temporary buffer to hold the fully qualified path.
     */
    if ((tempbuf = malloc(_MAX_PATH * sizeof(_TCHAR))) == NULL)
        return (NULL);

    /* Use wonderful new NT function to do all the hard work.
     */
    len = (size_t)GetFullPathName((_TCHAR *)pathname,_MAX_PATH, tempbuf, &lastpart);
    if (len == 0 || len >= _MAX_PATH)
    {
        free(tempbuf);
        return (NULL);
    }

    /*  _fullpath is documented as failing for an invalid drive.
     *  If you prefer not to validate the drive then turn off the
     *  following conditional.
     */
#if 1
    if (tempbuf[1] == ':')
    {
        _TCHAR root[4];
        root[0] = tempbuf[0];
        root[1] = ':';
        root[2] = '\\';
        root[3] = 0;

        /* On error GetDriveType returns:
               0	The drive type cannot be determined.
               1	The root directory does not exist.
         */
        if (GetDriveType(root) < 2)
        {
            free(tempbuf);
            return (NULL);
        }
    }
#endif

    /* Copy the temp buffer to the user's buffer, if present.
     * Otherwise shrink the temp buffer and return a pointer to it.
     */
    len++;                                      /* add space for null */
    if (buffer != NULL)
    {
        if (len > maxlen)                       /* user buffer too small? */
        {
            free(tempbuf);
            return (NULL);
        }
        else
        {
            _tcscpy(buffer,tempbuf);
            free(tempbuf);
            return (buffer);
        }
    }
    else
        /* shrink the buffer */
        return ((_TCHAR*)realloc(tempbuf,len * sizeof(_TCHAR)));
}
