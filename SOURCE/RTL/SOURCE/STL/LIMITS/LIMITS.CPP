/***************************************************************************
 *
 * limits.cpp - Source for the Standard Library limits class
 *
 * $Id: limits.cpp,v 1.23 1995/09/27 21:14:36 smithey Exp $
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 *
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
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

#include <limits>

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifdef RWSTD_NO_STI_SIMPLE
#define __RW_INIT(n) = n
#else
#define __RW_INIT(n) /**/
#endif


//**********************************************************************
//
// Vendors MUST set the following functions to their proper values.
//
//**********************************************************************

float numeric_limits<float>::round_error   () { return .5F;   }
float numeric_limits<float>::infinity      () { return 0;     }
float numeric_limits<float>::quiet_NaN     () { return 0;     }
float numeric_limits<float>::signaling_NaN () { return 0;     }
float numeric_limits<float>::denorm_min    () { return min(); }

double numeric_limits<double>::round_error   () { return .5;    }
double numeric_limits<double>::infinity      () { return 0;     }
double numeric_limits<double>::quiet_NaN     () { return 0;     }
double numeric_limits<double>::signaling_NaN () { return 0;     }
double numeric_limits<double>::denorm_min    () { return min(); }

long double numeric_limits<long double>::round_error   () { return .5L;   }
long double numeric_limits<long double>::infinity      () { return 0;     }
long double numeric_limits<long double>::quiet_NaN     () { return 0;     }
long double numeric_limits<long double>::signaling_NaN () { return 0;     }
long double numeric_limits<long double>::denorm_min    () { return min(); }

#ifndef RWSTD_NO_OVERLOAD_WCHAR
wchar_t numeric_limits<wchar_t>::min () { return INT_MIN; }
wchar_t numeric_limits<wchar_t>::max () { return INT_MAX; }
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
const bool numeric_limits<float>::has_denorm             __RW_INIT(false);
const bool numeric_limits<float>::traps                  __RW_INIT(false);
const bool numeric_limits<float>::tinyness_before        __RW_INIT(false);

const bool numeric_limits<double>::has_infinity           __RW_INIT(false);
const bool numeric_limits<double>::has_quiet_NaN          __RW_INIT(false);
const bool numeric_limits<double>::has_signaling_NaN      __RW_INIT(false);
const bool numeric_limits<double>::is_iec559              __RW_INIT(false);
const bool numeric_limits<double>::is_modulo              __RW_INIT(false);
const bool numeric_limits<double>::has_denorm             __RW_INIT(false);
const bool numeric_limits<double>::traps                  __RW_INIT(false);
const bool numeric_limits<double>::tinyness_before        __RW_INIT(false);

const bool numeric_limits<long double>::has_infinity      __RW_INIT(false);
const bool numeric_limits<long double>::has_quiet_NaN     __RW_INIT(false);
const bool numeric_limits<long double>::has_signaling_NaN __RW_INIT(false);
const bool numeric_limits<long double>::is_iec559         __RW_INIT(false);
const bool numeric_limits<long double>::is_modulo         __RW_INIT(false);
const bool numeric_limits<long double>::has_denorm        __RW_INIT(false);
const bool numeric_limits<long double>::traps             __RW_INIT(false);
const bool numeric_limits<long double>::tinyness_before   __RW_INIT(false);

const int  numeric_limits<int>::radix                     __RW_INIT(2);
const bool numeric_limits<int>::is_modulo                 __RW_INIT(false);

#ifndef RWSTD_NO_OVERLOAD_WCHAR
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
const float_round_style numeric_limits<float>::round_style __RW_INIT((float_round_style) FLT_ROUNDS);


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
const float_round_style numeric_limits<double>::round_style __RW_INIT((float_round_style) FLT_ROUNDS);


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
const float_round_style numeric_limits<long double>::round_style __RW_INIT((float_round_style) FLT_ROUNDS);


const bool numeric_limits<short>::is_specialized    __RW_INIT(true);
const int  numeric_limits<short>::digits            __RW_INIT(CHAR_BIT*sizeof(short)-1);
const int  numeric_limits<short>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<short>::has_denorm        __RW_INIT(false);
const bool numeric_limits<short>::traps             __RW_INIT(false);
const bool numeric_limits<short>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<short>::round_style __RW_INIT(round_toward_zero);


const bool numeric_limits<unsigned short>::is_specialized    __RW_INIT(true);
const int  numeric_limits<unsigned short>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned short));
const int  numeric_limits<unsigned short>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<unsigned short>::has_denorm        __RW_INIT(false);
const bool numeric_limits<unsigned short>::traps             __RW_INIT(false);
const bool numeric_limits<unsigned short>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<unsigned short>::round_style __RW_INIT(round_toward_zero);


const bool numeric_limits<int>::is_specialized    __RW_INIT(true);
const int  numeric_limits<int>::digits            __RW_INIT(CHAR_BIT*sizeof(int)-1);
const int  numeric_limits<int>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<int>::has_denorm        __RW_INIT(false);
const bool numeric_limits<int>::traps             __RW_INIT(false);
const bool numeric_limits<int>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<int>::round_style __RW_INIT(round_toward_zero);


const bool numeric_limits<unsigned int>::is_specialized    __RW_INIT(true);
const int  numeric_limits<unsigned int>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned int));
const int  numeric_limits<unsigned int>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<unsigned int>::has_denorm        __RW_INIT(false);
const bool numeric_limits<unsigned int>::traps             __RW_INIT(false);
const bool numeric_limits<unsigned int>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<unsigned int>::round_style __RW_INIT(round_toward_zero);


const bool numeric_limits<long>::is_specialized    __RW_INIT(true);
const int  numeric_limits<long>::digits            __RW_INIT(CHAR_BIT*sizeof(long)-1);
const int  numeric_limits<long>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<long>::has_denorm        __RW_INIT(false);
const bool numeric_limits<long>::traps             __RW_INIT(false);
const bool numeric_limits<long>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<long>::round_style __RW_INIT(round_toward_zero);

const bool numeric_limits<unsigned long>::is_specialized    __RW_INIT(true);
const int  numeric_limits<unsigned long>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned long));
const int  numeric_limits<unsigned long>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<unsigned long>::has_denorm        __RW_INIT(false);
const bool numeric_limits<unsigned long>::traps             __RW_INIT(false);
const bool numeric_limits<unsigned long>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<unsigned long>::round_style __RW_INIT(round_toward_zero);


const bool numeric_limits<char>::is_specialized     __RW_INIT(true);
const bool numeric_limits<char>::is_signed          __RW_INIT((CHAR_MAX == SCHAR_MAX) ? true : false);
const int  numeric_limits<char>::digits             __RW_INIT(is_signed ? CHAR_BIT*sizeof(char) -1 : CHAR_BIT*sizeof(char));
const int  numeric_limits<char>::digits10           __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<char>::has_denorm         __RW_INIT(false);
const bool numeric_limits<char>::traps              __RW_INIT(false);
const bool numeric_limits<char>::tinyness_before    __RW_INIT(false);
const float_round_style numeric_limits<char>::round_style __RW_INIT(round_toward_zero);


#ifndef RWSTD_NO_OVERLOAD_WCHAR
const bool numeric_limits<wchar_t>::is_specialized    __RW_INIT(true);
const int  numeric_limits<wchar_t>::digits            __RW_INIT(is_signed ? CHAR_BIT*sizeof(wchar_t) - 1 : CHAR_BIT*sizeof(wchar_t));
const int  numeric_limits<wchar_t>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<wchar_t>::has_denorm        __RW_INIT(false);
const bool numeric_limits<wchar_t>::traps             __RW_INIT(false);
const bool numeric_limits<wchar_t>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<wchar_t>::round_style __RW_INIT(round_toward_zero);
#endif /*!RWSTD_NO_OVERLOAD_WCHAR */


const bool numeric_limits<unsigned char>::is_specialized    __RW_INIT(true);
const int  numeric_limits<unsigned char>::digits            __RW_INIT(CHAR_BIT*sizeof(unsigned char));
const int  numeric_limits<unsigned char>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<unsigned char>::has_denorm        __RW_INIT(false);
const bool numeric_limits<unsigned char>::traps             __RW_INIT(false);
const bool numeric_limits<unsigned char>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<unsigned char>::round_style __RW_INIT(round_toward_zero);


const bool numeric_limits<signed char>::is_specialized    __RW_INIT(true);
const int  numeric_limits<signed char>::digits            __RW_INIT(CHAR_BIT*sizeof(signed char)-1);
const int  numeric_limits<signed char>::digits10          __RW_INIT(int(digits/3.321928095));
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
const bool numeric_limits<signed char>::has_denorm        __RW_INIT(false);
const bool numeric_limits<signed char>::traps             __RW_INIT(false);
const bool numeric_limits<signed char>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<signed char>::round_style __RW_INIT(round_toward_zero);

#ifndef RWSTD_NO_BOOL
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
const bool numeric_limits<bool>::has_denorm        __RW_INIT(false);
const bool numeric_limits<bool>::traps             __RW_INIT(false);
const bool numeric_limits<bool>::tinyness_before   __RW_INIT(false);
const float_round_style numeric_limits<bool>::round_style __RW_INIT(round_toward_zero);
#endif /*!RWSTD_NO_BOOL*/

#undef __RW_INIT

#ifndef RWSTD_NO_NAMESPACE
}
#endif

