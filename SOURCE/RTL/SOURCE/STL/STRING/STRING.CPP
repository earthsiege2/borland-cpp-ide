#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * string.cpp - Source for the Standard Library string classes
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
#include <string>
#include <rw/rwstderr.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#if defined (_RWSTD_MULTI_THREAD) && defined(_RWSTD_ONE_STRING_MUTEX)
  _RWSTDMutex _RWSTDExport __rw_string_mutex;
#endif /* _RWSTD_MULTI_THREAD */

#ifdef _RWSTD_NO_STATIC_DEF3
  unsigned long _RWSTDExport __nullref[sizeof(__string_ref_rep<_RW_STD::allocator<char> >)/4 + 2];
  bool _RWSTDExport __nullref_initialized = false;
#endif
#ifdef _RWSTD_LOCALIZED_ERRORS
  
  extern const unsigned int _RWSTDExport  __rwse_InvalidSizeParam = _RWSTD_ERROR_INVALID_SIZE_PARAM; 

  extern const unsigned int _RWSTDExport __rwse_PosBeyondEndOfString = _RWSTD_ERROR_POS_BEYOND_END_OF_STRING; 

  extern const unsigned int _RWSTDExport __rwse_ResultLenInvalid = _RWSTD_ERROR_RESULT_LEN_INVALID;   

  extern const unsigned int _RWSTDExport __rwse_StringIndexOutOfRange = _RWSTD_ERROR_STRING_INDEX_OUT_OF_RANGE; 
  extern const unsigned int _RWSTDExport __rwse_UnexpectedNullPtr = _RWSTD_ERROR_UNEXPECTED_NULL_PTR; 

#else
  extern const char _RWSTDExportFunc(*) __rwse_InvalidSizeParam = "invalid string size parameter in function: %s \n size: %d is greater than maximum size: %d";

  extern const char _RWSTDExportFunc(*) __rwse_PosBeyondEndOfString = "position beyond end of string in function: %s \n index: %d is greater than max_index: %d";

  extern const char _RWSTDExportFunc(*) __rwse_ResultLenInvalid = "resulting length is invalid  in function: %s \n index: %d is greater than max_index: %d";

  extern const char _RWSTDExportFunc(*) __rwse_StringIndexOutOfRange = "string index out of range in function: %s \n position: %d is greater than length: %d";

  extern const char _RWSTDExportFunc(*) __rwse_UnexpectedNullPtr = "unexpected NULL pointer in function: %s";

#endif //_RWSTD_LOCALIZED_ERRORS

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION
#ifndef _RWSTD_NO_STRING_REF_COUNT
  template class _RWSTDExportTemplate
  __string_ref<char,_RW_STD::char_traits<char>, _RW_STD::allocator<char> >;
#else
  template class _RWSTDExportTemplate
  __string_noref<char,_RW_STD::char_traits<char>, _RW_STD::allocator<char> >;
#endif
#endif

#ifndef _RWSTD_NO_NAMESPACE
}

namespace std {
#endif
#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

  template class _RWSTDExportTemplate 
  basic_string<char, char_traits<char>, allocator<char> >;

#ifndef _RWSTD_NO_WIDE_CHAR
  template class _RWSTDExportTemplate 
  basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >;
#endif
#else

#ifndef _RWSTD_NO_INSTANTIATE
#ifndef _RWSTD_NO_STRING_REF_COUNT
#pragma instantiate __RWSTD::__string_ref<char, char_traits<char>, allocator<char> >
#else
#pragma instantiate __RWSTD::__string_noref<char, char_traits<char>, allocator<char> >
#endif

#pragma instantiate basic_string<char, char_traits<char>, allocator<char> >

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >

#endif // _RWSTD_NO_WIDE_CHAR 
#endif // _RWSTD_NO_INSTANTIATE 
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION 

#ifdef _RWSTD_EXPLICIT_FUNC_INSTANTIATION

  template istream& _RWSTDExportTemplate operator >>(istream & is, 
           basic_string<char,char_traits<char>, allocator<char> > & str);
 
  template ostream& _RWSTDExportTemplate operator <<(ostream & os, 
           const basic_string<char, char_traits<char>, allocator<char> > & str);

  template istream& _RWSTDExportTemplate  getline(istream& is, 
           basic_string<char, char_traits<char>,allocator<char> >& str, char delim);
  
#endif // _RWSTD_EXPLICIT_FUNC_INSTANTIATION 

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
