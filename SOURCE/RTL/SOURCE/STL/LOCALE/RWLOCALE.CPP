#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * locale.cpp - Source for the Standard Library locale classes
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
#include <istream>
#include <ostream>
#include <rw/numbrw>
#include <rw/lochelp>
#include <rw/rwstderr.h>

#ifdef _RWSTD_MULTI_THREAD
#include <rw/stdmutex.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifdef _RWSTD_LOCALIZED_ERRORS
  extern const unsigned int _RWSTDExport  __rw_LocaleNotPresent = _RWSTD_ERROR_LOCALE_NOT_PRESENT;
  extern const unsigned int _RWSTDExport  __rw_LocaleInitCalledTwice = _RWSTD_ERROR_LOCALE_INIT_CALLED_TWICE;
  extern const unsigned int _RWSTDExport  __rw_LocaleNullPointer =  _RWSTD_ERROR_LOCALE_NULL_POINTER;
  extern const unsigned int _RWSTDExport  __rw_LocaleBadName = _RWSTD_ERROR_LOCALE_BAD_NAME;
  extern const unsigned int _RWSTDExport  __rw_LocaleErrorName = _RWSTD_ERROR_LOCALE_ERROR_NAME;
  extern const unsigned int _RWSTDExport  __rw_LocaleCodeConvFailed = _RWSTD_ERROR_LOCALE_CODE_CONV_FAILED;
#else 
  extern const char _RWSTDExportFunc(*) __rw_LocaleNotPresent = "Facet not present in locale";
  extern const char _RWSTDExportFunc(*) __rw_LocaleInitCalledTwice = "locale::__initid() called twice";
  extern const char _RWSTDExportFunc(*) __rw_LocaleNullPointer = "Tried to construct a locale from a NULL pointer.";
  extern const char _RWSTDExportFunc(*) __rw_LocaleBadName = "System does not recognize this locale name.";
  extern const char _RWSTDExportFunc(*) __rw_LocaleErrorName = "Error constructing locale name.";
  extern const char _RWSTDExportFunc(*) __rw_LocaleCodeConvFailed = "Code conversion failed.";
#endif // _RWSTD_LOCALIZED_ERRORS
// --------------------------
// Class ref_counted members.
// --------------------------

ref_counted::~ref_counted () { }

// ----------------------------
// Class locale_id_imp members.
// ----------------------------

size_t _RWSTDExport locale_id_imp::__last_used_id;

#ifdef _RWSTD_MULTI_THREAD
_RWSTDMutex _RWSTDExport locale_id_imp::__mutex;
#endif

void locale_id_imp::__initid () const {
  if (!__id_value) {
    #ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(__mutex);
    #endif

    if (!__id_value)
      #ifdef _RWSTD_NO_MUTABLE
      *(size_t*)&  /* cast away const */
      #endif
        __id_value = ++__last_used_id;
  }
}

// -------------------------
// Class locale_imp members.
// -------------------------

locale_imp::locale_imp
    (size_t sz, size_t refs): ref_counted(refs),
    vec_(sz,(facet_imp*)NULL),
    native_cats_(0), named_cats_(0), named_(false)
{
  names_.resize(locale::__rw_num_categories,string(""));
}

locale_imp::locale_imp

    (const locale_imp &other, size_t refs):
    ref_counted(refs), vec_(other.vec_), names_(other.names_),
    native_cats_(other.native_cats_), named_cats_(other.named_cats_),
    named_(other.named_)
{
  size_t i=vec_.size();
  while (i)
    ref_counted::add_possible_reference(vec_[--i]);
}

locale_imp::~locale_imp ()
{
  size_t i = vec_.size();
  while (i)
    ref_counted::remove_possible_reference(vec_[--i]);
}

const char * locale_imp::category_name
    (locale::category cat) const
{
  locale::category mask=locale::__rw_first_category;
  size_t i=0;

  for ( ; i<locale::__rw_num_categories; i++,mask<<=1)
    if (cat&mask)
      return names_[i].c_str();

  return "";
}

// ------------------------------
// Class use_Clib_locale members.
// ------------------------------

// Constructor changes the C library locale, saving the old locale to be
// restored by the destructor.

use_Clib_locale::use_Clib_locale
    (const char *name,int cat)
{
  previous_locale_name=setlocale(saved_cat=cat,NULL);
  if (previous_locale_name)
  {

    char * tmp = new char[strlen(previous_locale_name)+1];

#ifdef __BORLANDC__
    char cat_names[][16] = {"LC_COLLATE", "LC_CTYPE", "LC_MONETARY", "LC_NUMERIC", "LC_TIME", 
                            "LC_MESSAGES", "LC_ALL" };
    char * cur_cat;

    // Get category name as character string
    switch (cat)
    {
      case LC_COLLATE :
        cur_cat = cat_names[0];
        break;
      case LC_CTYPE :
        cur_cat = cat_names[1];
        break;        
      case LC_MONETARY :
        cur_cat = cat_names[2];
        break;        
      case LC_NUMERIC :
        cur_cat = cat_names[3];
        break;
      case LC_TIME :
        cur_cat = cat_names[4];
        break;        
      default :
        cur_cat = cat_names[6];
    }    
    // Look for the category name
    char * parsed_name = strstr(previous_locale_name,cur_cat);
    if (parsed_name)
      previous_locale_name = parsed_name;
    // Look past the '=' to find start of locale name
    parsed_name = strchr(previous_locale_name,'=');
    if (parsed_name)
      strcpy(tmp,parsed_name+1);
    else
      strcpy(tmp,previous_locale_name);
    // Mark end of locale name
    char * name_end = strchr(tmp,'\n');
    if (name_end)
      *name_end = '\0';
#else
    strcpy(tmp,previous_locale_name);
#endif // __BORLANDC__    
    previous_locale_name=tmp;
  }
  setlocale(cat,name);
}

// Destructor restores the C library locale that was in effect when the object
// was constructed.

use_Clib_locale::~use_Clib_locale (void)
{
  if (previous_locale_name) {
    setlocale(saved_cat,previous_locale_name);
    delete[] previous_locale_name;
  }
}

//---------------------------------
// Class locale mutex
//---------------------------------

#ifdef _RWSTD_MULTI_THREAD
#ifndef _MSC_VER
static _RWSTDMutex locale_global_mutex;
#else
_RWSTDMutex _RWSTDExport locale_global_mutex;
#endif
#endif

#ifndef _RWSTD_NO_NAMESPACE
} namespace std { // Leave __rwstd, back to std
#endif

//---------------------------------
// Class locale static data members
//---------------------------------

#ifndef _RWSTD_NO_STI_SIMPLE
const locale::category  locale::collate, locale::ctype, locale::monetary,
                        locale::numeric, locale::time, locale::messages,
                        locale::all, locale::none,
                        locale::__rw_collate_category,
                        locale::__rw_ctype_category, 
                        locale::__rw_messages_category, 
                        locale::__rw_Clib_LC_constants, 
                        locale::__rw_num_categories,
                        locale::__rw_first_category;
#endif

// ----------------------------------
// Class locale non-template members.
// ----------------------------------

__RWSTD::locale_imp _RWSTDExportFunc(*) locale::__the_classic_locale;
__RWSTD::locale_imp _RWSTDExportFunc(*) locale::__the_native_locale;
__RWSTD::locale_imp _RWSTDExportFunc(*) locale::__global;

// Static initialization method, called exactly once, the first time a locale
// is constructed.

void locale::init (void) {
  _RWSTD_THROW(__global,logic_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleInitCalledTwice).msgstr());

  // Create locale_imp objects for the classic ("C") and native (") locales.
  // Each has an extra use-count to make it immortal.  The latter is also the
  // locale_imp for the initial global locale, so we start it with a ref-count
  // of 2; the second count will go away if some other locale is made global.

  __the_classic_locale = new __RWSTD::locale_imp (10,1);

  __the_classic_locale->named_ = true;
  __the_classic_locale->big_name_ = "C";
  for (int i = 0, j = (all&(~all+1)); (j & all); ++i, j <<= 1)
    __the_classic_locale->names_[i] = __the_classic_locale->big_name_;
  __the_native_locale = new __RWSTD::locale_imp (10,2);
  __the_native_locale->native_cats_ = all;
  __the_native_locale->named_ = true;
  __global = __the_classic_locale;
}

// The following constructor makes a locale composed of "byname" facets, and
// assigns it a name.

locale::locale (const char* std_name)
{
  if (!__global)
    init();

  _RWSTD_THROW(!std_name,runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleNullPointer).msgstr());

  if (strcmp("C",std_name)==0 || strcmp("POSIX",std_name)==0)
    __RWSTD::ref_counted::add_reference(__imp=__the_classic_locale);
  else if (strcmp("",std_name)==0)
    __RWSTD::ref_counted::add_reference(__imp=__the_native_locale);
  else {
    // Create a new locale_imp with one reference.
    __imp = new __RWSTD::locale_imp(10,1);
    // Call vendor-dependent method to break big name into category names.
    bool good_name=__RWSTD::locale_imp::parse_name
        (__imp->names_,std_name);
    _RWSTD_THROW(!good_name,runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleBadName).msgstr());
    __imp->named_cats_ = all;
    __imp->named_ = true;
  }
}

// The following constructor copies all facets from the first argument, except
// those that are part of the specified categories, which are copied from the
// second argument.  If both locales have a name, the resulting locale has a
// name also.

locale::locale (const locale& first, const locale& second, category cat):
    __imp(new __RWSTD::locale_imp(*first.__imp,1))
{
  if (cat & __rw_Clib_LC_constants)
    // Call vendor-supplied routine to map C-library LC_xxx constants into
    // C++ library locale categories.
    cat = __RWSTD::locale_imp::map_category(cat);

  size_t i,end;
  category mask;
  __RWSTD::facet_imp *f;

  // Copy implicit facets by copying flags and name pieces that will tell us
  // how to construct them (ie. make them explicit) if they are called for.

  __imp->named_cats_ =
      (__imp->named_cats_&~cat) | (second.__imp->named_cats_&cat);
  __imp->native_cats_ =
      (__imp->native_cats_&~cat) | (second.__imp->native_cats_&cat);

  for (i=0,mask=__rw_first_category; i<__rw_num_categories; i++,mask<<=1)
    if (mask&cat && mask&second.__imp->named_cats_)
      __imp->names_[i]=second.__imp->names_[i];

  // Remove all explicit facets of the requested categories from the copy we
  // just made of the first locale_imp.
  for (i=0,end=__imp->vec_.size(); i<end; i++) {
    f=__imp->vec_[i];
    if (f && (cat&f->__category)) {
      __RWSTD::ref_counted::remove_reference(f);
      __imp->vec_[i]=NULL;
    }
  }

  // Install all explicit facets of the requested categories from the second
  // locale_imp into the new one.
  for (i=0,end=second.__imp->vec_.size(); i<end; i++) {
    f=second.__imp->vec_[i];
    if (f && (cat&f->__category)) {
      __RWSTD::ref_counted::remove_possible_reference(__imp->vec_[i]);
      __RWSTD::ref_counted::add_reference(__imp->vec_[i]=f);
    }
  }

  __imp->named_ = first.__imp->named_ && second.__imp->named_;
}

// The following constructor copies all facets from the first argument except
// the ones in the categories specified by the third argument, which it gets
// (implicitly or explicitly) by name using the name in the second argument.

locale::locale (const locale& other, const char *std_name, category cat):
    __imp(new __RWSTD::locale_imp(*other.__imp,1))
{
  if (!std_name)
    std_name = "";

  if (cat & __rw_Clib_LC_constants)
    cat = __RWSTD::locale_imp::map_category(cat);

  size_t i,end;
  category mask;
  __RWSTD::facet_imp *f;

  // Remove all explicit facets of the requested categories from the copy we
  // just made of the other locale_imp.
  for (i=0,end=__imp->vec_.size(); i<end; i++) {
    f=__imp->vec_[i];
    if (f && (cat&f->__category)) {
      __RWSTD::ref_counted::remove_reference(f);
      __imp->vec_[i]=NULL;
    }
  }

  __RWSTD::locale_vector<string> new_names(__imp->names_.size());
  bool good_name=__RWSTD::locale_imp::parse_name(new_names,std_name);
  _RWSTD_THROW(!good_name,runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleBadName).msgstr());

  // Flag the new categories of facets to be constructed by name when they are
  // first called for, and update the name to be used for those categories.
  __imp->named_cats_ |= cat;
  for (mask=__rw_first_category,i=0; i<__rw_num_categories; i++,mask<<=1)
    if (mask&cat)
      __imp->names_[i]=std_name;

  // If the other locale has a name, the new one does too.
  __imp->named_ = other.__imp->named_;
}

// Equality operator.

bool locale::operator == (const locale& other) const {
  return ((__imp == other.__imp) ||
          (name() != "*" && name() == other.name()));
}

// Assignment operator.

const locale & locale::operator = (const locale& other) _RWSTD_THROW_SPEC_NULL
{
  if (__imp != other.__imp) {
    __RWSTD::ref_counted::remove_reference(__imp);
    __RWSTD::ref_counted::add_reference(__imp=other.__imp);
  }
  return *this;
}

// Return the locale name.

string locale::name (void) const
{
  if (!__imp->named_)
    return "*";
  if (__imp->big_name_.length()==0) {
    bool good=__RWSTD::locale_imp::build_name
        (__imp->big_name_,__imp->names_);
    _RWSTD_THROW(!good,runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleErrorName).msgstr());
  }
  return __imp->big_name_;
}

// Private implementation methods:

// The following function retrieves an implicit facet from a cache, or creates
// it if needed (via call to the passed call-back function), and makes it an
// explicit facet of the locale.

__RWSTD::facet_imp* locale::__make_explicit (const id &facet_id,
     bool ok_implicit, category facet_cat, __facet_maker_func maker) const
{
  __RWSTD::facet_imp *f=NULL;

  // Determine whether the implicit facet has by-name or native or classic
  // behavior, based on its category and flags in the locale_imp that track
  // how the locale was constructed (i.e. which categories have which kinds
  // of behavior by default).  And locate the "base" locale_imp where facets
  // with the indicated kind of behavior are cached.

  __RWSTD::locale_imp *base;
  if (__imp->named_cats_ & facet_cat)
    base=NULL;
  else if (__imp->native_cats_ & facet_cat)
    base=__the_native_locale;
  else
    base=__the_classic_locale;

  if (base) {
    size_t index(facet_id);
    if (index >= base->vec_.size())
      base->vec_.resize(index+1,NULL);
    f=base->vec_[index];
  }

  if (!f) {
    #ifndef _RWSTD_NO_BAD_CAST
    _RWSTD_THROW_NO_MSG(!ok_implicit,bad_cast);
    #else
    _RWSTD_THROW(!ok_implicit,runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleNotPresent).msgstr());
    #endif

    #ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(__RWSTD::locale_global_mutex);
    #endif

    if (base) {
      size_t index(facet_id);
      if (index >= base->vec_.size())
        base->vec_.resize(index+1,NULL);
      f=base->vec_[index];
    }

    if (!f) {
      int t;
      const char *name="";
      if (__imp->named_cats_ & facet_cat) {
        t=2; name=__imp->category_name(facet_cat);
      } else if (__imp->native_cats_ & facet_cat)
        t=1;
      else
        t=0;

      f=maker(t,name,0);

      if (base && base!=__imp)
        locale(base).__install(f,facet_id);
    }
  }

  __install(f,facet_id);
  return f;
}

// Make the passed facet an explicit facet of this locale.

void locale::__install (__RWSTD::facet_imp* f,const id& i) const
{
  if (!(f->__flags & f->__initdone)) {
    i.__initid();  // initialize facet id if not done yet.
    f->__initfacet(this);
    f->__flags |= f->__initdone;
  }

  size_t index(i);
  if (index>=__imp->vec_.size())
    __imp->vec_.resize(index+1,NULL);
  __RWSTD::ref_counted::remove_possible_reference(__imp->vec_[index]);
  __RWSTD::ref_counted::add_reference(__imp->vec_[index]=f);
}

// Static members:

// Change the global locale, returing the previous global locale.  This
// function logically replaces the C library's setlocale().  It calls
// setlocale(LC_ALL,name) if the new global locale has a name, otherwise
// the C library locale is not modified.

locale locale::global (const locale& loc)
{
  #ifdef _RWSTD_MULTI_THREAD
  _RWSTDGuard guard(__RWSTD::locale_global_mutex);
  #endif

  locale previous(__global);
  __RWSTD::ref_counted::remove_reference(__global);
  __RWSTD::ref_counted::add_reference(__global=loc.__imp);

  if (__global->named_) {
    bool it_failed=(setlocale(LC_ALL,loc.name().c_str())==NULL);
    _RWSTD_THROW(it_failed,runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleBadName).msgstr());
  }

  return previous;
}

const locale& locale::classic()       // the "C" locale
{
  if (!__global) init();
  static locale cl(__the_classic_locale);
  return cl;
}

// ----------------------------------------------------------
// Facet specialization codecvt<char,char,mbstate_t> members.
// ----------------------------------------------------------

locale::id _RWSTDExport codecvt<char,char,mbstate_t>::id;

codecvt<char,char,mbstate_t>::~codecvt() { }

codecvt_base::result
codecvt<char,char,mbstate_t>::do_out (mbstate_t& /*state*/,
    const char* from, const char* /*from_end*/, const char*& from_next,
          char* to, char* /*to_end*/, char*& to_next ) const
{
   to_next = to;
   from_next = from;
   return noconv; 
}

codecvt_base::result _RWSTDExport
codecvt<char,char,mbstate_t>::do_in (mbstate_t& /*state*/,
    const char* from, const char* /*from_end*/, const char*& from_next,
          char* to, char* /*to_end*/, char*& to_next ) const
{
   to_next = to;
   from_next = from;
   return noconv; 
}

codecvt_base::result _RWSTDExport
codecvt<char,char,mbstate_t>::do_unshift (mbstate_t& /*state*/,
          char* /*to*/, char* /*to_end*/, char*& /*to_next*/ ) const
{
  return noconv;
}

bool codecvt<char,char,mbstate_t>::do_always_noconv () const
    _RWSTD_THROW_SPEC_NULL
{
  return true;
}

int codecvt<char,char,mbstate_t>::do_encoding() const
    _RWSTD_THROW_SPEC_NULL
{
  return 1;
}

int codecvt<char,char,mbstate_t>::do_length
    (const mbstate_t&,const char* from,const char* from_end,size_t max) const
{
  size_t len = from_end - from;
  return len < max ? len : max; 
}

int codecvt<char,char,mbstate_t>::do_max_length () const _RWSTD_THROW_SPEC_NULL
{
  return 1;
}

#ifndef _RWSTD_NO_WIDE_CHAR 
 
// -------------------------------------------------------------
// Facet specialization codecvt<wchar_t,char,mbstate_t> members.
// -------------------------------------------------------------

locale::id _RWSTDExport codecvt<wchar_t,char,mbstate_t>::id;
codecvt<wchar_t,char,mbstate_t>::~codecvt () { }

codecvt_base::result codecvt<wchar_t,char,mbstate_t>::do_out
    (mbstate_t&, const wchar_t* from, const wchar_t* from_end,
     const wchar_t*& from_next, char* to, char* to_end, char*& to_next) const
{
  // Result area must be big enough to contain the biggest possible multi-byte
  // character representation ... perhaps we should throw here?
  if ((to_end-to) < MB_CUR_MAX)
    return error;

  codecvt_base::result res=ok;
  char *safe_to_end=to_end-(MB_CUR_MAX-1);
  for (from_next=from,to_next=to; from_next<from_end && to_next<safe_to_end;
       from_next++)
  {
    int n=wctomb(to_next,*from_next);
	if (n>0)
		to_next+=n;
	else {
		if (n<0)
			res=error;
      break;
    }
  }

// try to read additional characters from the from buffer
  char *temp = new char[MB_CUR_MAX];
  while (from_next<from_end && res != error) {
	  int n=wctomb(temp,*from_next);
	  if (n>0) {
		  if (to_next+n < to_end)
			  wctomb(to_next,*from_next);
		  else
			  break;
		  to_next+=n;
	  }
	  else {
		  if (n<0)
			  res=error;
		  break;
	  }
  }
  delete[] temp;

  if (res==ok && from_next!=from_end)
    res=partial;

  return res;
}

codecvt_base::result codecvt<wchar_t,char,mbstate_t>::do_in
    (mbstate_t&, const char* from, const char* from_end,
     const char*& from_next, wchar_t* to, wchar_t* to_end,
     wchar_t*& to_next) const
{
  codecvt_base::result res=ok;
  for (from_next=from,to_next=to; from_next<from_end && to_next<to_end;
       to_next++)
  {
    int n=mbtowc(to_next,from_next,from_end-from_next);
    if (n>0)
      from_next+=n;
    else {
      if (n==0 || to_next>to)
        res=partial;
      else
        res=error;
      break;
    }
  }
  return res;
}

codecvt_base::result
codecvt<wchar_t,char,mbstate_t>::do_unshift (mbstate_t& /*state*/,
    char* /*to*/, char* /*to_end*/, char*& /*to_next*/) const
{
  return noconv;
}

bool codecvt<wchar_t,char,mbstate_t>::do_always_noconv () const
    _RWSTD_THROW_SPEC_NULL
{
  return false;
}

int codecvt<wchar_t,char,mbstate_t>::do_encoding () const
    _RWSTD_THROW_SPEC_NULL
{
  return -1;
}

// Return the number of wchar_t's in the range from to from_end whose char
// (multi-byte) representations will fit in a buffer of size max.

int codecvt<wchar_t,char,mbstate_t>::do_length (const mbstate_t&,
    const char* from, const char* from_end, size_t max) const
{
  size_t n=from_end-from;
  return n<max? n : max;
}

int codecvt<wchar_t,char,mbstate_t>::do_max_length () const
    _RWSTD_THROW_SPEC_NULL
{
  return 1;
}

wstring codecvt<wchar_t,char,mbstate_t>::in (const string &s) const
{
  wchar_t result_buf[1000];
  size_t max=sizeof result_buf/sizeof(wchar_t);
  size_t n=mbstowcs(result_buf,s.c_str(),max);
  _RWSTD_THROW(n==size_t(-1),runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleCodeConvFailed).msgstr());
  if (n==max) {
    // 1000 was too small, allocate something larger and try again ... but
    // for now we just return the truncated result.
  }
  return wstring(result_buf,(wstring::size_type)n);
}

string codecvt<wchar_t,char,mbstate_t>::out (const wstring &s) const
{
  char result_buf[1000];
  size_t n=wcstombs(result_buf,s.c_str(),sizeof result_buf);
  _RWSTD_THROW(n==size_t(-1),runtime_error,__RWSTD::except_msg_string(__RWSTD::__rw_LocaleCodeConvFailed).msgstr());
  if (n==sizeof result_buf) {
    // 1000 was too small, allocate something larger and try again ... but
    // for now we just return the truncated result.
  }
  return string(result_buf,(string::size_type)n);
}

#endif // _RWSTD_NO_WIDE_CHAR

#ifdef _RWSTD_NO_MEMBER_TEMPLATES
// If your compiler does not support member templates, we supply explicit
// versions of operator () for string and (if your compiler supports wide
// chars) wstring.

bool locale::operator() (const string &s1,const string &s2) const {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
  return use_facet<_RW_STD::collate<char> >(*this).compare
      (s1.data(),s1.data()+s1.length(),s2.data(),s2.data()+s2.length()) < 0;
#else
  return use_facet(*this,(_RW_STD::collate<char>*)0).compare
      (s1.data(),s1.data()+s1.length(),s2.data(),s2.data()+s2.length()) < 0;
#endif
}

#ifndef _RWSTD_NO_WIDE_CHAR
bool locale::operator() (const wstring &s1,const wstring &s2) const {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
  return use_facet<_RW_STD::collate<wchar_t> >(*this).compare
      (s1.data(),s1.data()+s1.length(),s2.data(),s2.data()+s2.length()) < 0;
#else
  return use_facet(*this,(_RW_STD::collate<wchar_t>*)0).compare
      (s1.data(),s1.data()+s1.length(),s2.data(),s2.data()+s2.length()) < 0;
#endif
}
#endif // _RWSTD_NO_WIDE_CHAR
#endif //  _RWSTD_NO_MEMBER_TEMPLATES

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd { // Leave std, enter implementation namespace
#endif

const char digit_map_base::punct_chars[] =
    { '0','-','+','X','x','E','e' };

const char digit_map_base::digit_chars[] =
    { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',
                                              'a','b','c','d','e','f' };
const char digit_map_base::char_values[] =
    { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,10,11,12,13,14,15 };

// Class rwstd::digit_writer_base member functions.

digit_writer_base::
digit_writer_base (ios_base &b): io(b), flags(b.flags()),
    precision(b.precision()), width(b.width()), iprecision(0), num_groups(0),
    fractional(false), separable(true), start(buffer), end(buffer)
{
  ios_base::fmtflags f=flags&ios_base::basefield;
  if (f==ios_base::hex)
    radix=16;
  else if (f==ios_base::oct)
    radix=8;
  else
    radix=10;

  f=flags&ios_base::adjustfield;
  if (f==ios_base::left)
    adjust=left;
  else if (f==ios_base::internal)
    adjust=internal;
  else
    adjust=right;
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RW_STD_LOCALE

