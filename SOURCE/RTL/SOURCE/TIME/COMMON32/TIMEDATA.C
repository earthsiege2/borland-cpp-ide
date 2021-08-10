/*------------------------------------------------------------------------
 * filename - timedata.c
 *
 * Tables shared by the time functions.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

char *_SWeekday[7] = {
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  };

char *_LWeekday[7] = {
  "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
  };

char *_SMonth[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

char *_LMonth[12] = {
  "January", "February", "March",     "April",   "May",      "June",
  "July",    "August",   "September", "October", "November", "December"
  };

char *_AmPm[2] = {
  "AM", "PM"
  };

char _Days[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

int _YDays[13] = {
  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
  };
