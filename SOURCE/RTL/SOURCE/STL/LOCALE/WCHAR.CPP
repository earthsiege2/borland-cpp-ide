#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * wchar.cpp - Source for wchar instantiations of locale facets
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

#if defined(_RW_STD_LOCALE) && !defined(_RWSTD_NO_WIDE_CHAR)

#include <rw/rwlocale>
#include <rw/collate>
#include <istream>

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstdlib>
#include <cassert>
#include <clocale>
#else
#include <locale.h>
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
#include <stdexcept>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _MSC_VER
static 
#endif
inline bool fits (wchar_t c) {
  return ((~(wchar_t)UCHAR_MAX) & c) == 0;
}

// --------------------------------------
// Specialization ctype<wchar_t> members.
// --------------------------------------

locale::id _RWSTDExport ctype<wchar_t>::id;

ctype<wchar_t>::ctype (size_t refs): locale::facet(refs,locale::ctype) { }

ctype<wchar_t>::mask ctype<wchar_t>::mask_of (wchar_t c) {
  return fits(c)?
      ctype<char>::classic_table()[(unsigned char)c] : (ctype_base::mask) 0;
}

#ifndef _RWSTD_STRICT_ANSI
ctype<wchar_t>::string_type ctype<wchar_t>::widen (const string &s) const {
  string_type result(s.size(),0);
  do_widen(s.begin(),s.end(),result.begin());
  return result;
}

string ctype<wchar_t>::narrow (const string_type &s,char dfault) const {
  string result(s.size(),0);
  do_narrow(s.begin(),s.end(),dfault,result.begin());
  return result;
}
#endif

bool ctype<wchar_t>::do_is(mask m, wchar_t c) const {
  return (mask_of(c) & m) != 0;
}

const wchar_t* ctype<wchar_t>::do_is(
  const wchar_t* lo, const wchar_t* hi, mask* vec) const
{
  while (lo != hi)
    *vec++ = mask_of(*lo++);
  return hi;
}

const wchar_t* ctype<wchar_t>::do_scan_is(
  ctype_base::mask m,
  const wchar_t* low,
  const wchar_t* high) const
{
  while (low != high && !(mask_of(*low) & m))
    ++low;
  return low;
}

const wchar_t* ctype<wchar_t>::do_scan_not(
  mask m,
  const wchar_t* low,
  const wchar_t* high) const
{
  while (low != high && (mask_of(*low) & m))
    ++low;
  return low;
}

wchar_t ctype<wchar_t>::do_toupper(wchar_t c) const
{
  return (mask_of(c) & lower) ? (c &~ 0x20) : c;
}

const wchar_t* ctype<wchar_t>::do_toupper(wchar_t* low, const wchar_t* high) const
{
  for (; low < high; ++low)
    if (mask_of(*low) & lower)
      *low &=~ 0x20;
  return low;
}

wchar_t ctype<wchar_t>::do_tolower(wchar_t c) const
{
  return (mask_of(c) & upper) ? (c | 0x20) : c;
}

const wchar_t*  ctype<wchar_t>::do_tolower(wchar_t* low, const wchar_t* high) const
{
  for (; low < high; ++low)
    if ((mask_of(*low) & upper) != 0) *low |= 0x20;
  return low;
}
wchar_t ctype<wchar_t>::do_widen(char c) const
{
  return (wchar_t)(unsigned char)c;
}

const char* ctype<wchar_t>::do_widen(
  const char* lo,
  const char* hi, wchar_t* dest) const
{
  while (lo != hi) {
    *dest = (wchar_t)(unsigned char)*lo;
    ++lo; ++dest;
  }
  return hi;
}

char ctype<wchar_t>::do_narrow(wchar_t c, char dfault) const
{
  return (fits(c) ? (char)(unsigned char)c : dfault);
}

const wchar_t* ctype<wchar_t>::do_narrow(const wchar_t* lo, const wchar_t* hi,
                                char dfault, char* dest) const
{
  for ( ; lo != hi; lo++)
    *dest++ = fits(*lo) ? (char)(unsigned char)*lo : dfault;
  return hi;
}

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

collate_table<wchar_t> _RWSTDExport collate_impl<wchar_t>::__default_table =
{
  0, { NULL, NULL, NULL, 0, 0, 0 }
};

// This will move to wvendor.cpp
numpunct_init<wchar_t>
numpunct_impl<wchar_t>::ivals_ =
{
  false,        // Don't delete me, I'm static
  L'.',         // Decimal point
  L',',         // Thousands separator
  "",           // Digit grouping rule
  L"true",      // Boolean true value as string
  L"false",     // Boolean false value as string
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RW_STD_LOCALE && !_RWSTD_NO_WIDE_CHAR

