/*------------------------------------------------------------------------
 * filename - _ftime.c
 *
 * function(s)
 *        _ftime - Get current time and store it in 'timeb' structure
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#include <sys\timeb.h>
#include <time.h>
#include <dos.h>
#include <mem.h>
#include <_io.h>


/*---------------------------------------------------------------------*

Name            getdate - gets MS-DOS date

Usage           #include <dos.h>
                void getdate(struct date *dateblk);

Prototype in    dos.h

Description     getdate fills in the date structure (pointed to by
                dateblk) with the system's current date.

                The date structure is defined as follows:

                struct date {
                        int da_year;    (* Current year *)
                        char da_day;    (* Day of the month *)
                        char da_mon;    (* Month (1 = Jan) *)
                };

Return value    nothing

*---------------------------------------------------------------------*/
static void _getdate(struct date *datep)
{
        _AH = 0x2a;
        geninterrupt(0x21);
        ((int *)datep)[0] = _CX;
        ((int *)datep)[1] = _DX;
}

/*---------------------------------------------------------------------*

Name            gettime - gets MS-DOS time

Usage           #include <dos.h>
                void gettime(struct time *timep);

Prototype in    dos.h

Description     gettime fills in the time structure pointed to by timep
                with the system's current time.

                The time structure is defined as follows:

                struct time {
                        unsigned char ti_min;   (* Minutes *)
                        unsigned char ti_hour;  (* Hours *)
                        unsigned char ti_hund;  (* Hundredths of seconds *)
                        unsigned char ti_sec;   (* Seconds *)
                };

Return value    nothing

*---------------------------------------------------------------------*/
static void _gettime(struct time *timep)
{
        _AH = 0x2c;
        geninterrupt(0x21);
        ((int *)timep)[0] = _CX;
        ((int *)timep)[1] = _DX;
}


/*---------------------------------------------------------------------*

Name            _ftime - Get current time and store it in 'timeb' structure

Usage           void _ftime(struct timeb *TimeStructPtr);

Prototype in    nowhere, private function used by ftime.c and clock.cas

Description     _ftime determines the current time and fills in the fields
                in the timeb structure pointed to by TimeStructPtr.

*---------------------------------------------------------------------*/

void _FARFUNC _ftime(struct timeb _FAR *TimeStructPtr)
{
    struct date DosDate;
    struct time DosTime;

    tzset(); /* Get timezone info. */

    /*
       Because there is a window of vulnerability at exactly midnight when
       calling getdate(INT 21 fn 2A) and gettime(INT 21 fn 2C) in succession,
       we check whether the time has just passed midnight and get the date
       again if necessary.
    */
    _getdate(&DosDate);
    _gettime(&DosTime);
    if ((DosTime.ti_hour == 0) && (DosTime.ti_min == 0))
	_getdate(&DosDate);

    /*
       Convert extern 'timezone's seconds to structure 'timezone's minutes.
       Set daylight savings indicator.
       Convert DOS date and time to UNIX style time and store in structure.
       Set milliseconds structure field. DOS is only accurate to 100ths of a
          second so (100ths * 10) makes 1000ths.
    */
#if defined(_RTLDLL)
        TimeStructPtr->__timezone = (short)( _timezone / 60L);
#else
        TimeStructPtr->_timezone = (short)( _timezone / 60L);
#endif
    if (_daylight && __isDST( DosTime.ti_hour, DosDate.da_day,
                                 DosDate.da_mon,  DosDate.da_year-1970) )
        TimeStructPtr->dstflag  = 1;
    else
        TimeStructPtr->dstflag  = 0;

    TimeStructPtr->time     = dostounix(&DosDate, &DosTime);
    TimeStructPtr->millitm  = DosTime.ti_hund * 10;
}
