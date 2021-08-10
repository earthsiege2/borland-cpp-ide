/*------------------------------------------------------------------------
 * filename - timedata.c
 *
 * Tables shared by the time functions.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */

#if !defined( __CTYPE_H )
#include <ctype.h>
#endif

#if !defined( __TIME_H )
#include <time.h>
#endif

#if !defined( ___TIME_H )
#include <_time.h>
#endif

_TCHAR *_tSWeekday[7] = {
  _TEXT("Sun"), _TEXT("Mon"), _TEXT("Tue"), _TEXT("Wed"), _TEXT("Thu"),
  _TEXT("Fri"), _TEXT("Sat")
  };

_TCHAR *_tLWeekday[7] = {
  _TEXT("Sunday"),   _TEXT("Monday"), _TEXT("Tuesday"), _TEXT("Wednesday"),
  _TEXT("Thursday"), _TEXT("Friday"), _TEXT("Saturday")
  };

_TCHAR *_tSMonth[12] = {
  _TEXT("Jan"), _TEXT("Feb"), _TEXT("Mar"), _TEXT("Apr"),
  _TEXT("May"), _TEXT("Jun"), _TEXT("Jul"), _TEXT("Aug"),
  _TEXT("Sep"), _TEXT("Oct"), _TEXT("Nov"), _TEXT("Dec")
  };

_TCHAR *_tLMonth[12] = {
  _TEXT("January"),  _TEXT("February"), _TEXT("March"),     _TEXT("April"),
  _TEXT("May"),      _TEXT("June"),     _TEXT("July"),      _TEXT("August"),
  _TEXT("September"),_TEXT("October"),  _TEXT("November"),  _TEXT("December")
  };

_TCHAR *_tAmPm[2] = {
  _TEXT("AM"), _TEXT("PM")
  };

#ifndef _UNICODE
char _Days[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

int _YDays[13] = {
  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
  };
#endif
