#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * wmoney.cpp - Source for the Standard Library wide-character monetary
 *              locale classes.
 *
 * $Id: wmoney.cpp,v 9.6 2001/07/10 17:24:47 nyork Exp $
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
#include <rw/money>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;

namespace __rwstd {
#endif
// ------------------------------------------------------------
// Implementation class moneypunct_impl<wchar_t,false> members.
// ------------------------------------------------------------

moneypunct_init<wchar_t>
moneypunct_impl<wchar_t,false>::ivals_ =
{
  false,        // Don't delete me, I'm static
  L'.',         // Decimal point
  L',',         // Thousands separator
  "\03",        // Digit grouping rule
  L"$",         // Currency symbol
  L"",          // Positive sign
  L"-",         // Negative sign
  2,            // Fractional digits

  { { money_base::symbol, money_base::sign,         // Positive format
      money_base::none,   money_base::value } },
  { { money_base::symbol, money_base::sign,         // Negative format
      money_base::none,   money_base::value } }
};

// ------------------------------------------------------------
// Implementation class moneypunct_impl<wchar_t,true> members.
// ------------------------------------------------------------

moneypunct_init<wchar_t>
moneypunct_impl<wchar_t,true>::ivals_ =
{
  false,        // Don't delete me, I'm static
  L'.',         // Decimal point
  L',',         // Thousands separator
  "\03",        // Digit grouping rule
  L"USD ",      // Currency symbol
  L"",          // Positive sign
  L"-",         // Negative sign
  2,            // Fractional digits

  { { money_base::symbol, money_base::sign,         // Positive format
      money_base::none,   money_base::value } },
  { { money_base::symbol, money_base::sign,         // Negative format
      money_base::none,   money_base::value } }
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RWSTD_NO_WIDE_CHAR

