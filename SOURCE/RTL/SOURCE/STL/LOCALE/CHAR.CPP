#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * char.cpp - Source for char instantiations of locale facets
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

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// Some useful typedefs, this module only.
typedef istreambuf_iterator<char,char_traits<char> > isit;
typedef ostreambuf_iterator<char,char_traits<char> > osit;

// -----------------------------------------------------
// Standard facet specialization -- ctype<char> members.
// -----------------------------------------------------

locale::id _RWSTDExport ctype<char>::id;

#ifndef _RWSTD_NO_STI_SIMPLE
const size_t _RWSTDExport ctype<char>::table_size;
#endif

// Static table of character types for ASCII.
const ctype_base::mask
ctype<char>::__classic_table[ctype<char>::table_size] = {
  ctype_base::mask(cntrl), // 0x00
  ctype_base::mask(cntrl), // 0x01
  ctype_base::mask(cntrl), // 0x02
  ctype_base::mask(cntrl), // 0x03
  ctype_base::mask(cntrl), // 0x04
  ctype_base::mask(cntrl), // 0x05
  ctype_base::mask(cntrl), // 0x06
  ctype_base::mask(cntrl), // 0x07
  ctype_base::mask(cntrl), // 0x08
  ctype_base::mask(space | cntrl), // 0x09
  ctype_base::mask(space | cntrl), // 0x0a
  ctype_base::mask(space | cntrl), // 0x0b
  ctype_base::mask(space | cntrl), // 0x0c
  ctype_base::mask(space | cntrl), // 0x0d
  ctype_base::mask(cntrl), // 0x0e
  ctype_base::mask(cntrl), // 0x0f
  ctype_base::mask(cntrl), // 0x10
  ctype_base::mask(cntrl), // 0x11
  ctype_base::mask(cntrl), // 0x12
  ctype_base::mask(cntrl), // 0x13
  ctype_base::mask(cntrl), // 0x14
  ctype_base::mask(cntrl), // 0x15
  ctype_base::mask(cntrl), // 0x16
  ctype_base::mask(cntrl), // 0x17
  ctype_base::mask(cntrl), // 0x18
  ctype_base::mask(cntrl), // 0x19
  ctype_base::mask(cntrl), // 0x1a
  ctype_base::mask(cntrl), // 0x1b
  ctype_base::mask(cntrl), // 0x1c
  ctype_base::mask(cntrl), // 0x1d
  ctype_base::mask(cntrl), // 0x1e
  ctype_base::mask(cntrl), // 0x1f
  ctype_base::mask(space | print), // ' '
  ctype_base::mask(print | punct | graph), // '!'
  ctype_base::mask(print | punct | graph), // '"'
  ctype_base::mask(print | punct | graph), // '#'
  ctype_base::mask(print | punct | graph), // '$'
  ctype_base::mask(print | punct | graph), // '%'
  ctype_base::mask(print | punct | graph), // '&'
  ctype_base::mask(print | punct | graph), // '\''
  ctype_base::mask(print | punct | graph), // '('
  ctype_base::mask(print | punct | graph), // ')'
  ctype_base::mask(print | punct | graph), // '*'
  ctype_base::mask(print | punct | graph), // '+'
  ctype_base::mask(print | punct | graph), // ','
  ctype_base::mask(print | punct | graph), // '-'
  ctype_base::mask(print | punct | graph), // '.'
  ctype_base::mask(print | punct | graph), // '/'
  ctype_base::mask(print | digit | xdigit | graph), // '0'
  ctype_base::mask(print | digit | xdigit | graph), // '1'
  ctype_base::mask(print | digit | xdigit | graph), // '2'
  ctype_base::mask(print | digit | xdigit | graph), // '3'
  ctype_base::mask(print | digit | xdigit | graph), // '4'
  ctype_base::mask(print | digit | xdigit | graph), // '5'
  ctype_base::mask(print | digit | xdigit | graph), // '6'
  ctype_base::mask(print | digit | xdigit | graph), // '7'
  ctype_base::mask(print | digit | xdigit | graph), // '8'
  ctype_base::mask(print | digit | xdigit | graph), // '9'
  ctype_base::mask(print | punct | graph), // ':'
  ctype_base::mask(print | punct | graph), // ';'
  ctype_base::mask(print | punct | graph), // '<'
  ctype_base::mask(print | punct | graph), // '='
  ctype_base::mask(print | punct | graph), // '>'
  ctype_base::mask(print | punct | graph), // '?'
  ctype_base::mask(print | punct | graph), // '@'
  ctype_base::mask(print | upper | alpha | xdigit | graph), // 'A'
  ctype_base::mask(print | upper | alpha | xdigit | graph), // 'B'
  ctype_base::mask(print | upper | alpha | xdigit | graph), // 'C'
  ctype_base::mask(print | upper | alpha | xdigit | graph), // 'D'
  ctype_base::mask(print | upper | alpha | xdigit | graph), // 'E'
  ctype_base::mask(print | upper | alpha | xdigit | graph), // 'F'
  ctype_base::mask(print | upper | alpha | graph), // 'G'
  ctype_base::mask(print | upper | alpha | graph), // 'H'
  ctype_base::mask(print | upper | alpha | graph), // 'I'
  ctype_base::mask(print | upper | alpha | graph), // 'J'
  ctype_base::mask(print | upper | alpha | graph), // 'K'
  ctype_base::mask(print | upper | alpha | graph), // 'L'
  ctype_base::mask(print | upper | alpha | graph), // 'M'
  ctype_base::mask(print | upper | alpha | graph), // 'N'
  ctype_base::mask(print | upper | alpha | graph), // 'O'
  ctype_base::mask(print | upper | alpha | graph), // 'P'
  ctype_base::mask(print | upper | alpha | graph), // 'Q'
  ctype_base::mask(print | upper | alpha | graph), // 'R'
  ctype_base::mask(print | upper | alpha | graph), // 'S'
  ctype_base::mask(print | upper | alpha | graph), // 'T'
  ctype_base::mask(print | upper | alpha | graph), // 'U'
  ctype_base::mask(print | upper | alpha | graph), // 'V'
  ctype_base::mask(print | upper | alpha | graph), // 'W'
  ctype_base::mask(print | upper | alpha | graph), // 'X'
  ctype_base::mask(print | upper | alpha | graph), // 'Y'
  ctype_base::mask(print | upper | alpha | graph), // 'Z'
  ctype_base::mask(print | punct | graph), // '['
  ctype_base::mask(print | punct | graph), // '\\'
  ctype_base::mask(print | punct | graph), // ']'
  ctype_base::mask(print | punct | graph), // '^'
  ctype_base::mask(print | punct | graph), // '_'
  ctype_base::mask(print | punct | graph), // '`'
  ctype_base::mask(print | lower | alpha | xdigit | graph), // 'a'
  ctype_base::mask(print | lower | alpha | xdigit | graph), // 'b'
  ctype_base::mask(print | lower | alpha | xdigit | graph), // 'c'
  ctype_base::mask(print | lower | alpha | xdigit | graph), // 'd'
  ctype_base::mask(print | lower | alpha | xdigit | graph), // 'e'
  ctype_base::mask(print | lower | alpha | xdigit | graph), // 'f'
  ctype_base::mask(print | lower | alpha | graph), // 'g'
  ctype_base::mask(print | lower | alpha | graph), // 'h'
  ctype_base::mask(print | lower | alpha | graph), // 'i'
  ctype_base::mask(print | lower | alpha | graph), // 'j'
  ctype_base::mask(print | lower | alpha | graph), // 'k'
  ctype_base::mask(print | lower | alpha | graph), // 'l'
  ctype_base::mask(print | lower | alpha | graph), // 'm'
  ctype_base::mask(print | lower | alpha | graph), // 'n'
  ctype_base::mask(print | lower | alpha | graph), // 'o'
  ctype_base::mask(print | lower | alpha | graph), // 'p'
  ctype_base::mask(print | lower | alpha | graph), // 'q'
  ctype_base::mask(print | lower | alpha | graph), // 'r'
  ctype_base::mask(print | lower | alpha | graph), // 's'
  ctype_base::mask(print | lower | alpha | graph), // 't'
  ctype_base::mask(print | lower | alpha | graph), // 'u'
  ctype_base::mask(print | lower | alpha | graph), // 'v'
  ctype_base::mask(print | lower | alpha | graph), // 'w'
  ctype_base::mask(print | lower | alpha | graph), // 'x'
  ctype_base::mask(print | lower | alpha | graph), // 'y'
  ctype_base::mask(print | lower | alpha | graph), // 'z'
  ctype_base::mask(print | punct | graph), // '{'
  ctype_base::mask(print | punct | graph), // '|'
  ctype_base::mask(print | punct | graph), // '}'
  ctype_base::mask(print | punct | graph), // '~'
  ctype_base::mask(cntrl), // 0x7f
  // Remaining entries are 0 thanks to static initialization.
};

// Constructor.
ctype<char>::ctype (const ctype_base::mask* tab, bool del, size_t refs):
    locale::facet(refs,locale::ctype), __table(tab), __delete_it(del)
{
  // Save the passed table of mask values.
  if (!__table) {
    __table=__classic_table;
    __delete_it=false;
  }

  // Build translate tables __to_upper_tab and __to_lower_tab.  The standard
  // does not pass enough information into this constructor to let us do this
  // reliably.  As a fall-back we construct tables that work for as much of
  // ['a'..'z','A'..'Z'] as is marked lower/upper in the mask table, and leave
  // it to the derived class to correct the tables and/or to override the
  // do_toupper/lower as needed.

  // As a future extension, we could provide a non-standard constructor, or
  // a non-standard additional argument to this constructor, that would let
  // pre-built upper-to-lower tranlate tables be passed into the class along
  // with the pre-built mask table.
  unsigned int i,j,c;
  char *p;

  for (i=0,j=table_size-1; i<j; i++)
	  if (is(lower,i)) {
		  for ( ; j>i; j--)
			  if (is(lower,j))
				  break;
		  break;
	  }

  __lower_min=i;
  __lower_max=j;

  __to_upper_tab=new char[j-i+1];
  for (p=__to_upper_tab; i<=j; i++,p++)
	  *p=(i>=(unsigned char) 'a' && i<=(unsigned char) 'z'
		  && is(lower,i) && is(upper,c=i+'A'-'a'))? c : i;

  for (i=0,j=table_size-1; i<j; i++)
	  if (is(upper,i)) {
		  for ( ; j>i; j--)
			  if (is(upper,j))
				  break;
		  break;
	  }

  __upper_min=i;
  __upper_max=j;

  __to_lower_tab=new char[j-i+1];
  for (p=__to_lower_tab; i<=j; i++,p++)
	  *p=(i>=(unsigned char) 'A' && i<=(unsigned char) 'Z'
		  && is(upper,i) && is(lower,c=i+'a'-'A'))? c : i;

}

void ctype<char>::__initfacet (const locale* loc) {
	__RWSTD::use_Clib_locale clocale(loc->name().data(),LC_CTYPE);
	unsigned int i,j,c;
	char *p;

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

ctype<char>::~ctype () {
  if (__delete_it)
    delete[] _RWSTD_CONST_CAST(mask*,__table);
  delete[] __to_upper_tab;
  delete[] __to_lower_tab;
}

char ctype<char>::do_toupper (char c) const {
  return is(lower,c)? __to_upper_tab[(unsigned char)c-__lower_min] : c;
}

const char* ctype<char>::do_toupper (char* low, const char* high) const {
  for ( ; low<high; ++low)
    if (is(lower,*low))
      *low=__to_upper_tab[(unsigned char) *low-__lower_min];
  return low;
}

char ctype<char>::do_tolower(char c) const {
  return is(upper,c)? __to_lower_tab[(unsigned char)c-__upper_min] : c;
}

const char* ctype<char>::do_tolower(char* low, const char* high) const {
  for (; low < high; ++low)
    if (is(upper,*low))
      *low=__to_lower_tab[(unsigned char) *low-__upper_min];
  return low;
}

const char* ctype<char>::is (const char* lo, const char* hi, mask* vec) const {
  while (lo != hi)
    *vec++ = __table[(unsigned char)*lo++];
  return hi;
}

const char* ctype<char>::scan_is (ctype_base::mask m,
    const char* lo, const char* hi) const
{
  while (lo != hi && !(__table[(unsigned char) *lo] & m))
    ++lo;
  return lo;
}

const char* ctype<char>::scan_not (ctype_base::mask m,
    const char* lo, const char* hi) const
{
  while (lo != hi && (__table[(unsigned char) *lo] & m))
    ++lo;
  return lo;
}

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

collate_table<char> _RWSTDExport collate_impl<char>::__default_table =
{
  0, { NULL, NULL, NULL, 0, 0, 0 }
};

numpunct_init<char> numpunct_impl<char>::ivals_ =
{
  false,        // Don't kill me please
  '.',          // Decimal point
  ',',          // Thousands separator
  "",           // Digit grouping rule
  "true",       // Boolean true value as string
  "false",      // Boolean false value as string
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RW_STD_LOCALE
