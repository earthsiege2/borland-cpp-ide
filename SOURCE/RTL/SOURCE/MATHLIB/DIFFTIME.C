/*------------------------------------------------------------------------
 * filename - difftime.c
 *
 * function(s)
 *        difftime - computes difference between two times
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <_math.h>
#include <time.h>

/*---------------------------------------------------------------------------*

Name            difftime - computes difference between two times

Usage           #include <time.h>
                double difftime(time_t time2, time_t time1);

Prototype in    time.h

Description     difftime  calculates  the  elapsed  time,  in seconds, from
                time1 to time2

Return value    difftime returns the result of its calculation as a double

*---------------------------------------------------------------------------*/
double difftime(time_t time2, time_t time1)
{
        return (double) time2 - time1;
}
