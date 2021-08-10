#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * vendor.cpp - Source for the Standard Library locale classes
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
#ifdef __BORLANDC__
#define __USELOCALES__
#endif

#include <compnent.h>
#ifdef _RW_STD_LOCALE

#include <locale>
#include <rw/lochelp>
#include <rw/locvector>

#ifndef _RWSTD_COMPILE_INSTANTIATE
#include <rw/numbrw>
#endif

#ifndef _RWSTD_NO_NAMESPACE
 namespace __rwstd {
using namespace std;
#endif

// ---------------------------------------------------------
// Implementation class locale_imp vendor-dependent members.
// ---------------------------------------------------------

// Translate a LC_xxx constant into its associated locale::category bit mask.

locale::category locale_imp::map_category
    (locale::category cat)
{
  switch (cat) {
   case LC_ALL:
    return locale::all;
   case LC_CTYPE:
    return locale::__rw_ctype_category;
   case LC_COLLATE:
    return locale::__rw_collate_category;
   case LC_MONETARY:
    return locale::monetary;
   case LC_NUMERIC:
    return locale::numeric;
   case LC_TIME:
    return locale::time;
#ifndef _RWSTD_NO_CATOPEN_CATGETS
   case LC_MESSAGES:
    return locale::__rw_messages_category;
#endif
  }

  // Should we throw here instead?
  return locale::none;
}

// Parse a (possibly abbreviated) locale name into its component category
// names.

bool locale_imp::parse_name
       (locale_vector<string> &names,const char *name)
{
  string previous_locale(setlocale(LC_ALL,NULL));

  if (!setlocale(LC_ALL,name))
    return false;

  names[0]=clean_name(setlocale(LC_COLLATE,name));
  names[1]=clean_name(setlocale(LC_CTYPE,name));
  names[2]=clean_name(setlocale(LC_MONETARY,name));
  names[3]=clean_name(setlocale(LC_NUMERIC,name));
  names[4]=clean_name(setlocale(LC_TIME,name));
#ifndef _RWSTD_NO_CATOPEN_CATGETS
  names[5]=clean_name(setlocale(LC_MESSAGES,name));
#endif

  setlocale(LC_ALL,previous_locale.c_str());
  return true;
}

// Build a full locale name from the locale's category names.

bool locale_imp::build_name
       (string &name,const locale_vector<string> &names)
{
  string previous_locale(setlocale(LC_ALL,NULL));

  setlocale(LC_COLLATE,  names[0].c_str());
  setlocale(LC_CTYPE,    names[1].c_str());
  setlocale(LC_MONETARY, names[2].c_str());
  setlocale(LC_NUMERIC,  names[3].c_str());
  setlocale(LC_TIME,     names[4].c_str());
#ifndef _RWSTD_NO_CATOPEN_CATGETS
  setlocale(LC_MESSAGES, names[5].c_str());
#endif

  name=setlocale(LC_ALL,NULL);

  setlocale(LC_ALL,previous_locale.c_str());
  return true;
}

// -----------------------------------------------
// Implementation class digit_reader_base members.
// -----------------------------------------------

// to_ulong_dec -- converts a string of one or more digits to unsigned long.
// Caller should ensure that b is strictly less than e.

unsigned long digit_reader_base::to_ulong_dec
    (char *b,char *e)
{
  char *beg=b,*end=e;
  unsigned long sum=*beg++;

  if (beg<end) {
    sum=sum*10+*beg++;
    if (beg<end) {
      sum=sum*10+*beg++;
      if (beg<end) {
        sum=sum*10+*beg++;
        while (beg<end) {
          unsigned long oldsum=sum;
          sum=sum*10+*beg++;
          if (sum<oldsum) {
            error=overflow;
            break;
          }
        }
      }
    }
  }
  return sum;
}

unsigned long digit_reader_base::to_ulong (char* eod) {
  unsigned long sum=0;
  int i;

  if (!error) {
    char *d=digits;
    if (d==eod)
      error=no_digits;
    else {
      while (*d==0 && d!=eod) d++;

      switch (radix) {
       case 10:
        if (d<eod)
          sum=to_ulong_dec(d,eod);
        break;

       case 16:
        if ((i=numeric_limits<unsigned long>::digits-(eod-d)*4) < 0 &&
            (i<-4 || (16>>-i <= *d)))
          error=overflow;
        else
          for ( ; d!=eod; d++)
            sum=(sum<<4)+*d;
        break;

       case 8:
        if ((i=numeric_limits<unsigned long>::digits-(eod-d)*3) < 0 &&
            (i<-3 || (8>>-i <= *d)))
          error=overflow;
        else
          for ( ; d!=eod; d++)
            sum=(sum<<3)+*d;
        break;
      }
    }
  }
  return sum;
}

#ifdef _RWSTD_LONG_LONG

unsigned _RWSTD_LONG_LONG digit_reader_base::to_ulong_ulong (char* eod) {
  unsigned _RWSTD_LONG_LONG value;

  if (error)
    value=0;
  else {
    char buf[digit_buf_size],*p=buf,*q=digits;
    static char pattern[] = "%" _RWSTD_LONG_LONG_PRINTF_PREFIX "d";
    while (q<eod)
      *p++="0123456789ABCDEF"[*q++];
    *p=0;
    pattern[sizeof pattern-2]=(radix==10? 'd' : radix==16? 'x' : 'o');
    sscanf(buf,pattern,&value);
  }

  return value;
}

#endif // _RWSTD_LONG_LONG

void *digit_reader_base::to_pointer (char *eod) {
  void *result=NULL;
  if (!error) {
    char buf[digit_buf_size],c,*p=buf,*d=digits;
    while (d<eod)
      *p++=((c=*d++)>15)? c : digit_map_base::digit_chars[c];
    *p=0;
    sscanf(buf,"%p",&result);
  }
  return result;
}

float digit_reader_base::to_float (char* eod) {
  float result=0;
  to_floating_point(eod,"%e",&result);
  return result;
}

double digit_reader_base::to_double (char* eod) {
  double result=0;
  to_floating_point(eod,"%le",&result);
  return result;
}

long double digit_reader_base::to_long_double (char* eod) {
  long double result=0;
  to_floating_point(eod,"%Le",&result);
  return result;
}

void digit_reader_base::to_floating_point
    (char* eod, char *fmt, void *result)
{
  if (!error) {
    char buf[digit_buf_size],*p=buf,*d=digits,*dp=NULL;
    if (negative)
      *p++='-';
    while (d<frac_beg)
      *p++=digit_map_base::digit_chars[*d++];
    if (d<exp_beg) {
      *(dp=p++)='.';
      do *p++=digit_map_base::digit_chars[*d++];
      while (d<exp_beg);
    }
    if (d<eod) {
      *p++='e';
      *p++=exp_negative? '-' : '+';
      do *p++=digit_map_base::digit_chars[*d++];
      while (d<eod);
    }
    *p=0;

    if (!dp)
      sscanf(buf,fmt,result);
    else {
      use_Clib_locale clocale("C",LC_NUMERIC);
      sscanf(buf,fmt,result);
    }
  }
}

// -----------------------------------------------
// Implementation class digit_writer_base methods.
// -----------------------------------------------

void digit_writer_base::digitize (const void *value)
{
  end=start+sprintf(start,"%p",value);
}

void digit_writer_base::get_pattern(char *p, char *prefix, bool is_signed)
{
  *p++='%';
  if (flags&ios_base::showpos)
    *p++='+';
  if (flags&ios_base::showbase)
    *p++='#';
  if (iprecision) {
    *p++='.';
    *p++='*';
  }

  while (*prefix)
    *p++=*prefix++;

  switch (radix) {
   case 16:
    *p++=(flags&ios_base::uppercase)? 'X' : 'x';
    break;
   case 8:
    *p++='o';
    break;
   default:
    *p++=is_signed? 'd' : 'u';
  }

  *p=0;

}

void digit_writer_base::digitize (unsigned short value)
{
  char pattern[16];
  get_pattern(pattern,"h",false);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

void digit_writer_base::digitize (short value)
{
  char pattern[16];
  get_pattern(pattern,"h",true);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

void digit_writer_base::digitize (unsigned int value)
{
  char pattern[16];
  get_pattern(pattern,"",false);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

void digit_writer_base::digitize (int value)
{
  char pattern[16];
  get_pattern(pattern,"",true);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

void digit_writer_base::digitize (unsigned long value)
{
  char pattern[16];
  get_pattern(pattern,"l",false);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

void digit_writer_base::digitize (long value)
{
  char pattern[16];
  get_pattern(pattern,"l",true);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

#ifdef _RWSTD_LONG_LONG

void digit_writer_base::digitize (unsigned _RWSTD_LONG_LONG value)
{
  char pattern[16];
  get_pattern(pattern,_RWSTD_LONG_LONG_PRINTF_PREFIX,false);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

void digit_writer_base::digitize (_RWSTD_LONG_LONG value)
{
  char pattern[16];
  get_pattern(pattern,_RWSTD_LONG_LONG_PRINTF_PREFIX,true);
  end=start+(iprecision? sprintf(start,pattern,iprecision,value) :
                         sprintf(start,pattern,value));
}

#endif // _RWSTD_LONG_LONG

bool digit_writer_base::get_f_pattern(char *p, char prefix)
{
  *p++='%';
  if (flags&ios_base::showpos)
    *p++='+';
  if (flags&ios_base::showpoint)
    *p++='#';
  bool use_precision=false;
  if (precision || flags&ios_base::fixed) {
    use_precision=true;
    *p++='.';
    *p++='*';
  }

  if (prefix)
    *p++ = prefix;

  ios_base::fmtflags f=flags&ios_base::floatfield;
  *p++=(f==ios_base::scientific)? (flags&ios_base::uppercase)? 'E' : 'e' :
       (f==ios_base::fixed)? 'f' : (flags&ios_base::uppercase)? 'G' : 'g';

  *p=0;
  fractional=true;
  radix=10;
  return use_precision;
}

void digit_writer_base::digitize (double value)
{
  char pattern[16];
  bool use_precision = get_f_pattern(pattern,0);
  // if value is not a formatable number then disable the relevant parts of formatting
  numeric_limits<double> nl;
  if (value == nl.infinity() || value != value) {  // IEEE754 says that a NaN does not compare equal to itself
	  fractional = false;
	  separable = false;
  }
  end=start+(use_precision? sprintf(start,pattern,precision,value) :
                            sprintf(start,pattern,value));
}

#ifndef _RWSTD_NO_LONG_DOUBLE
void digit_writer_base::digitize (long double value)
{
  char pattern[16];
  bool use_precision = get_f_pattern(pattern,'L');
  end=start+(use_precision? sprintf(start,pattern,precision,value) :
                            sprintf(start,pattern,value));
}
#endif // _RWSTD_NO_LONG_DOUBLE

// Calculate the number and pattern of separators needed if any for the passed
// number of integral digits and grouping pattern.

int digit_writer_base::calc_groups
    (int nDigits,const char *grouping)
{
  group=groups+sizeof groups;
  num_groups=0;

  const char *grp=grouping;
  if (*grp) {
    int g=*grp++ & 0x0F;
    if (g<nDigits) {
      do {
        *--group=(char) g;
        num_groups++;
        nDigits-=g;
        if (group==groups || *grp==CHAR_MAX)
          break;
        if (*grp)
          g=*grp++ & 0x0F;
      } while (g<nDigits);
    }
  }
  return nDigits;
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RW_STD_LOCALE

