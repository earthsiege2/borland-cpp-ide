/*-----------------------------------------------------------------------*
 * filename - timecvt.c
 *
 * function(s)
 *    dostounix - converts date and time to UNIX time format
 *    unixtodos - converts from UNIX-format time
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_io.h>
#include <dos.h>
#include <time.h>

/*---------------------------------------------------------------------*

Name            dostounix - converts date and time to UNIX time format

Usage           long dostounix(struct date *d, struct time *t);

Prototype in    time.h

Description     Converts a date and time (as returned from getdate and
                gettime) into UNIX-format time.

Return value    UNIX version of the given date and time.

*---------------------------------------------------------------------*/
long _FARFUNC _dostounix(struct date *d, struct time *t);

long _FARFUNC dostounix(struct date *d, struct time *t)
{
	return( _dostounix( d, t ) );
}


/*---------------------------------------------------------------------*

Name            unixtodos - converts from UNIX-format time

Usage           void unixtodos(long time, struct date *d, struct time *t);

Prototype in    time.h

Description     Converts a UNIX-format time into date and time.

Return value    There is no return value.

*---------------------------------------------------------------------*/
void _FARFUNC _unixtodos(long time, struct date *d, struct time *t);

void _FARFUNC unixtodos(long time, struct date *d, struct time *t)
{
	_unixtodos( time, d, t );
}
