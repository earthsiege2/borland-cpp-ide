/*---------------------------------------------------------------------------
 * filename - ffile.c
 *
 * function(s)
 *              _findnext     - fetches files which match findfirst
 *              _wfindnext    - fetches files which match _wfindfirst
 *              _findnexti64  - fetches files which match _findfirsti64
 *              _wfindnexti64 - fetches files which match _wfindfirsti64
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

#include <io.h>
#include <time.h>
#include <windows.h>
#include <tchar.h>
#include <errno.h>
#include <_time.h>
#include <_io.h>

#define MAGIC_VALUE (-2L)

/*--------------------------------------------------------------------------*

Name            _tfindnexti64 and _tfindnext used as _findnext,
                _wfindnext, _findnexti64 and _wfindnext64

                _findnext     - fetches files which match findfirst
                _wfindnext    - fetches files which match _wfindfirst
                _findnexti64  - fetches files which match _findfirsti64
                _wfindnexti64 - fetches files which match _wfindfirsti64


Usage           long _findnext(long handle, struct _finddata_t *filespec);
                long _wfindnext(long handle, struct _wfinddata_t *filespec);
                long _findnexti64(long handle, struct _finddatai64_t *filespec);
                long _wfindnexti64(long handle, struct _wfinddatai64_t *filespec);

Prototype in    io.h

Description     _tfindnext is used to fetch subsequent files which
                match the pathname given in _tfindfirst.  _finddata_t is the
                same block filled in by the _tfindfirst call.  This
                block contains necessary information for continuing
                the search.  One file name for each call to _tfindnext will
                be returned until no more files are found in the directory
                matching the pathname. The i64 versions are for 64 bit filesize
                use.

Return value    success : returns a handle to the file that can be used
                          in subsequent calls to _findnext

                else : INVALID_HANDLE_VALUE and errno will be set accordingly

*---------------------------------------------------------------------------*/

#ifdef _USE_FINDFIRST64_
long _RTLENTRY _EXPFUNC __tfindnexti64(long handle, struct __tfinddatai64_t *filespec)
#else
long _RTLENTRY _EXPFUNC __tfindnext(long handle, struct __tfinddata_t *filespec)
#endif /* _USE_FINDFIRST64_ */
{
    long nexthandle;
    WIN32_FIND_DATA fdata;
    FILETIME ft;
    SYSTEMTIME st;

    ZeroMemory(&fdata, sizeof(WIN32_FIND_DATA));

    if (handle == MAGIC_VALUE)  /* called FindFirst */
    {
        nexthandle = (long)FindFirstFile(filespec->name, &fdata);
        if ((nexthandle == (long)INVALID_HANDLE_VALUE) ||
            (nexthandle == (long)0))
        {
            __DOSerror();    /* Set errno */
            return -1L;      /* Failure   */
        }
    }
    else
    {
        nexthandle = FindNextFile((HANDLE)handle, &fdata);
        if ((nexthandle == (long)INVALID_HANDLE_VALUE) ||
            (nexthandle == (long)0))
        {
            __DOSerror();   /* Set errno */
            return -1L;     /* Failure   */
        }
    }

    filespec->attrib      = fdata.dwFileAttributes;

    FileTimeToLocalFileTime(&fdata.ftCreationTime, &ft);
    FileTimeToSystemTime(&ft, &st);
    filespec->time_create = _totalsec(st.wYear-1900, st.wMonth-1, st.wDay-1,
                                      st.wHour, st.wMinute, st.wSecond, -1);

    FileTimeToLocalFileTime(&fdata.ftLastAccessTime, &ft);
    FileTimeToSystemTime(&ft, &st);
    filespec->time_access = _totalsec(st.wYear-1900, st.wMonth-1, st.wDay-1,
                                      st.wHour, st.wMinute, st.wSecond, -1);

    FileTimeToLocalFileTime(&fdata.ftLastWriteTime, &ft);
    FileTimeToSystemTime(&ft, &st);
    filespec->time_write  = _totalsec(st.wYear-1900, st.wMonth-1, st.wDay-1,
                                      st.wHour, st.wMinute, st.wSecond, -1);
#ifdef _USE_FINDFIRST64_
    filespec->size        = (((__int64)fdata.nFileSizeHigh) << 32) | ((__int64)fdata.nFileSizeLow);
#else
    filespec->size        = fdata.nFileSizeLow;
#endif

    _tcscpy(filespec->name,  fdata.cFileName);

    if (handle == MAGIC_VALUE)  /* called FindFirst */
        return (long)nexthandle;

    return 0L; /* Success */

}


/*--------------------------------------------------------------------------*

Name            _tfindfirst and _tfindfirsti64 used as _findfirst,
                _wfindfirst, _findfirsti64 and _wfindfirsti64

                _findfirst     - searches disk directory
                _wfindfirst    - searches disk directory
                _findfirsti64  - searches disk directory
                _wfindfirsti64 - searches disk directory

Usage           long -findfirst(const char *filter, struct _finddata_t *filespec);
                long _wfindfirst(const wchar_t *filter, struct _wfinddata_t *filespec);
                long -findfirsti64(const char *filter, struct _finddatai64_t *filespec);
                long _wfindfirsti64(const wchar_t *filter, struct _wfinddatai64_t *filespec);

Prototype in    io.h

Description     begins a search of a disk directory similar to the
                MS-DOS system call 0x4E.

                filter is a string that specifies which files to return.
                wildcards may be used. If a matching file is found, the
                finddata_t structure is filled with the file-directory
                information.

Return value    success : returns a handle to the file that can be used
                          in subsequent calls to _findnext

                else : INVALID_HANDLE_VALUE and errno will be set accordingly


*---------------------------------------------------------------------------*/


#ifdef _USE_FINDFIRST64_
long _RTLENTRY _EXPFUNC __tfindfirsti64(_TCHAR *filter, struct __tfinddatai64_t *filespec)
#else
long _RTLENTRY _EXPFUNC __tfindfirst(_TCHAR *filter, struct __tfinddata_t *filespec)
#endif /* _USE_FINDFIRST64_ */
{
    _tcscpy(filespec->name, filter);

#ifdef _USE_FINDFIRST64_
    return __tfindnexti64(MAGIC_VALUE, filespec);
#else
    return __tfindnext(MAGIC_VALUE, filespec);
#endif
}


/*--------------------------------------------------------------------------*

Name            _findclose
                _findclose   - closes handles associated with a previous
                               findfirst/findnext call


Usage           int findclose(long handle);

Prototype in    io.h

Description     findclose closes any handles and frees up any dynamic
                memory associated with previous calles to findfirst/findnext.

Return value    success : 0
                else : -1 and errno is set to
                        ENOENT Invalid data

*---------------------------------------------------------------------------*/

#if !defined (_UNICODE) && !defined (_USE_FINDFIRST64_)
/* Make sure that there is only one copy of this function */

int _RTLENTRY _EXPFUNC _findclose(long handle)
{
    if ( FindClose((void*)handle) == 0)
    {
        errno = ENOENT;
        return -1;
    }

    return 0;
}
#endif
