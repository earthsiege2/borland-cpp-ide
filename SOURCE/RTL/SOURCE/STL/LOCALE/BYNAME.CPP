#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * byname.cpp - Source for the Standard Library locale classes
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

// byname.cpp: construct standard facets by name.
//   This is in a separate module so that if the program
//   never mentions a locale by name, it doesn't get linked.

#include <compnent.h>
#ifdef _RW_STD_LOCALE
#include <locale>
#include <rw/rwstderr.h>
#include <rw/lochelp>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifdef _RWSTD_LOCALIZED_ERRORS
  extern const char _RWSTDExportFunc(*) __rw_LocaleBadNumericName = "Invalid numeric locale name";
#else
  extern const unsigned int _RWSTDExport __rw_LocaleBadNumericName = _RWSTD_ERROR_LOCALE_BAD_NUMERIC_NAME;
#endif

// -------------------------------------------
// Implementation class numpunct_base members.
// -------------------------------------------

// Static function to construct by name a numpunct_init<char> object for use
// in initializing the private members of a numpunct<charT>.

numpunct_init<char>*
numpunct_base::get_named_init_ (const char *name)
{
  use_Clib_locale clocale(name,LC_NUMERIC);
  _RWSTD_THROW(!clocale,domain_error,__RWSTD::except_msg_string(__rw_LocaleBadNumericName).msgstr());
  lconv *lc=localeconv();

  // The lconv structure does not provide strings to represent the boolean
  // values true and false.  If the strings can be obtained in some vendor-
  // dependent way, they should be substituted for "true" and "false" below.

  size_t extra_chars = strlen(lc->grouping)+1;
  size_t extra_charTs = strlen("true")+1+strlen("false")+1;
  size_t size = sizeof(__RWSTD::numpunct_init<char>)
      + extra_chars + extra_charTs;

  numpunct_init<char>* init =
      (numpunct_init<char>*) new char[size];
  char *p=(char*) (init+1);

  init->del_=true;
  init->dp_=*lc->decimal_point;
  init->ts_=*lc->thousands_sep;
  init->gr_=strcpy(p,lc->grouping);
  init->tn_=strcpy(p+=strlen(p)+1,"true");
  init->fn_=strcpy(p+=strlen(p)+1,"false");

  return init;
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RW_STD_LOCALE

