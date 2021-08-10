/*------------------------------------------------------------------------
 * filename - tzdata.c
 *
 *            Public variables used by TZSET.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

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
#pragma startup initTZ 20 /* Initialization of the tzset() routine */
                          /* Must be called before tzset (tzset.c) */

    tzset();
}
