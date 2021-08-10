/*------------------------------------------------------------------------
 * filename - ftime.c
 *
 * function(s)
 *        ftime - Get current time and store it in 'timeb' structure
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <sys\timeb.h>

/*---------------------------------------------------------------------*

Name            ftime - Get current time and store it in 'timeb' structure

Usage           void ftime(struct timeb *TimeStructPtr);

Prototype in    sys\timeb.h

Description     ftime determines the current time and fills in the fields
                in the timeb structure pointed to by TimeStructPtr.

*---------------------------------------------------------------------*/

void _FARFUNC _ftime(struct timeb _FAR *TimeStructPtr);

void _FARFUNC ftime(struct timeb _FAR *TimeStructPtr)
{
    _ftime( TimeStructPtr );
}
