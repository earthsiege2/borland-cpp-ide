/*---------------------------------------------------------------------------
 * filename - createmp.c
 *
 * function(s)
 *        creattemp  - creates a new file
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <dos.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

/*--------------------------------------------------------------------------*

Name            creattemp - creates a new file

Usage           int creattemp(const char *filename, int attrib);

Prototype in    io.h

Description     similar to _rtl_creat except that the filename is a path
                name ending with a backslash (\).  A unique file name
                is selected in the directory given by filename.  The
                newly created file name is stored in the filename string
                supplied.  The file is not automatically deleted when the
                program terminates.

                The file is opened in the default translation mode
                specified by the external variable _fmode.

Return value    same as _rtl_creat

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC creattemp (char *pathP, int attr)
{
    struct dostime_t    t;
    char *              name;
    char *              s;
    char *              d;
    int                 handle;
    int                 i;
    char                c;

    name = pathP + strlen(pathP);   /* point to end of path */

    for (;;)
    {
        /* Append a string to the supplied path that is the current
         * time (hours, minutes, secs, and hundredths) in hexadecimal.
         * This is the same procedure that MS-DOS function 5A uses.
         */
        _dos_gettime(&t);
        for (i = 0, s = (char *)&t.hour, d = name; i < 4; i++, s++)
        {
            c = (*s >> 4) & 0x0f;
            *d++ = c < 10 ? c + '0' : c - 10 + 'a';
            c = *s & 0x0f;
            *d++ = c < 10 ? c + '0' : c - 10 + 'a';
        }
        *d++ = '\0';        /* null-terminate the name */

        /* Try to create the file, but only if it doesn't already exist.
         */
        if (_dos_creatnew(pathP, attr, &handle) == 0)
            break;
        if (errno != EEXIST)
            return (-1);

        /* File already exists.  Just keep trying with a different
         * time-of-day until we no longer get this error (either
         * a successful open, or an error other than EEXIST).
         */
    }
    _openfd[handle] = _FMODE & (O_TEXT | O_BINARY);
    return (handle);
}
