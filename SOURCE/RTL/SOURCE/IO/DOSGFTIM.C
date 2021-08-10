/*---------------------------------------------------------------------------
 * filename - dosgftim.c
 *
 * function(s)
 *        _dos_getftime - gets file date and time (MSC compatible)
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#define INCL_ERROR_H
#include <ntbc.h>
#include <io.h>
#include <_io.h>
#include <dos.h>

/*--------------------------------------------------------------------------*

Name            _dos_getftime - gets file date and time

Usage           #include <dos.h>
		unsigned _dos_getftime(int handle, unsigned *date,
			 unsigned *time);

Related
functions       _dos_setftime

Prototype in    dos.h

Description     _dos_getftime retrieves the file time and date for the
		disk file associated with the open handle, storing them
		at *time and *date.

		Time bits       Meaning
		---------       -------
		0-4             Number of 2-second increment (0-99)
		5-10            Minutes (0-59)
		11-15           Hours (0-23)
		
		Date bits       Meaning
		---------       -------
		0-4             Day (1-31)
		5-8             Month (1-12)
		9-15            Year (1980-2099)
		

Return value    On success, 0 is returned.

		In the event of an error return, the DOS error code
		is returned and the global variable errno is set to:

			EBADF           Bad file number

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC _dos_getftime(int fd, unsigned *date, unsigned *time)
{
    FILETIME ft, lft;
    WORD date_word, time_word;

    /* Verify the file handle.
     */
    if ((unsigned)fd >= _nfile)
    {
	__IOerror(ERROR_INVALID_HANDLE);    /* set errno */
	return (ERROR_INVALID_HANDLE);      /* return fake NT error code */
    }

    /* Get the file's last write time.
     */
    if (GetFileTime((HANDLE)_handles[fd], NULL, NULL, &ft) != TRUE)
	return (__DOSerror());

    /* Convert file time to local file time.
     */
    if (FileTimeToLocalFileTime(&ft, &lft) != TRUE)
	return (__DOSerror());
	
    /* Convert the FILETIME to a DOS date and time.
     */
    if (FileTimeToDosDateTime(&lft, &date_word, &time_word) != TRUE)
	return (__DOSerror());

    *date = (unsigned)date_word;
    *time = (unsigned)time_word;
    return (0);
}
