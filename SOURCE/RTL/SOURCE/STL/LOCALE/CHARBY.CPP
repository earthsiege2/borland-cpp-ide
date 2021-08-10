#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * charby.cpp - Source for char instantiations of locale _byname facets
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

#include <locale>
#include <rw/lochelp>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _MSC_VER
static 
#endif
bool _RWSTDExport is_classic_name (const char* name) {
  return strcmp(name, "C") == 0 || strcmp(name, "POSIX") == 0;
}

// --------------------------------------------------
// Standard facet specialization ctype<char> members.
// --------------------------------------------------

ctype_byname<char>::ctype_byname (const char *name,size_t refs):
    ctype<char>(get_mask_table(name),false,refs)
{
	if (__table != __classic_table) {
    __delete_it = true;
    __RWSTD::use_Clib_locale clocale(name,LC_CTYPE);

    char *p;
	unsigned int i,j;

	// set bounds on lower and upper case characters
	for (i=0,j=table_size-1; i<j; i++)
		if (is(lower,i)) {
			for ( ; j>i; j--)
				if (is(lower,j))
					break;
			break;
		}

	__lower_min=i;
	__lower_max=j;

	for (i=0,j=table_size-1; i<j; i++)
		if (is(upper,i)) {
			for ( ; j>i; j--)
				if (is(upper,j))
					break;
			break;
		}

	__upper_min=i;
	__upper_max=j;

	// Install characters in upper and lower case tables
    for (i=__lower_min,p=__to_upper_tab; i<=__lower_max; i++,p++)
      if (is(lower,i))
        *p=::toupper(i);

    for (i=__upper_min,p=__to_lower_tab; i<=__upper_max; i++,p++)
      if (is(upper,i))
        *p=::tolower(i);
  }
}

ctype_byname<char>::~ctype_byname () { }

const ctype_base::mask * ctype_byname<char>::get_mask_table (const char *name)
{
  if (is_classic_name(name))
    return __classic_table;
  else {
    mask *result=new mask[UCHAR_MAX+1];
    __RWSTD::use_Clib_locale clocale(name,LC_CTYPE);
    for (unsigned char c=0; c<UCHAR_MAX; c++) {
      int m=0;
      if (::isspace(c))
        m|=space;
      if (::isprint(c))
        m|=print;
      if (::iscntrl(c))
        m|=cntrl;
      if (::isupper(c))
        m|=upper;
      if (::islower(c))
        m|=lower;
      if (::isalpha(c))
        m|=alpha;
      if (::isdigit(c))
        m|=digit;
      if (::ispunct(c))
        m|=punct;
      if (::isxdigit(c))
        m|=xdigit;
      if (::isgraph(c))
        m|=graph;
      result[c]=mask(m);
    }
    return result;
  }
}

// -----------------------------------------------------------
// Standard facet specialization collate_byname<char> members.
// -----------------------------------------------------------

collate_byname<char>::collate_byname (const char *n,size_t refs):
    collate<char>(refs), __collate_name(n)
{ }

collate_byname<char>::~collate_byname (void) { }

int collate_byname<char>::do_compare
    (const char* low1, const char* high1,
     const char* low2, const char* high2) const
{
  __RWSTD::use_Clib_locale clocale(__collate_name.c_str(),LC_COLLATE);

  size_t len1=high1-low1,len2=high2-low2;
  char *buf=new char[len1+len2+2];
  memcpy(buf,low1,len1);
  buf[len1]=0;
  memcpy(buf+len1+1,low2,len2);
  buf[len1+1+len2]=0;

  int result=strcoll(buf,buf+len1+1);

  if (result)
    if (result>0)
      result=1;
    else
      result=-1;

  delete[] buf;
  return result;
}

string collate_byname<char>::do_transform
  (const char* low, const char* high) const
{
  __RWSTD::use_Clib_locale clocale(__collate_name.c_str(),LC_COLLATE);

  char *buf=new char[high-low+1];
  memcpy(buf,low,high-low);
  buf[high-low]=0;

  size_t result_length=strxfrm(NULL,buf,0);
  char *buf2=new char[1+result_length];
  strxfrm(buf2,buf,1+result_length);

  string result(buf2);

  delete[] buf;
  delete[] buf2;
  return result;
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace std
#endif

#endif // _RW_STD_LOCALE

