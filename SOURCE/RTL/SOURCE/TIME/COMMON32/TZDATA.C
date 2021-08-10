/*------------------------------------------------------------------------
 * filename - tzdata.c
 *
 *            Public variables used by TZSET.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $        */

#if defined(__WIN32__)
#include <ntbc.h>
#endif

#include <_defs.h>
#include <time.h>
#include <_time.h>

long  _RTLENTRY _EXPDATA _timezone = DefaultTimeZone * 60L * 60L; /* Set for EST */

int   _RTLENTRY _EXPDATA _daylight = DefaultDaylight;             /* Apply daylight savings */

static void initTZ()
{
#pragma startup initTZ 29	// Note: called before TZSET init
                                // procedure so that correct
                                // wide/narrow version has last shot
    tzset();
}
