/*---------------------------------------------------------------------------
 * filename - doscreat.c
 *
 * function(s)
 *        _dos_creat     - creates a new file or rewrites an existing one
 *        _dos_creatnew  - creates a new file
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H
#include <ntbc.h>

#include <_io.h>
#include <fcntl.h>


/*--------------------------------------------------------------------------*

Name            DosCreate - create a file

Usage           unsigned DosCreate(char *pathP, DWORD attr, int *handlep,
                    DWORD disp)

Prototype in    local

Description     Used by _dos_creat and _dos_creatnew to create
                a file.

Notes           disp is one of the following:

                     CREATE_ALWAYS  replace a file if it exists
                     CREATE_NEW     fail if file already exists

Return value    success : 0, and handle is stored at *handlep
                else    : the NT error code, and errno is set to
                          one of the following:

                        ENOENT   Path or file name not found
                        EMFILE   Too many open files
                        EACCESS  Permission denied


*---------------------------------------------------------------------------*/

static unsigned DosCreate(char *pathP, DWORD attr, int *handlep, DWORD disp)
{
    HANDLE   handle;
    SECURITY_ATTRIBUTES sec;    /* used only to set inheritance flag */
    unsigned rc, oflag;

    /* Set the inheritance flag in the security attributes.
     */
    sec.nLength = sizeof(sec);
    sec.lpSecurityDescriptor = NULL;
    sec.bInheritHandle = TRUE;

    /* Create the file.
     */
    if ((handle = CreateFile((char *)pathP, GENERIC_READ|GENERIC_WRITE,
            FILE_SHARE_READ|FILE_SHARE_WRITE, &sec, disp,
            attr, NULL)) == (HANDLE)-1)
        return (__DOSerror());

    /* Save the open flags and find free file handle table slot.
     * Save the NT file handle in the table, return the table index.
     */
    oflag = O_BINARY;
    if (__isatty((int)handle))
        oflag |= O_DEVICE;
    if ((attr & FILE_ATTRIBUTE_READONLY) == 0)
        oflag |= _O_WRITABLE;       /* fstat() uses this bit */

    _lock_all_handles();
    if ((*handlep = _get_handle((long)handle, oflag)) == -1)
    {
        __IOerror(rc = ERROR_TOO_MANY_OPEN_FILES);
        CloseHandle(handle);
        DeleteFile(pathP);
    }
    else
        rc = 0;

    _unlock_all_handles();
    return rc;
}


/*--------------------------------------------------------------------------*

Name            _dos_creat - creates a new file or rewrites an existing one.

Usage           unsigned int _dos_creat(const char *filename, unsigned attrib,
                                    int *handle );

Prototype in    dos.h

Description     _dos_creat accepts attrib, an NT attribute word.  Any
                attribute bits may be set with this call.  The file
                is always opened in binary mode.  Upon successful
                creation, the file pointer is set to the beginning
                of the file, and the file handle is copied to *handle.
                The file is opened for both reading and writing.

                The attrib argument to _dos_creat and _dos_creatnew
                can be one of the following constants (defined in dos.h):

                        _A_RDONLY   Read only attribute
                        _A_HIDDEN   Hidden file
                        _A_SYSTEM   System file

                It is assumed that these attributes are identical in
                value to the equivalent NT attributes.

                The file handle can only be used with _dos routines;
                it cannot be used with low-level I/O routines such
                as read() or _rtl_read().

Return value    success : 0
                else    : the NT error code, and errno is set to
                          one of the following:

                        ENOENT   Path or file name not found
                        EMFILE   Too many open files
                        EACCESS  Permission denied

Note            Compatible with Microsoft C.  Not the same as _creat().

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_creat (const char *pathP, unsigned attr, int *handle )
{
    return( DosCreate((char *)pathP, attr, handle, CREATE_ALWAYS) );
}

/*--------------------------------------------------------------------------*

Name            _dos_creatnew - creates a new file

Usage           unsigned _dos_creatnew(char *filename, unsigned attrib,
                                        unsigned *handle);

Prototype in    dos.h

Description     identical to _dos_creat, with the exception that, if
                the file exists, the _dos_creatnew call returns an
                error, leaves the file untouched, and sets errno
                to EEXIST.

Return value    same as _dos_creat

Note            Compatible with Microsoft C.  Not the same as creatnew().

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_creatnew (const char *pathP, unsigned attr, int *handle )
{
    return( DosCreate((char *)pathP, attr, handle, CREATE_NEW) );
}
