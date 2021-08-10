/*-----------------------------------------------------------------------*
 * filename - ermsghlp.c
 *
 * function(s)
 *        _ErrorMessageHelper - write an error message to file if
                                specified.

 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <_io.h>
#include <dos.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys\stat.h>
#include <time.h>

/* --------------------------------------------------------------------------*/
static char *DateTime (void)
{
    static char buf[24];
    struct time tm;
    struct date da;

    getdate (&da);
    gettime (&tm);

    sprintf(buf,"%02d/%02d/%04d %2d:%02d:%02d.%02d ",
            da.da_mon, da.da_day, da.da_year,
            tm.ti_hour, tm.ti_min, tm.ti_sec, tm.ti_hund);
    return buf;
}
/* --------------------------------------------------------------------------*/

void _ErrorMessageHelper (const char *msgfile, const char *msg)
{
    int fd;
    char *date;

    if ((fd=__open(msgfile,O_TEXT|O_WRONLY|O_CREAT|O_DENYNONE,S_IREAD|S_IWRITE))==-1)
        return;

    date = DateTime ();
    __write (fd, date, strlen (date));
    __write (fd, msg, strlen (msg));
    __close (fd);
}

/* --------------------------------------------------------------------------*/
