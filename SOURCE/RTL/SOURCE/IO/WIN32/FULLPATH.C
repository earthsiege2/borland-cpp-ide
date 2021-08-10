/*-----------------------------------------------------------------------*
 * filename - fullpath.c
 *
 * function(s)
 *        _fullpath - make an absolute path name from a relative path name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------------------*

Name            _fullpath - makes new file name

Usage           #include <dir.h>
                char *_fullpath(char *buffer, const char * pathname,
                                size_t maxlen);

Prototype in    stdlib.h

Description     _fullpath converts the relative path name name 'pathname'
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

char * _RTLENTRYF _EXPFUNC
_fullpath(char *buffer, const char *pathname, size_t maxlen)
{
    char *tempbuf;
    char *lastpart;
    int len;

    /* Allocate a temporary buffer to hold the fully qualified path.
     */
    if ((tempbuf = malloc(_MAX_PATH)) == NULL)
        return (NULL);

    /* Use wonderful new NT function to do all the hard work.
     */
    len = (int)GetFullPathName((char *)pathname,_MAX_PATH, tempbuf, &lastpart);
    if (len == 0 || len >= _MAX_PATH)
    {
        free(tempbuf);
        return (NULL);
    }

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
            strcpy(buffer,tempbuf);
            free(tempbuf);
            return (buffer);
        }
    }
    else
        return (realloc(tempbuf,len));          /* shrink the buffer */
}
