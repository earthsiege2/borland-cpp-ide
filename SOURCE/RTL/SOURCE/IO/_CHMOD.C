/*---------------------------------------------------------------------------
 * filename - _chmod.c
 *
 * function(s)
 *        _rtl_chmod - changes access mode of file
 *        _chmod - changes access mode of file ( obsolete )
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>

#include <io.h>
#include <_io.h>
#include <stdarg.h>
#include <tchar.h>

/*--------------------------------------------------------------------------*

Name            _trtl_chmod used as _rtl_chmod and _wrtl_chmod
                _rtl_chmod  - changes access mode of file
                _wrtl_chmod - changes access mode of file

Usage           int _rtl_chmod(const char *filename, int func [,int attrib]);
                int _wrtl_chmod(const wchar_t *filename, int func [,int attrib]);

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

int  _RTLENTRY _EXPFUNC _trtl_chmod (const _TCHAR *filename, int func, ...)
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
        if (SetFileAttributes(filename, attr) == FALSE)
            return (__NTerror());
    }
    else                /* get attributes */
    {
        if ((attr = GetFileAttributes(filename)) == (DWORD)-1)
            return (__NTerror());
    }

    return ((int)attr);
}

/*---------------------------------------------------------------------------*/

#ifndef _UNICODE
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
#endif  /* _UNICODE */



