#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * time.cpp - Source for the Standard Library time and date locale classes.
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-1999 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software – Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/

#include <rw/rwlocale>
#include <iostream>
#include <rw/numbrw>
#include <rw/time>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

  const timepunct_loc<char>::string_type
  timepunct_loc<char>::get_day(int i, bool abbr) const
  {
#if !defined(_RWSTD_NO_NAMESPACE) && !defined(_RWSTD_NO_NEW_HEADER)
    using std::strftime;
    using std::time;
    using std::localtime;
#endif
    char buf[64];
    struct tm tmb;
    time_t now;
    if(time(&now) != time_t(-1))
    {
      struct tm *tmNow;
      tmNow = localtime(&now);
      if(tmNow)
        tmb=*tmNow;
    }
    tmb.tm_wday = i;
    abbr ? strftime(buf,512,"%a",&tmb) : strftime(buf,512,"%A",&tmb);
    return string_type(buf);
  }

  const timepunct_loc<char>::string_type 
  timepunct_loc<char>::get_month(int i, bool abbr) const
  {
#if !defined(_RWSTD_NO_NAMESPACE) && !defined(_RWSTD_NO_NEW_HEADER)
    using std::strftime;
    using std::time;
    using std::localtime;
#endif
    char buf[64];
    struct tm tmb;
    time_t now;
    if(time(&now) != time_t(-1))
    {
      struct tm *tmNow;
      tmNow = localtime(&now);
      if(tmNow)
        tmb=*tmNow;
    }
    tmb.tm_mon = i;
    abbr ? strftime(buf,512,"%b",&tmb) : strftime(buf,512,"%B",&tmb);
    return string_type(buf);
  }

  const timepunct_loc<char>::string_type 
  timepunct_loc<char>::get_ampm(bool afternoon) const
  {
#if !defined(_RWSTD_NO_NAMESPACE) && !defined(_RWSTD_NO_NEW_HEADER)
    using std::strftime;
    using std::time;
    using std::localtime;
#endif
    char buf[16];
    struct tm tmb;
    time_t now;
    if(time(&now) != time_t(-1))
    {
      struct tm *tmNow;
      tmNow = localtime(&now);
      if(tmNow)
        tmb=*tmNow;
    }
    tmb.tm_hour = afternoon ? 13 : 1;
    strftime(buf,512,"%p",&tmb);
    return string_type(buf);
  }
// --------------------------------------------------
// Implementation class timepunct_impl<char> members.
// --------------------------------------------------

timepunct_init<char>
timepunct_impl<char>::__ivals =
{
  {
    { "Sunday",     "Sun" },    // Weekday names and abbreviations
    { "Monday",     "Mon" },
    { "Tuesday",    "Tue" },
    { "Wednesday",  "Wed" },
    { "Thursday",   "Thu" },
    { "Friday",     "Fri" },
    { "Saturday",   "Sat" }
  },
  {
    { "January",    "Jan" },    // Month names and abbreviations
    { "February",   "Feb" },
    { "March",      "Mar" },
    { "April",      "Apr" },
    { "May",        "May" },
    { "June",       "Jun" },
    { "July",       "Jul" },
    { "August",     "Aug" },
    { "September",  "Sep" },
    { "October",    "Oct" },
    { "November",   "Nov" },
    { "December",   "Dec" }
  },

  { "am", "pm" },               // 12-hour clock halves

  "ERR",                        // Error indication

  {
    "0th", "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th",
    "10th","11th","12th","13th","14th","15th","16th","17th","18th","19th",
    "20th","21st","22nd","23rd","24th","25th","26th","27th","28th","29th",
    "30th","31st","32nd","33rd","34th","35th","36th","37th","38th","39th",
    "40th","41st","42nd","43rd","44th","45th","46th","47th","48th","49th",
    "50th","51st","52nd","53rd","54th","55th","56th","57th","58th","59th",
    "60th","61st","62nd","63rd","64th","65th","66th","67th","68th","69th",
    "70th","71st","72nd","73rd","74th","75th","76th","77th","78th","79th",
    "80th","81st","82nd","83rd","84th","85th","86th","87th","88th","89th",
    "90th","91st","92nd","93rd","94th","95th","96th","97th","98th","99th",
  },

  {
    "%m/%d/%y",                     // x: 03/17/96
    "%H:%M:%S",                     // X: 22:50:12
    "%a %b %d %H:%M:%S %Y",         // c: Sun Mar 17 22:50:12 1996
    "%a %b %d",                     // D: Sun Mar 17
    "%I:%M:%S %p",                  // r: 10:50:12 pm
    "%H:%M:%S",                     // T: 22:50:12
  }
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif
