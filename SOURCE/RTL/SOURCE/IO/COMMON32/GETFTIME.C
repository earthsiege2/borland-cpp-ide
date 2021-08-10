/*---------------------------------------------------------------------------
 * filename - getftime.c
 *
 * function(s)
 *        getftime - gets file date and time
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <dos.h>
#include <io.h>

/*--------------------------------------------------------------------------*

Name            getftime - gets file date and time

Usage           #include <dos.h>
                int getftime(int handle, struct ftime *ftimep);

Related
functions usage int setftime(int handle, struct ftime *ftimep);

Prototype in    dos.h

Description     getftime retrieves the file time and date for the
                disk file associated with the open handle. The ftime
                structure pointed to by ftimep is filled in with the
                file's time and date.

                setftime sets the file date and time of the disk file
                associated with the open handle to the date and time in the
                ftime structure pointed to by ftimep.

                The ftime structure is defined as follows:

                struct ftime {
                        unsigned ft_tsec: 5;    (* Two seconds *)
                        unsigned ft_min: 6;     (* Minutes *)
                        unsigned ft_hour: 5;    (* Hours *)
                        unsigned ft_day: 5;     (* Days *)
                        unsigned ft_month: 4;   (* Months *)
                        unsigned ft_year: 7;    (* Year - 1980 *)
                };

Return value    Both functions return 0 on success.

                In the event of an error return, -1 is returned and the global
                variable errno is set to one of the following:

                        EINVFNC         Invalid function number
                        EBADF           Bad file number

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC getftime(int fd, struct ftime *ftimep)
{
    short *p;
    int date, time;

    if (_dos_getftime(fd, (unsigned *)&date, (unsigned *)&time) != 0)
        return -1;

    /* WARNING: The following code makes assumptions about the
     * ordering of bit fields.  This may not work on non-Intel CPUs.
     */
    p = (short *)ftimep;
    p[0] = time;
    p[1] = date;

    return 0;
}
