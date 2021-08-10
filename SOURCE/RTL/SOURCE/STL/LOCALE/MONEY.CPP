#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * money.cpp - Source for the Standard Library monetary locale classes.
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
#include <rw/lochelp>
#include <rw/numbrw>
#include <rw/money>
#include <rw/rwstderr.h>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;

namespace __rwstd { 
#endif

#ifdef _RWSTD_LOCALIZED_ERRORS
  extern const unsigned int _RWSTDExport __rw_LocaleBadMoneyName = _RWSTD_ERROR_LOCALE_BAD_MONEY_NAME;
#else
  extern const char _RWSTDExportFunc(*) __rw_LocaleBadMoneyName = "Invalid monetary locale name";
#endif //_RWSTD_LOCALIZED_ERRORS
// ---------------------------------------------
// Implementation class moneypunct_base members:
// ---------------------------------------------

moneypunct_init<char>*
moneypunct_base::__get_named_init (const char *name,bool intl)
{
  use_Clib_locale clocale(name,LC_MONETARY);
  _RWSTD_THROW(!clocale,domain_error,__RWSTD::except_msg_string(__rw_LocaleBadMoneyName).msgstr());
  lconv *lc=localeconv();

  // If C library locale does not contain monetary formatting information (this
  // is usual for the "C" locale for instance), we default to the settings in
  // the vendor's native locale.  A more rigorous approach might be to throw
  // something.  (And also find a way to have has_facet return false?)

  if (lc->frac_digits==CHAR_MAX)
    return intl? &moneypunct_impl<char,true>::ivals_ :
                 &moneypunct_impl<char,false>::ivals_;

  size_t extra_chars=strlen(lc->mon_grouping)+1;
  size_t extra_charTs=strlen(intl? lc->int_curr_symbol : lc->currency_symbol)+1
      +strlen(lc->positive_sign)+1+strlen(lc->negative_sign)+1;
  size_t size=sizeof(moneypunct_init<char>)
      +extra_chars+extra_charTs;

  moneypunct_init<char>* init =
      (moneypunct_init<char>*) new char[size];
  char *p=(char*) (init+1);

  init->del_=true;
  init->dp_=*lc->mon_decimal_point;
  init->ts_=*lc->mon_thousands_sep;
  init->gr_=strcpy(p,lc->mon_grouping);
  init->ps_=strcpy(p+=strlen(p)+1,lc->positive_sign);
  init->ns_=strcpy(p+=strlen(p)+1,lc->negative_sign);

  if (intl) {
    init->cs_=strcpy(p+=strlen(p)+1,lc->int_curr_symbol);
    init->fd_=lc->int_frac_digits;

    // All international formats follow the same pattern.
    init->pf_.field[0]=init->nf_.field[0]=money_base::symbol;
    init->pf_.field[1]=init->nf_.field[1]=money_base::sign;
    init->pf_.field[2]=init->nf_.field[2]=money_base::none;
    init->pf_.field[3]=init->nf_.field[3]=money_base::value;
  } else {
    init->cs_=strcpy(p+=strlen(p)+1,lc->currency_symbol);
    init->fd_=lc->frac_digits;

    // For non-international formats we have to construct the positive and
    // negative patterns from flags in the lconv structure.

    p=init->pf_.field;
    if (lc->p_sign_posn==2 || lc->p_sign_posn==4)
      p[3]=money_base::sign;
    else {
      p[0]=money_base::sign;
      p++;
    }
    if (lc->p_cs_precedes) {
      p[0]=money_base::symbol;
      p[2]=money_base::value;
    } else {
      p[0]=money_base::value;
      p[2]=money_base::symbol;
    }
    if (lc->p_sep_by_space)
      p[1]=money_base::space;
    else
      p[1]=money_base::none;

    p=init->nf_.field;
    if (lc->n_sign_posn==2 || lc->n_sign_posn==4)
      p[3]=money_base::sign;
    else {
      p[0]=money_base::sign;
      p++;
    }
    if (lc->n_cs_precedes) {
      p[0]=money_base::symbol;
      p[2]=money_base::value;
    } else {
      p[0]=money_base::value;
      p[2]=money_base::symbol;
    }
    if (lc->n_sep_by_space)
      p[1]=money_base::space;
    else
      p[1]=money_base::none;
  }

  return init;
}

// ---------------------------------------------------------
// Implementation class moneypunct_impl<char,false> members.
// ---------------------------------------------------------

moneypunct_init<char>
moneypunct_impl<char,false>::ivals_ =
{
  false,        // Don't delete me, I'm static
  '.',          // Decimal point
  ',',          // Thousands separator
  "\03",        // Digit grouping rule
  "$",          // Currency symbol
  "",           // Positive sign
  "-",          // Negative sign
  2,            // Fractional digits

  { { money_base::symbol, money_base::sign,         // Positive format
      money_base::none,   money_base::value } },
  { { money_base::symbol, money_base::sign,         // Negative format
      money_base::none,   money_base::value } }
};

// ---------------------------------------------------------
// Implementation class moneypunct_impl<char,true> members.
// ---------------------------------------------------------

moneypunct_init<char>
moneypunct_impl<char,true>::ivals_ =
{
  false,        // Don't delete me, I'm static
  '.',          // Decimal point
  ',',          // Thousands separator
  "\03",        // Digit grouping rule
  "USD ",       // Currency symbol
  "",           // Positive sign
  "-",          // Negative sign
  2,            // Fractional digits

  { { money_base::symbol, money_base::sign,         // Positive format
      money_base::none,   money_base::value } },
  { { money_base::symbol, money_base::sign,         // Negative format
      money_base::none,   money_base::value } }
};
#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

