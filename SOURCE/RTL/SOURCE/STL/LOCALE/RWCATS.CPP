#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * rwcats.cpp - Implementation of XPG4 messages
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

#include <compnent.h>
#ifdef _RW_STD_LOCALE

#include <stdcomp.h>

#ifdef _RWSTD_NO_CATOPEN_CATGETS

#include <stdio.h>
#include <rw/rwcats.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

static locale_vector<__rwcat*> __rwcatlist(2,NULL);
  
#ifdef _RWSTD_USE_RC

  __rwcat::__rwcat(const char* fname, int oflag)
  {
    if (fname)
      __cat = LoadLibrary(fname);
    else
      __cat = GetModuleHandle(NULL);
  }

  __rwcat::~__rwcat()
  {
    if (__cat)
      FreeLibrary(__cat);
    __cat = NULL;
  }

  char * __rwcat::catgets(int set_num, int msg_num, const char* s)
  {
    __cat_type::iterator it = __msgs.find(msg_num);
    if (it != __msgs.end())
      return (char*)(*it).second.c_str();
    else {
      char buf[NL_TEXTMAX];
      if (LoadString(__cat,(UINT)msg_num,buf,NL_TEXTMAX))
      {
        _RW_STD::pair<__cat_type::iterator,bool> ret =
                __msgs.insert(__msg_type(msg_num,_RW_STD::string(buf)));
        if (ret.second)
          return (char*)(*(ret.first)).second.c_str();
      }
    }
    return (char*)s;
  }

#endif //_RWSTD_USE_RC

  locale_vector<__rwcat*>::size_type __catfind(nl_catd id)
  {
    locale_vector<__rwcat*>::size_type i = 0;
    while (i < __rwcatlist.size() && __rwcatlist[i] && __rwcatlist[i]->id() != id)
      i++;
    if (!__rwcatlist[i])
      return __rwcatlist.size();
    return i;
  }  

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifndef _RWSTD_NO_NAMESPACE
using namespace __rwstd;
#endif  

nl_catd catopen(const char* name, int oflag)
{
  __rwcat* cat=NULL;
#ifndef _RWSTD_NO_EXCEPTIONS
  try {
#endif
  cat = new __rwcat(name,oflag);

  if (cat && cat->good())
  {
    locale_vector<__rwcat*>::size_type i = 0;
    while (__rwcatlist[i])
      i++;
    if (__rwcatlist.size() == i)
      __rwcatlist.resize(__rwcatlist.size() * 2,NULL);
    __rwcatlist[i] = cat;
    return cat->id();
  }
#ifndef _RWSTD_NO_EXCEPTIONS
  } catch (...) { ;  }
#endif

  delete cat;
  return (nl_catd)-1; 
}
char * catgets(nl_catd catd, int set_num, int msg_num, const char* s)
{
#ifndef _RWSTD_NO_EXCEPTIONS
  try {
#endif
  locale_vector<__rwcat*>::size_type i = __catfind(catd);
  if (i < __rwcatlist.size())
    return __rwcatlist[i]->catgets(set_num,msg_num,s);
  else
    return (char*)s;
#ifndef _RWSTD_NO_EXCEPTIONS
  } catch (...) { return (char*)s;  }
#endif
}
int catclose(nl_catd catd)
{
  locale_vector<__rwcat*>::size_type i = __catfind(catd);
  if (i < __rwcatlist.size())
  {
    delete __rwcatlist[i];
    locale_vector<__rwcat*>::size_type j;
    for (j = i+1; __rwcatlist[j] && j < __rwcatlist.size(); j++)
      __rwcatlist[j-1] = __rwcatlist[j];
    if (j < __rwcatlist.size())
      __rwcatlist[j] = NULL;
    return 0;
  }
  return -1;
}
#endif // _RWSTD_NO_CATOPEN_CATGETS

#endif // _RW_STD_LOCALE
