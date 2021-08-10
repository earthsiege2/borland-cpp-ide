/*-----------------------------------------------------------------------*
 * filename - utime.c
 *
 * function(s)
 *        utime - set file access and modification times
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <time.h>
#include <utime.h>
#include <_io.h>
#include <_time.h>

static char Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static BOOL unixtofile(time_t tim, FILETIME *ftp)
{
    SYSTEMTIME st;

    /* Convert supplied modification time to System date and time.
     * This code was stolen from unixtodos().
     */
    tim -= 24L * 60L * 60L * 3652L + timezone;
    st.wSecond = tim % 60;
    tim /= 60;                              /* Time in minutes */
    st.wMinute = tim % 60;
    tim /= 60;                              /* Time in hours */
    st.wYear = 1980 + (int)((tim / (1461L * 24L)) << 2);
    tim %= 1461L * 24L;
    if (tim >= 366 * 24)
    {
            tim -= 366 * 24;
            st.wYear++;
            st.wYear += (int)(tim / (365 * 24));
            tim %= 365 * 24;
    }
    if (daylight && _isDST( (int)(tim % 24), (int)(tim / 24), 0, st.wYear-1970 ))
            tim++;
    st.wHour = tim % 24;
    tim /= 24;                              /* Time in days */
    tim++;
    if ((st.wYear & 3) == 0)
    {
            if (tim > 60)
                    tim--;
            else
            if (tim == 60)
            {
                    st.wMonth = 2;
                    st.wDay = 29;
                    goto done;
            }
    }
    for (st.wMonth = 0; Days[st.wMonth] < tim; st.wMonth++)
            tim -= Days[st.wMonth];
    st.wMonth++;
    st.wDay = tim;
done:

    /* Convert the constructed system time to a file time.
     */
    return SystemTimeToFileTime(&st,ftp);
}

/*---------------------------------------------------------------------*

Name            utime - set file modification time

Usage           int utime(const char *path, const struct utimbuf *times);

Prototype in    utime.h

Description     Sets the modification time for the file 'path'
                to the UNIX-format time in times->modtime.  The
                access time times->actime is ignored on DOS.
                If times is NULL, the current time is used.

Return value    If successful, 0 is returned.  Otherwise -1 is returned
                and errno is set as follows:

                ENOENT      File not found
                EMFILE      oo many open files
                EACCESS     Permission denied

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC utime(const char *path, const struct utimbuf *times)
{
    unsigned err;
    HANDLE handle;
    SYSTEMTIME st;
    FILETIME fta;       /* access time */
    FILETIME ftm;       /* modification time */

    /* We have to open the file for writing before we can modify its time.
     */
    if ((handle = CreateFile(path, GENERIC_WRITE,
                             FILE_SHARE_READ|FILE_SHARE_WRITE,
                             NULL, OPEN_EXISTING, 0, NULL)) == (HANDLE)-1)
        return (__NTerror());

    /* If times not supplied, use current time.
     */
    if (times == NULL)
    {
        GetSystemTime(&st);
        SystemTimeToFileTime(&st,&fta);
        ftm = fta;
    }
    else
    {
        /* Convert supplied modification and access times to NT file times.
         */
        if ((err = unixtofile(times->actime, &fta)) != TRUE) goto done;
        if ((err = unixtofile(times->modtime, &ftm)) != TRUE) goto done;
    }

    /* Set the file time and date, close the file.
     */
    err = SetFileTime(handle,&ftm,&fta,&ftm);
done:
    CloseHandle(handle);
    return (err == TRUE ? 0 : __NTerror());
}
