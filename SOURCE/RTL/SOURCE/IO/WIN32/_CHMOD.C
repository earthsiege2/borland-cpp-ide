/*---------------------------------------------------------------------------
 * filename - chmod.c
 *
 * function(s)
 *        _rtl_chmod - changes access mode of file
 *        _chmod - changes access mode of file ( obsolete )
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <io.h>
#include <_io.h>
#include <stdarg.h>

/*--------------------------------------------------------------------------*

Name            _rtl_chmod - changes access mode of file

Usage           int _rtl_chmod(const char *filename, int func [,int attrib]);

Prototype in    io.h

Description     may either fetch or set the NT file attributes.
                If func is 0, the function returns the current
                attributes for the file.  If func is 1, the
                attribute is set to attrib.  The file must not
                currently be opened by any process, including the
                caller.

Return value    success : returns the file attribute word
                failure : -1 and errno is set to either

                        ENOENT  Path or file name not found
                        EACCESS Permission denied

*---------------------------------------------------------------------------*/

int  _RTLENTRY _EXPFUNC _rtl_chmod (const char *filename, int func, ...)
{
    DWORD attr;

    if (func == 1)      /* set attributes */
    {
        va_list ap;

        /* Get optional attrib parameter.
         */
        va_start(ap, func);
        attr = va_arg(ap, DWORD);
        va_end(ap);

        /* Set the new file attributes.
         */
        if (SetFileAttributes((LPSTR)filename, attr) == FALSE)
            return (__NTerror());
    }
    else                /* get attributes */
    {
        if ((attr = GetFileAttributes((LPSTR)filename)) == (DWORD)-1)
            return (__NTerror());
    }

    return ((int)attr);
}

/*---------------------------------------------------------------------------*/

int  _RTLENTRY _EXPFUNC _chmod (const char *filename, int func, ...)
{
    DWORD attr;

    if (func == 1)      /* set attributes */
    {
        va_list ap;

        /* Get optional attrib parameter.
         */
        va_start(ap, func);
        attr = va_arg(ap, DWORD);
        va_end(ap);

        /* Set the new file attributes.
         */
        if (SetFileAttributes((LPSTR)filename, attr) == FALSE)
            return (__NTerror());
    }
    else                /* get attributes */
    {
        if ((attr = GetFileAttributes((LPSTR)filename)) == (DWORD)-1)
            return (__NTerror());
    }

    return ((int)attr);
}



