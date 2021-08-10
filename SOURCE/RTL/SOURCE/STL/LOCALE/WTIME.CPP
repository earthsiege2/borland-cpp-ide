#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * wtime.cpp - Source for the Standard Library wide-character time and date
 *             locale classes.
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

#include <stdcomp.h>
#ifndef _RWSTD_NO_WIDE_CHAR

#include <rw/rwlocale>
#include <iostream>
#include <rw/numbrw>
#include <rw/time>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd { 
#endif

#ifndef _RWSTD_NO_WSTR
  const timepunct_loc<wchar_t>::string_type 
  timepunct_loc<wchar_t>::get_day(int i, bool abbr) const
  {
#if !defined(_RWSTD_NO_NAMESPACE) && !defined(_RWSTD_NO_NEW_HEADER)
#ifndef _HPACC_
    using std::wcsftime;
#endif
#endif
    wchar_t buf[64];
    struct tm tmb;
    tmb.tm_wday = i;
#if defined(_HPACC_) || defined(__sgi)
    abbr ? wcsftime(buf,512,"%a",&tmb) : wcsftime(buf,512,"%A",&tmb);
#else
    abbr ? wcsftime(buf,512,L"%a",&tmb) : wcsftime(buf,512,L"%A",&tmb);
#endif
    return string_type(buf);
  }

  const timepunct_loc<wchar_t>::string_type 
  timepunct_loc<wchar_t>::get_month(int i, bool abbr) const
  {
#if !defined(_RWSTD_NO_NAMESPACE) && !defined(_RWSTD_NO_NEW_HEADER)
#ifndef _HPACC_
    using std::wcsftime;
#endif
#endif
    wchar_t buf[64];
    struct tm tmb;
    tmb.tm_mon = i;
#if defined(_HPACC_) || defined(__sgi)
    abbr ? wcsftime(buf,512,"%b",&tmb) : wcsftime(buf,512,"%B",&tmb);
#else
    abbr ? wcsftime(buf,512,L"%b",&tmb) : wcsftime(buf,512,L"%B",&tmb);
#endif
    return string_type(buf);
  }

  const timepunct_loc<wchar_t>::string_type 
  timepunct_loc<wchar_t>::get_ampm(bool afternoon) const
  {
#if !defined(_RWSTD_NO_NAMESPACE) && !defined(_RWSTD_NO_NEW_HEADER)
#ifndef _HPACC_
    using std::wcsftime;
#endif
#endif
    wchar_t buf[32];
    struct tm tmb;
    tmb.tm_hour = afternoon ? 13 : 1;
#if defined(_HPACC_) || defined(__sgi)
    wcsftime(buf,512,"%p",&tmb);
#else
    wcsftime(buf,512,L"%p",&tmb);
#endif
    return string_type(buf);
  }
#endif  // _RWSTD_NO_WSTR

// -----------------------------------------------------
// Implementation class timepunct_impl<wchar_t> members.
// -----------------------------------------------------

timepunct_init<wchar_t>
timepunct_impl<wchar_t>::__ivals =
{
  {
    { L"Sunday",     L"Sun" },      // Weekday names and abbreviations
    { L"Monday",     L"Mon" },
    { L"Tuesday",    L"Tue" },
    { L"Wednesday",  L"Wed" },
    { L"Thursday",   L"Thu" },
    { L"Friday",     L"Fri" },
    { L"Saturday",   L"Sat" }
  },
  {
    { L"January",    L"Jan" },      // Month names and abbreviations
    { L"February",   L"Feb" },
    { L"March",      L"Mar" },
    { L"April",      L"Apr" },
    { L"May",        L"May" },
    { L"June",       L"Jun" },
    { L"July",       L"Jul" },
    { L"August",     L"Aug" },
    { L"September",  L"Sep" },
    { L"October",    L"Oct" },
    { L"November",   L"Nov" },
    { L"December",   L"Dec" }
  },

  { L"am", L"pm" },                 // 12-hour clock halves

  L"ERR",                           // Error indication

  {
    L"0th", L"1st", L"2nd", L"3rd", L"4th",
    L"5th", L"6th", L"7th", L"8th", L"9th",
    L"10th",L"11th",L"12th",L"13th",L"14th",
    L"15th",L"16th",L"17th",L"18th",L"19th",
    L"20th",L"21st",L"22nd",L"23rd",L"24th",
    L"25th",L"26th",L"27th",L"28th",L"29th",
    L"30th",L"31st",L"32nd",L"33rd",L"34th",
    L"35th",L"36th",L"37th",L"38th",L"39th",
    L"40th",L"41st",L"42nd",L"43rd",L"44th",
    L"45th",L"46th",L"47th",L"48th",L"49th",
    L"50th",L"51st",L"52nd",L"53rd",L"54th",
    L"55th",L"56th",L"57th",L"58th",L"59th",
    L"60th",L"61st",L"62nd",L"63rd",L"64th",
    L"65th",L"66th",L"67th",L"68th",L"69th",
    L"70th",L"71st",L"72nd",L"73rd",L"74th",
    L"75th",L"76th",L"77th",L"78th",L"79th",
    L"80th",L"81st",L"82nd",L"83rd",L"84th",
    L"85th",L"86th",L"87th",L"88th",L"89th",
    L"90th",L"91st",L"92nd",L"93rd",L"94th",
    L"95th",L"96th",L"97th",L"98th",L"99th",
  },

  {
    L"%m/%d/%y",                    // x: 03/17/96
    L"%H:%M:%S",                    // X: 22:50:12
    L"%a %b %d %H:%M:%S %Y",        // c: Sun Mar 17 22:50:12 1996
    L"%a %b %d",                    // D: Sun Mar 17
    L"%I:%M:%S %p",                 // r: 10:50:12 pm
    L"%H:%M:%S",                    // T: 22:50:12
  }
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RWSTD_NO_WIDE_CHAR

