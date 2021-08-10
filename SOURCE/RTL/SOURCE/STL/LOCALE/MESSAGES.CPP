#include "stlhdrs.h"
#pragma  hdrstop
#ifdef __BORLANDC__
#ifdef __CREATE_ALLSTL__
#  pragma option -Jgd // Disable template instantiation output for this entire
                      // module when creating allstl.txt
#endif
#endif
/***************************************************************************
 *
 * messages.cpp - Source for the Standard Library messages locale classes.
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

#include <locale>
#include <rw/lochelp>

#ifndef _RWSTD_NO_CATOPEN_CATGETS
#include <nl_types.h>
#else
#include <rw/rwcats.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;

namespace __rwstd {
#endif
// Implementation structure private to this module -- open_cat_data.  Keeps
// track of the association between an open message catalog (as identified by
// the nl_catd handle returned by the C library catopen function) and the
// locale specified by the user for character translation in the call to
// messages<charT>::open.

struct open_cat_data {
  nl_catd catd;
  locale loc;

  open_cat_data (): catd((nl_catd)-1), loc(locale::classic()) { }
};

// Static vector of open_cat_data structs for all message catalogs that have
// been opened and not yet closed.  Note that the handle we return (of type
// messages_base::catalog) to identify a catalog is an index into this vector.
// This is NOT the same as the nl_catd handle of the underlying C library or
// operating system catalog.  We don't use the nl_catd value because we can't
// assume the C library returns unique nl_catd values when identically-named
// catalogs are opened.  (It may be returning the same handle and keeping an
// internal ref-count instead.)

static locale_vector<open_cat_data> open_cats;

// Constructor.  We require a LC_MESSAGES name to be fixed at construction
// time, so that subsequent operations can be independent of changes to the
// C library locale.

messages_impl::messages_impl (string n):
    loc_name_(n)
{ }

// Static function that can be used during construction to convert a possibly
// abbreviated locale name into a full LC_MESSAGES name.

string messages_impl::get_loc_name_ (const char *name)
{
  use_Clib_locale clocale(name,LC_MESSAGES);
  return setlocale(LC_MESSAGES,NULL);
}

// Open a message catalog and assign and return a handle for it.

messages_base::catalog messages_impl::open_cat_
    (const string &cat_name, const locale &loc) const
{
  use_Clib_locale clocale(loc_name_.c_str(),LC_MESSAGES);

  nl_catd catd=catopen(cat_name.c_str(),NL_CAT_LOCALE);
  if (catd==(nl_catd) -1)
    return (messages_base::catalog)-1;

  locale_vector<open_cat_data>::iterator it = open_cats.begin();
  for ( ; ; it++) {
    if (it==open_cats.end()) {
      // Vector is full, so add and use a new entry at the end.
      open_cats.resize(open_cats.size()+1);
      it=open_cats.end();
      it--;
      break;
    }
    if ((*it).catd==(nl_catd)-1)
      // Found an unused entry, so reuse it.
      break;
  }

  (*it).catd=catd;
  (*it).loc=loc;

  return it-open_cats.begin();
}

// Get message text from catalog.

char *messages_impl::get_mess_
    (messages_base::catalog cat, int set_num, int msg_num) const
{
  nl_catd catd;
  if (cat<open_cats.size() && (catd=open_cats[cat].catd)!=(nl_catd)-1) {
    char buf[1];
    buf[0]=0;
    char *text=catgets(catd,set_num,msg_num,buf);
    if (text!=buf)
      return text;
  }

  return NULL;
}

// Get locale to be used for character translation for this message catalog.

const locale &messages_impl::get_loc_
    (messages_base::catalog cat) const
{
  if (cat<open_cats.size())
    return open_cats[cat].loc;
  return locale::classic();
}

// Close a catalog and release its handle.

void messages_impl::close_cat_
    (messages_base::catalog cat) const
{
  nl_catd catd;
  if (cat<open_cats.size() && (catd=open_cats[cat].catd)!=(nl_catd) -1) {
    catclose(catd);
    open_cats[cat].catd=(nl_catd) -1;
    open_cats[cat].loc=locale::classic();
  }
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

