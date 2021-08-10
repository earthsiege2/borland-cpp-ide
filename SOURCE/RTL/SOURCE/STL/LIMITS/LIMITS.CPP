#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * limits.cpp - Source for the Standard Library limits class
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

//**********************************************************************
//
// Assumptions made in this implementation:
//
//   1) numeric_limits<int>::radix equals numeric_limits<T>::radix
//      for all integral T specialized in this file;
//
//   2) numeric_limits<int>::is_modulo equals numeric_limits<T>::is_modulo
//      for all signed integral T specialized in this file, except
//      numeric_limits<bool>::is_modulo, which is assumed to be false;
//
//   3) numeric_limits<T>::traps == false for all builtin integral T.
//
// Does there exist a machine for which these aren't true?
//
//**********************************************************************

#include <stdcomp.h>
#include <rw/stddefs.h> 

#include <limits>

#include <_float.h>  // Borland header
#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#if defined(_RWSTD_NO_STI_SIMPLE) //&& !defined(_RWSTD_FLT_ROUNDS_IS_CONSTANT)
#define __RW_INIT(n) = n
#else
#define __RW_INIT(n) /**/
#endif

//**********************************************************************
//
// Vendors MUST set the following functions to their proper values.
//
//**********************************************************************

  float numeric_limits<float>::round_error   () _RWSTD_INLINE_NO_THROW { return .5F;   }
  float numeric_limits<float>::infinity      () _RWSTD_INLINE_NO_THROW { return (float)__ieee_64_p_inf; }
  float numeric_limits<float>::quiet_NaN     () _RWSTD_INLINE_NO_THROW { return (float)__ieee_64_p_nanq; }
  float numeric_limits<float>::signaling_NaN () _RWSTD_INLINE_NO_THROW { return (float)__ieee_64_p_nans; }
  float numeric_limits<float>::denorm_min    () _RWSTD_INLINE_NO_THROW { return min(); }

  double numeric_limits<double>::round_error   () _RWSTD_INLINE_NO_THROW { return .5;    }
  double numeric_limits<double>::infinity      () _RWSTD_INLINE_NO_THROW { return (double)__ieee_64_p_inf; }
  double numeric_limits<double>::quiet_NaN     () _RWSTD_INLINE_NO_THROW { return (double)__ieee_64_p_nanq; }
  double numeric_limits<double>::signaling_NaN () _RWSTD_INLINE_NO_THROW { return (double)__ieee_64_p_nans; }
  double numeric_limits<double>::denorm_min    () _RWSTD_INLINE_NO_THROW { return min(); }

#ifndef _RWSTD_NO_LONGDOUBLE
  long double numeric_limits<long double>::round_error   () _RWSTD_INLINE_NO_THROW { return .5L;   }
  long double numeric_limits<long double>::infinity      () _RWSTD_INLINE_NO_THROW { return (long double)__ieee_64_p_inf; }
  long double numeric_limits<long double>::quiet_NaN     () _RWSTD_INLINE_NO_THROW { return (long double)__ieee_64_p_nanq; }
  long double numeric_limits<long double>::signaling_NaN () _RWSTD_INLINE_NO_THROW { return (long double)__ieee_64_p_nans; }
  long double numeric_limits<long double>::denorm_min    () _RWSTD_INLINE_NO_THROW { return min(); }
#endif

#ifndef _RWSTD_NO_OVERLOAD_WCHAR
  wchar_t numeric_limits<wchar_t>::min () _RWSTD_INLINE_NO_THROW { return INT_MIN; }
  wchar_t numeric_limits<wchar_t>::max () _RWSTD_INLINE_NO_THROW { return INT_MAX; }
#endif

//**********************************************************************
//
// End of functions needing to be set by vendors.
//
// If your compiler does NOT handle in-class initialization of static
// constant data members then you MUST fill in the proper values in the
// following section.
//
// If your compiler DOES handle in-class initialization of static
// constant data members then the ONLY things you should need to change
// in this file are the function definitions in the preceding section.
//
//**********************************************************************

  const bool numeric_limits<float>::has_infinity           __RW_INIT(false);
  const bool numeric_limits<float>::has_quiet_NaN          __RW_INIT(false);
  const bool numeric_limits<float>::has_signaling_NaN      __RW_INIT(false);
  const bool numeric_limits<float>::is_iec559              __RW_INIT(false);
  const bool numeric_limits<float>::is_modulo              __RW_INIT(false);
  const float_denorm_style numeric_limits<float>::has_denorm             __RW_INIT(denorm_indeterminate);
  const bool numeric_limits<float>::has_denorm_loss        __RW_INIT(false);
  const bool numeric_limits<float>::traps                  __RW_INIT(false);
  const bool numeric_limits<float>::tinyness_before        __RW_INIT(false);

  const bool numeric_limits<double>::has_infinity           __RW_INIT(false);
  const bool numeric_limits<double>::has_quiet_NaN          __RW_INIT(false);
  const bool numeric_limits<double>::has_signaling_NaN      __RW_INIT(false);
  const bool numeric_limits<double>::is_iec559              __RW_INIT(false);
  const bool numeric_limits<double>::is_modulo              __RW_INIT(false);
  const float_denorm_style numeric_limits<double>::has_denorm             __RW_INIT(denorm_indeterminate);
  const bool numeric_limits<double>::has_denorm_loss        __RW_INIT(false);
  const bool numeric_limits<double>::traps                  __RW_INIT(false);
  const bool numeric_limits<double>::tinyness_before        __RW_INIT(false);

#ifndef _RWSTD_NO_LONGDOUBLE
  const bool numeric_limits<long double>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<long double>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<long double>::has_signaling_NaN __RW_INIT(false);
  const bool numeric_limits<long double>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<long double>::is_modulo         __RW_INIT(false);
  const float_denorm_style numeric_limits<long double>::has_denorm        __RW_INIT(denorm_indeterminate);
  const bool numeric_limits<long double>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<long double>::traps             __RW_INIT(false);
  const bool numeric_limits<long double>::tinyness_before   __RW_INIT(false);
#endif

  const int  numeric_limits<int>::radix                     __RW_INIT(2);
  const bool numeric_limits<int>::is_modulo                 __RW_INIT(false);

#ifndef _RWSTD_NO_OVERLOAD_WCHAR
  const bool numeric_limits<wchar_t>::is_signed             __RW_INIT(true);
#endif

//**********************************************************************
//
// End of section of static const data members needing to be set.
//
// NOTHING should need to be changed below this point.
//
//**********************************************************************

  const bool numeric_limits<float>::is_specialized __RW_INIT(true);
  const int  numeric_limits<float>::digits         __RW_INIT(FLT_MANT_DIG);
  const int  numeric_limits<float>::digits10       __RW_INIT(FLT_DIG);
  const bool numeric_limits<float>::is_signed      __RW_INIT(true);
  const bool numeric_limits<float>::is_integer     __RW_INIT(false);
  const bool numeric_limits<float>::is_exact       __RW_INIT(false);
  const int  numeric_limits<float>::radix          __RW_INIT(FLT_RADIX);
  const int  numeric_limits<float>::min_exponent10 __RW_INIT(FLT_MIN_10_EXP); 
  const int  numeric_limits<float>::max_exponent10 __RW_INIT(FLT_MAX_10_EXP);
  const int  numeric_limits<float>::min_exponent   __RW_INIT(FLT_MIN_EXP);
  const int  numeric_limits<float>::max_exponent   __RW_INIT(FLT_MAX_EXP);
  const bool numeric_limits<float>::is_bounded     __RW_INIT(true);
  const float_round_style numeric_limits<float>::round_style
#ifndef _RWSTD_FLT_ROUNDS_IS_CONSTANT
	  = _RWSTD_STATIC_CAST(float_round_style,FLT_ROUNDS);
#else
  __RW_INIT(_RWSTD_STATIC_CAST(float_round_style,FLT_ROUNDS));
#endif

  const bool numeric_limits<double>::is_specialized __RW_INIT(true);
  const int  numeric_limits<double>::digits         __RW_INIT(DBL_MANT_DIG);
  const int  numeric_limits<double>::digits10       __RW_INIT(DBL_DIG);
  const bool numeric_limits<double>::is_signed      __RW_INIT(true);
  const bool numeric_limits<double>::is_integer     __RW_INIT(false);
  const bool numeric_limits<double>::is_exact       __RW_INIT(false);
  const int  numeric_limits<double>::radix          __RW_INIT(FLT_RADIX);
  const int  numeric_limits<double>::min_exponent10 __RW_INIT(DBL_MIN_10_EXP);
  const int  numeric_limits<double>::max_exponent10 __RW_INIT(DBL_MAX_10_EXP);
  const int  numeric_limits<double>::min_exponent   __RW_INIT(DBL_MIN_EXP);
  const int  numeric_limits<double>::max_exponent   __RW_INIT(DBL_MAX_EXP);
  const bool numeric_limits<double>::is_bounded     __RW_INIT(true);
  const float_round_style numeric_limits<double>::round_style  
#ifndef _RWSTD_FLT_ROUNDS_IS_CONSTANT
	  = _RWSTD_STATIC_CAST(float_round_style,FLT_ROUNDS);
#else
  __RW_INIT(_RWSTD_STATIC_CAST(float_round_style,FLT_ROUNDS));
#endif
  
#ifndef _RWSTD_NO_LONGDOUBLE
  const bool numeric_limits<long double>::is_specialized __RW_INIT(true);
  const int  numeric_limits<long double>::digits         __RW_INIT(LDBL_MANT_DIG);
  const int  numeric_limits<long double>::digits10       __RW_INIT(LDBL_DIG);
  const bool numeric_limits<long double>::is_signed      __RW_INIT(true);
  const bool numeric_limits<long double>::is_integer     __RW_INIT(false);
  const bool numeric_limits<long double>::is_exact       __RW_INIT(false);
  const int  numeric_limits<long double>::radix          __RW_INIT(FLT_RADIX);
  const int  numeric_limits<long double>::min_exponent10 __RW_INIT(LDBL_MIN_10_EXP); 
  const int  numeric_limits<long double>::max_exponent10 __RW_INIT(LDBL_MAX_10_EXP);
  const int  numeric_limits<long double>::min_exponent   __RW_INIT(LDBL_MIN_EXP);
  const int  numeric_limits<long double>::max_exponent   __RW_INIT(LDBL_MAX_EXP);
  const bool numeric_limits<long double>::is_bounded     __RW_INIT(true);
  const float_round_style numeric_limits<long double>::round_style
#ifndef _RWSTD_FLT_ROUNDS_IS_CONSTANT
	  = _RWSTD_STATIC_CAST(float_round_style,FLT_ROUNDS);
#else
  __RW_INIT(_RWSTD_STATIC_CAST(float_round_style,FLT_ROUNDS));
#endif
#endif
  const bool numeric_limits<short>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<short>::digits            __RW_INIT(CHAR_BIT*sizeof(short)-1);
  const int  numeric_limits<short>::digits10         = int(digits/3.321928095);
  const bool numeric_limits<short>::is_signed         __RW_INIT(true);
  const bool numeric_limits<short>::is_integer        __RW_INIT(true);
  const bool numeric_limits<short>::is_exact          __RW_INIT(true);
  const int  numeric_limits<short>::radix             __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<short>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<short>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<short>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<short>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<short>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<short>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<short>::has_signaling_NaN __RW_INIT(false);	
  const bool numeric_limits<short>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<short>::is_bounded        __RW_INIT(true);
  const bool numeric_limits<short>::is_modulo         __RW_INIT(numeric_limits<int>::is_modulo);
  const float_denorm_style numeric_limits<short>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<short>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<short>::traps             __RW_INIT(false);
  const bool numeric_limits<short>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<short>::round_style __RW_INIT(round_toward_zero);
  const bool numeric_limits<unsigned short>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<unsigned short>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned short));
  const int  numeric_limits<unsigned short>::digits10          = int(digits/3.321928095);
  const bool numeric_limits<unsigned short>::is_signed         __RW_INIT(false);
  const bool numeric_limits<unsigned short>::is_integer        __RW_INIT(true);
  const bool numeric_limits<unsigned short>::is_exact          __RW_INIT(true);
  const int  numeric_limits<unsigned short>::radix             __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<unsigned short>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<unsigned short>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<unsigned short>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<unsigned short>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<unsigned short>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<unsigned short>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<unsigned short>::has_signaling_NaN __RW_INIT(false);
  const bool numeric_limits<unsigned short>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<unsigned short>::is_bounded        __RW_INIT(true);
  const bool numeric_limits<unsigned short>::is_modulo         __RW_INIT(true);
  const float_denorm_style numeric_limits<unsigned short>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<unsigned short>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<unsigned short>::traps             __RW_INIT(false);
  const bool numeric_limits<unsigned short>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<unsigned short>::round_style __RW_INIT(round_toward_zero);
  const bool numeric_limits<int>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<int>::digits            __RW_INIT(CHAR_BIT*sizeof(int)-1);
  const int  numeric_limits<int>::digits10          = int(digits/3.321928095);
  const bool numeric_limits<int>::is_signed         __RW_INIT(true);
  const bool numeric_limits<int>::is_integer        __RW_INIT(true);
  const bool numeric_limits<int>::is_exact          __RW_INIT(true);
  const int  numeric_limits<int>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<int>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<int>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<int>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<int>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<int>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<int>::has_signaling_NaN __RW_INIT(false);
  const bool numeric_limits<int>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<int>::is_bounded        __RW_INIT(true);
  const float_denorm_style numeric_limits<int>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<int>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<int>::traps             __RW_INIT(false);
  const bool numeric_limits<int>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<int>::round_style __RW_INIT(round_toward_zero);
  const bool numeric_limits<unsigned int>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<unsigned int>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned int));
  const int  numeric_limits<unsigned int>::digits10          = int(digits/3.321928095);
  const bool numeric_limits<unsigned int>::is_signed         __RW_INIT(false);
  const bool numeric_limits<unsigned int>::is_integer        __RW_INIT(true);
  const bool numeric_limits<unsigned int>::is_exact          __RW_INIT(true);
  const int  numeric_limits<unsigned int>::radix             __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<unsigned int>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<unsigned int>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<unsigned int>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<unsigned int>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<unsigned int>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<unsigned int>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<unsigned int>::has_signaling_NaN __RW_INIT(false);
  const bool numeric_limits<unsigned int>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<unsigned int>::is_bounded        __RW_INIT(true);
  const bool numeric_limits<unsigned int>::is_modulo         __RW_INIT(true);
  const float_denorm_style numeric_limits<unsigned int>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<unsigned int>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<unsigned int>::traps             __RW_INIT(false);
  const bool numeric_limits<unsigned int>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<unsigned int>::round_style __RW_INIT(round_toward_zero);
  const bool numeric_limits<long>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<long>::digits            __RW_INIT(CHAR_BIT*sizeof(long)-1);
  const int  numeric_limits<long>::digits10          = int(digits/3.321928095);
  const bool numeric_limits<long>::is_signed         __RW_INIT(true);
  const bool numeric_limits<long>::is_integer        __RW_INIT(true);
  const bool numeric_limits<long>::is_exact          __RW_INIT(true);
  const int  numeric_limits<long>::radix             __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<long>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<long>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<long>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<long>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<long>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<long>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<long>::has_signaling_NaN __RW_INIT(false);	
  const bool numeric_limits<long>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<long>::is_bounded        __RW_INIT(true);
  const bool numeric_limits<long>::is_modulo         __RW_INIT(numeric_limits<int>::is_modulo);
  const float_denorm_style numeric_limits<long>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<long>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<long>::traps             __RW_INIT(false);
  const bool numeric_limits<long>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<long>::round_style __RW_INIT(round_toward_zero);

  const bool numeric_limits<unsigned long>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<unsigned long>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned long));
  const int  numeric_limits<unsigned long>::digits10          = int(digits/3.321928095);
  const bool numeric_limits<unsigned long>::is_signed         __RW_INIT(false);
  const bool numeric_limits<unsigned long>::is_integer        __RW_INIT(true);
  const bool numeric_limits<unsigned long>::is_exact          __RW_INIT(true);
  const int  numeric_limits<unsigned long>::radix             __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<unsigned long>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<unsigned long>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<unsigned long>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<unsigned long>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<unsigned long>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<unsigned long>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<unsigned long>::has_signaling_NaN __RW_INIT(false);	
  const bool numeric_limits<unsigned long>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<unsigned long>::is_bounded        __RW_INIT(true);
  const bool numeric_limits<unsigned long>::is_modulo         __RW_INIT(true);
  const float_denorm_style numeric_limits<unsigned long>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<unsigned long>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<unsigned long>::traps             __RW_INIT(false);
  const bool numeric_limits<unsigned long>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<unsigned long>::round_style __RW_INIT(round_toward_zero);
  const bool numeric_limits<char>::is_specialized     __RW_INIT(true);
  const bool numeric_limits<char>::is_signed          __RW_INIT((CHAR_MAX == SCHAR_MAX) ? true : false);
  const int  numeric_limits<char>::digits             __RW_INIT(is_signed ? CHAR_BIT*sizeof(char) -1 : CHAR_BIT*sizeof(char));
  const int  numeric_limits<char>::digits10           = int(digits/3.321928095);
  const bool numeric_limits<char>::is_integer         __RW_INIT(true);
  const bool numeric_limits<char>::is_exact           __RW_INIT(true);
  const int  numeric_limits<char>::radix              __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<char>::min_exponent10     __RW_INIT(0); 
  const int  numeric_limits<char>::max_exponent10     __RW_INIT(0);
  const int  numeric_limits<char>::min_exponent       __RW_INIT(0);
  const int  numeric_limits<char>::max_exponent       __RW_INIT(0);
  const bool numeric_limits<char>::has_infinity       __RW_INIT(false);
  const bool numeric_limits<char>::has_quiet_NaN      __RW_INIT(false);
  const bool numeric_limits<char>::has_signaling_NaN  __RW_INIT(false);	
  const bool numeric_limits<char>::is_iec559          __RW_INIT(false);
  const bool numeric_limits<char>::is_bounded         __RW_INIT(true);
  const bool numeric_limits<char>::is_modulo          __RW_INIT(is_signed ? numeric_limits<int>::is_modulo : true);
  const float_denorm_style numeric_limits<char>::has_denorm         __RW_INIT(denorm_absent);
  const bool numeric_limits<char>::has_denorm_loss    __RW_INIT(false);
  const bool numeric_limits<char>::traps              __RW_INIT(false);
  const bool numeric_limits<char>::tinyness_before    __RW_INIT(false);
  const float_round_style numeric_limits<char>::round_style __RW_INIT(round_toward_zero);
#ifndef _RWSTD_NO_OVERLOAD_WCHAR
  const bool numeric_limits<wchar_t>::is_specialized    __RW_INIT(true);
  const int  numeric_limits<wchar_t>::digits            __RW_INIT(is_signed ? CHAR_BIT*sizeof(wchar_t) - 1 : CHAR_BIT*sizeof(wchar_t));
  const int  numeric_limits<wchar_t>::digits10          = int(digits/3.321928095);
  const bool numeric_limits<wchar_t>::is_integer        __RW_INIT(true);
  const bool numeric_limits<wchar_t>::is_exact          __RW_INIT(true);
  const int  numeric_limits<wchar_t>::radix             __RW_INIT(numeric_limits<int>::radix);
  const int  numeric_limits<wchar_t>::min_exponent10    __RW_INIT(0); 
  const int  numeric_limits<wchar_t>::max_exponent10    __RW_INIT(0);
  const int  numeric_limits<wchar_t>::min_exponent      __RW_INIT(0);
  const int  numeric_limits<wchar_t>::max_exponent      __RW_INIT(0);
  const bool numeric_limits<wchar_t>::has_infinity      __RW_INIT(false);
  const bool numeric_limits<wchar_t>::has_quiet_NaN     __RW_INIT(false);
  const bool numeric_limits<wchar_t>::has_signaling_NaN __RW_INIT(false);	
  const bool numeric_limits<wchar_t>::is_iec559         __RW_INIT(false);
  const bool numeric_limits<wchar_t>::is_bounded        __RW_INIT(true);
  const bool numeric_limits<wchar_t>::is_modulo         __RW_INIT(is_signed ? numeric_limits<int>::is_modulo : true);
  const float_denorm_style numeric_limits<wchar_t>::has_denorm        __RW_INIT(denorm_absent);
  const bool numeric_limits<wchar_t>::has_denorm_loss   __RW_INIT(false);
  const bool numeric_limits<wchar_t>::traps             __RW_INIT(false);
  const bool numeric_limits<wchar_t>::tinyness_before   __RW_INIT(false);
  const float_round_style numeric_limits<wchar_t>::round_style __RW_INIT(round_toward_zero);
#endif /*!_RWSTD_NO_OVERLOAD_WCHAR */
const bool numeric_limits<unsigned char>::is_specialized    __RW_INIT(true);
const int  numeric_limits<unsigned char>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned char));
const int  numeric_limits<unsigned char>::digits10          = int(digits/3.321928095);
const bool numeric_limits<unsigned char>::is_signed         __RW_INIT(false);
const bool numeric_limits<unsigned char>::is_integer        __RW_INIT(true);
const bool numeric_limits<unsigned char>::is_exact          __RW_INIT(true);
const int  numeric_limits<unsigned char>::radix             __RW_INIT(numeric_limits<int>::radix);
const int  numeric_limits<unsigned char>::min_exponent10    __RW_INIT(0); 
const int  numeric_limits<unsigned char>::max_exponent10    __RW_INIT(0);
const int  numeric_limits<unsigned char>::min_exponent      __RW_INIT(0);
const int  numeric_limits<unsigned char>::max_exponent      __RW_INIT(0);
const bool numeric_limits<unsigned char>::has_infinity      __RW_INIT(false);
const bool numeric_limits<unsigned char>::has_quiet_NaN     __RW_INIT(false);
const bool numeric_limits<unsigned char>::has_signaling_NaN __RW_INIT(false);
const bool numeric_limits<unsigned char>::is_iec559         __RW_INIT(false);
const bool numeric_limits<unsigned char>::is_bounded        __RW_INIT(true);
const bool numeric_limits<unsigned char>::is_modulo         __RW_INIT(true);
const float_denorm_style numeric_limits<unsigned char>::has_denorm        __RW_INIT(denorm_absent);
const bool numeric_limits<unsigned char>::has_denorm_loss   __RW_INIT(false);
const bool numeric_limits<unsigned char>::traps             __RW_INIT(false);
const bool numeric_limits<unsigned char>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<unsigned char>::round_style __RW_INIT(round_toward_zero);
const bool numeric_limits<signed char>::is_specialized    __RW_INIT(true);
const int  numeric_limits<signed char>::digits            __RW_INIT(CHAR_BIT*sizeof(signed char)-1);
const int  numeric_limits<signed char>::digits10          =  int(digits/3.321928095);
const bool numeric_limits<signed char>::is_signed         __RW_INIT(true);
const bool numeric_limits<signed char>::is_integer        __RW_INIT(true);
const bool numeric_limits<signed char>::is_exact          __RW_INIT(true);
const int  numeric_limits<signed char>::radix             __RW_INIT(numeric_limits<int>::radix);
const int  numeric_limits<signed char>::min_exponent10    __RW_INIT(0); 
const int  numeric_limits<signed char>::max_exponent10    __RW_INIT(0);
const int  numeric_limits<signed char>::min_exponent      __RW_INIT(0);
const int  numeric_limits<signed char>::max_exponent      __RW_INIT(0);
const bool numeric_limits<signed char>::has_infinity      __RW_INIT(false);
const bool numeric_limits<signed char>::has_quiet_NaN     __RW_INIT(false);
const bool numeric_limits<signed char>::has_signaling_NaN __RW_INIT(false);
const bool numeric_limits<signed char>::is_iec559         __RW_INIT(false);
const bool numeric_limits<signed char>::is_bounded        __RW_INIT(true);
const bool numeric_limits<signed char>::is_modulo         __RW_INIT(numeric_limits<int>::is_modulo);
const float_denorm_style numeric_limits<signed char>::has_denorm        __RW_INIT(denorm_absent);
const bool numeric_limits<signed char>::has_denorm_loss   __RW_INIT(false);
const bool numeric_limits<signed char>::traps             __RW_INIT(false);
const bool numeric_limits<signed char>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<signed char>::round_style __RW_INIT(round_toward_zero);

#ifndef _RWSTD_NO_BOOL
const bool numeric_limits<bool>::is_specialized    __RW_INIT(true);
const int  numeric_limits<bool>::digits            __RW_INIT(1);
const int  numeric_limits<bool>::digits10          __RW_INIT(0);
const bool numeric_limits<bool>::is_signed         __RW_INIT(false);
const bool numeric_limits<bool>::is_integer        __RW_INIT(true);
const bool numeric_limits<bool>::is_exact          __RW_INIT(true);
const int  numeric_limits<bool>::radix             __RW_INIT(numeric_limits<int>::radix);
const int  numeric_limits<bool>::min_exponent10    __RW_INIT(0); 
const int  numeric_limits<bool>::max_exponent10    __RW_INIT(0);
const int  numeric_limits<bool>::min_exponent      __RW_INIT(0);
const int  numeric_limits<bool>::max_exponent      __RW_INIT(0);
const bool numeric_limits<bool>::has_infinity      __RW_INIT(false);
const bool numeric_limits<bool>::has_quiet_NaN     __RW_INIT(false);
const bool numeric_limits<bool>::has_signaling_NaN __RW_INIT(false);
const bool numeric_limits<bool>::is_iec559         __RW_INIT(false);
const bool numeric_limits<bool>::is_bounded        __RW_INIT(true);
const bool numeric_limits<bool>::is_modulo         __RW_INIT(false);
const float_denorm_style numeric_limits<bool>::has_denorm        __RW_INIT(denorm_absent);
const bool numeric_limits<bool>::has_denorm_loss   __RW_INIT(false);
const bool numeric_limits<bool>::traps             __RW_INIT(false);
const bool numeric_limits<bool>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<bool>::round_style __RW_INIT(round_toward_zero);
#endif /*!_RWSTD_NO_BOOL*/

#undef __RW_INIT

#ifndef _RWSTD_NO_NAMESPACE 
} 
#endif
