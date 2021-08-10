/*  limits.h

    Defines implementation specific limits on type values.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__USING_STD_NAMES__)

#ifndef __LIMITS_H
#define __LIMITS_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#define CHAR_BIT        8               /* number of bits in a char */
#define MB_LEN_MAX      2               /* max. # bytes in multibyte char */

#define SCHAR_MIN     (-128)            /* minimum signed   char value */
#define SCHAR_MAX       127             /* maximum signed   char value */
#define UCHAR_MAX       255             /* maximum unsigned char value */

#if ('\x80' < 0)
#define CHAR_MIN        SCHAR_MIN       /* minimum char value */
#define CHAR_MAX        SCHAR_MAX       /* maximum char value */
#else
#define CHAR_MIN        0
#define CHAR_MAX        UCHAR_MAX
#endif

#define SHRT_MIN      (-32767-1)        /* minimum signed   short value */
#define SHRT_MAX        32767           /* maximum signed   short value */
#define USHRT_MAX       65535U          /* maximum unsigned short value */

#define LONG_MIN      (-2147483647L-1)  /* minimum signed   long value */
#define LONG_MAX        2147483647L     /* maximum signed   long value */
#define ULONG_MAX       4294967295UL    /* maximum unsigned long value */

#if defined(__FLAT__) && defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
#define _I64_MIN      (-9223372036854775807i64-1) /* minimum signed   __int64 value */
#define _I64_MAX        9223372036854775807i64    /* maximum signed   __int64 value */
#define _UI64_MAX       18446744073709551615ui64  /* maximum unsigned __int64 value */
#endif

#if !defined(__FLAT__)
#define INT_MIN         SHRT_MIN        /* minimum signed   int value */
#define INT_MAX         SHRT_MAX        /* maximum signed   int value */
#define UINT_MAX        USHRT_MAX       /* maximum unsigned int value */
#else
#define INT_MIN         LONG_MIN
#define INT_MAX         LONG_MAX
#define UINT_MAX        ULONG_MAX
#endif


#if defined(__FLAT__) && defined(_POSIX_)

#define _POSIX_ARG_MAX          4096
#define _POSIX_CHILD_MAX        6
#define _POSIX_LINK_MAX         8
#define _POSIX_MAX_CANON        255
#define _POSIX_MAX_INPUT        255
#define _POSIX_NAME_MAX         14
#define _POSIX_NGROUPS_MAX      0
#define _POSIX_OPEN_MAX         16
#define _POSIX_PATH_MAX         255
#define _POSIX_PIPE_BUF         512
#define _POSIX_SSIZE_MAX        32767
#define _POSIX_STREAM_MAX       8
#define _POSIX_TZNAME_MAX       3

#define ARG_MAX                 (16384 - 256)   /* 16k-(heap overhead+safety) */
#define CHILD_MAX               32
#define LINK_MAX                _POSIX_LINK_MAX
#define MAX_CANON               _POSIX_MAX_CANON
#define MAX_INPUT               _POSIX_MAX_INPUT
#define NAME_MAX                255
#define NGROUPS_MAX             16
#define OPEN_MAX                32
#define PATH_MAX                512
#define PIPE_BUF                _POSIX_PIPE_BUF
#define SSIZE_MAX               _POSIX_SSIZE_MAX
#define STREAM_MAX              20
#define TZNAME_MAX              10

#endif /* POSIX */

#endif  /* __LIMITS_H */

#else   /* __USING_STD_NAMES__ */

#ifndef __STD_LIMITS
#define __STD_LIMITS

/***************************************************************************
 *
 * limits - Declarations for the Standard Library limits class
 *
 * $Id: limits,v 1.42 1995/09/29 01:06:31 smithey Exp $
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

#include <stdcomp.h>
#include <stddefs.h>

#ifndef RWSTD_NO_NEW_HEADER
#include <cfloat>
#include <climits>
#else
#include <float.h>
#include <limits.h>
#endif

//
// Hack to get around some <math.h>s defining an exception structure.
//
#define exception math_exception

#ifndef RWSTD_NO_NEW_HEADER
#include <cmath>
#else
#include <math.h>
#endif

//
// Undo the hack.
//
#undef exception

//
// WARNING: this is a hack to get around MSVC's complex
//
#ifdef _MSC_VER
#ifdef complex
#undef complex
#endif
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

enum float_round_style
{
    round_indeterminable      = -1,
    round_toward_zero         =  0,
    round_to_nearest          =  1,
    round_toward_infinity     =  2,
    round_toward_neg_infinity =  3
};

template <class T>
class numeric_limits
{
  public:

    static const bool is_specialized;

    static inline T min () { return (T) 0; }
    static inline T max () { return (T) 0; }

    static const int digits;
    static const int digits10;

    static const bool is_signed;
    static const bool is_integer;
    static const bool is_exact;

    static const int radix;
    static inline T  epsilon     () { return (T) 0; }
    static inline T  round_error () { return (T) 0; }

    static const int min_exponent;
    static const int min_exponent10;
    static const int max_exponent;
    static const int max_exponent10;

    static const bool has_infinity;
    static const bool has_quiet_NaN;
    static const bool has_signaling_NaN;
    static const bool has_denorm;

    static inline T infinity      () { return (T) 0; }
    static inline T quiet_NaN     () { return (T) 0; }
    static inline T signaling_NaN () { return (T) 0; }
    static inline T denorm_min    () { return min(); }

    static const bool is_iec559;
    static const bool is_bounded;
    static const bool is_modulo;

    static const bool traps;
    static const bool tinyness_before;

    static const float_round_style round_style;
};

#ifndef RWSTD_NO_TEMPLATE_SPECIALIZATION
template <class T>
const bool numeric_limits<T>::is_specialized = false;

template <class T>
const int numeric_limits<T>::digits = 0;

template <class T>
const int numeric_limits<T>::digits10 = 0;

template <class T>
const bool numeric_limits<T>::is_signed = false;

template <class T>
const bool numeric_limits<T>::is_integer = false;

template <class T>
const bool numeric_limits<T>::is_exact = false;

template <class T>
const int numeric_limits<T>::radix = 0;

template <class T>
const int numeric_limits<T>::min_exponent10 =0;

template <class T>
const int numeric_limits<T>::max_exponent10 = 0;

template <class T>
const int numeric_limits<T>::min_exponent = 0;

template <class T>
const int numeric_limits<T>::max_exponent = 0;

template <class T>
const bool numeric_limits<T>::has_infinity = false;

template <class T>
const bool numeric_limits<T>::has_quiet_NaN = false;

template <class T>
const bool numeric_limits<T>::has_signaling_NaN = false;

template <class T>
const bool numeric_limits<T>::is_iec559 = false;

template <class T>
const bool numeric_limits<T>::is_bounded = false;

template <class T>
const bool numeric_limits<T>::is_modulo = false;

template <class T>
const bool numeric_limits<T>::has_denorm = false;

template <class T>
const bool numeric_limits<T>::traps = false;

template <class T>
const bool numeric_limits<T>::tinyness_before = false;

template <class T>
const float_round_style numeric_limits<T>::round_style = round_toward_zero;
#endif


#ifndef RWSTD_NO_STI_SIMPLE
#define __RW_INIT(n) = n
#else
#define __RW_INIT(n) /**/
#endif


//**********************************************************************
//
// Assumptions made in this implementation:
//
//   1) numeric_limits<int>::radix equals numeric_limits<T>::radix
//      for all integral T specialized in this file.
//
//   2) numeric_limits<int>::is_modulo equals numeric_limits<T>::is_modulo
//      for all signed integral T specialized in this file, except
//      numeric_limits<bool>::is_modulo, which is assumed to be false.
//
//   3) numeric_limts<T>::traps == false for all builtin integral T.
//
// Does there exist a machine for which these aren't true?
//
//**********************************************************************


//**********************************************************************
//
// If your compiler allows in-class initialization of static const data
// members of integral type, then look for all lines having a comment of
// the form
//
//       // VENDOR
//
// and set the value on that line to the proper one for your environment.
//
// If your compiler does NOT allow in-class initialization of static const
// data members of integral type, then you'll need to set the values in
// stdlib/src/limits/limits.cpp so they're properly archived into the
// Standard Library.
//
//**********************************************************************


//
// Specialization for float.
//

class RWSTDExport numeric_limits<float>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline float min () { return FLT_MIN; }
    static inline float max () { return FLT_MAX; }

    static const int digits   __RW_INIT(FLT_MANT_DIG);
    static const int digits10 __RW_INIT(FLT_DIG);

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(false);
    static const bool is_exact   __RW_INIT(false);

    static const  int radix __RW_INIT(FLT_RADIX);

    static inline float epsilon () { return FLT_EPSILON; }
    static float round_error    ();

    static const int min_exponent   __RW_INIT(FLT_MIN_EXP);
    static const int min_exponent10 __RW_INIT(FLT_MIN_10_EXP);
    static const int max_exponent   __RW_INIT(FLT_MAX_EXP);
    static const int max_exponent10 __RW_INIT(FLT_MAX_10_EXP);

    static const bool has_infinity      __RW_INIT(false);            // VENDOR
    static const bool has_quiet_NaN     __RW_INIT(false);            // VENDOR
    static const bool has_signaling_NaN __RW_INIT(false);            // VENDOR
    static const bool has_denorm        __RW_INIT(false);            // VENDOR

    static float infinity      ();
    static float quiet_NaN     ();
    static float signaling_NaN ();
    static float denorm_min    ();

    static const bool is_iec559  __RW_INIT(false);                   // VENDOR
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(false);                   // VENDOR

    static const bool traps           __RW_INIT(false);              // VENDOR
    static const bool tinyness_before __RW_INIT(false);              // VENDOR

    static const float_round_style round_style __RW_INIT((float_round_style)FLT_ROUNDS);
};

//
// Specialization for double.
//

class RWSTDExport numeric_limits<double>
{
  public:

    static const bool is_specialized  __RW_INIT(true);

    static inline double min () { return DBL_MIN; }
    static inline double max () { return DBL_MAX; }

    static const int digits   __RW_INIT(DBL_MANT_DIG);
    static const int digits10 __RW_INIT(DBL_DIG);

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(false);
    static const bool is_exact   __RW_INIT(false);

    static const int radix __RW_INIT(FLT_RADIX);

    static inline double epsilon () { return DBL_EPSILON; }
    static double round_error    ();

    static const int min_exponent   __RW_INIT(DBL_MIN_EXP);
    static const int min_exponent10 __RW_INIT(DBL_MIN_10_EXP);
    static const int max_exponent   __RW_INIT(DBL_MAX_EXP);
    static const int max_exponent10 __RW_INIT(DBL_MAX_10_EXP);

    static const bool has_infinity      __RW_INIT(false);            // VENDOR
    static const bool has_quiet_NaN     __RW_INIT(false);            // VENDOR
    static const bool has_signaling_NaN __RW_INIT(false);            // VENDOR
    static const bool has_denorm        __RW_INIT(false);            // VENDOR

    static double infinity      ();
    static double quiet_NaN     ();
    static double signaling_NaN ();
    static double denorm_min    ();

    static const bool is_iec559  __RW_INIT(false);                   // VENDOR
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(false);                   // VENDOR

    static const bool traps           __RW_INIT(false);              // VENDOR
    static const bool tinyness_before __RW_INIT(false);              // VENDOR

    static const float_round_style round_style __RW_INIT((float_round_style)FLT_ROUNDS);
};

//
// Specialization for long double.
//

class RWSTDExport numeric_limits<long double>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline long double min () { return LDBL_MIN; }
    static inline long double max () { return LDBL_MAX; }

    static const int digits   __RW_INIT(LDBL_MANT_DIG);
    static const int digits10 __RW_INIT(LDBL_DIG);

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(false);
    static const bool is_exact   __RW_INIT(false);

    static const int radix __RW_INIT(FLT_RADIX);

    static inline long double epsilon () { return LDBL_EPSILON; }
    static long double round_error    ();

    static const int min_exponent   __RW_INIT(LDBL_MIN_EXP);
    static const int min_exponent10 __RW_INIT(LDBL_MIN_10_EXP);
    static const int max_exponent   __RW_INIT(LDBL_MAX_EXP);
    static const int max_exponent10 __RW_INIT(LDBL_MAX_10_EXP);

    static const bool has_infinity      __RW_INIT(false);            // VENDOR
    static const bool has_quiet_NaN     __RW_INIT(false);            // VENDOR
    static const bool has_signaling_NaN __RW_INIT(false);            // VENDOR
    static const bool has_denorm        __RW_INIT(false);            // VENDOR

    static long double infinity      ();
    static long double quiet_NaN     ();
    static long double signaling_NaN ();
    static long double denorm_min    ();

    static const bool is_iec559  __RW_INIT(false);                   // VENDOR
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(false);                   // VENDOR

    static const bool traps           __RW_INIT(false);              // VENDOR
    static const bool tinyness_before __RW_INIT(false);              // VENDOR

    static const float_round_style round_style __RW_INIT((float_round_style)FLT_ROUNDS);
};

//
// Specialization for int.
//

class RWSTDExport numeric_limits<int>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline int min () { return INT_MIN; }
    static inline int max () { return INT_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(int)-1);
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(2);                             // VENDOR

    static inline int epsilon     () { return 0; }
    static inline int round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline int infinity      () { return 0;     }
    static inline int quiet_NaN     () { return 0;     }
    static inline int signaling_NaN () { return 0;     }
    static inline int denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(false);                   // VENDOR

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

#ifndef RWSTD_NO_OVERLOAD_WCHAR
class RWSTDExport numeric_limits<wchar_t>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static wchar_t min ();
    static wchar_t max ();

    static const bool is_signed  __RW_INIT(true);                    // VENDOR

    static const int digits   __RW_INIT(is_signed ? CHAR_BIT*sizeof(wchar_t) - 1 : CHAR_BIT*sizeof(wchar_t));
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline wchar_t epsilon     () { return 0; }
    static inline wchar_t round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline wchar_t infinity      () { return 0;     }
    static inline wchar_t quiet_NaN     () { return 0;     }
    static inline wchar_t signaling_NaN () { return 0;     }
    static inline wchar_t denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(is_signed ? numeric_limits<int>::is_modulo : true);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};
#endif /*!RWSTD_NO_OVERLOAD_WCHAR*/

//**********************************************************************
//
// There are no VENDOR-settable values beyond this point.
//
//**********************************************************************

//
// Specialization for short.
//

class RWSTDExport numeric_limits<short>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline short min () { return SHRT_MIN; }
    static inline short max () { return SHRT_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(short)-1);
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline short epsilon     () { return 0; }
    static inline short round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline short infinity      () { return 0;     }
    static inline short quiet_NaN     () { return 0;     }
    static inline short signaling_NaN () { return 0;     }
    static inline short denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(numeric_limits<int>::is_modulo);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for unsigned short.
//

class RWSTDExport numeric_limits<unsigned short>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline unsigned short min () { return 0;         }
    static inline unsigned short max () { return USHRT_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(unsigned short));
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(false);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline unsigned short epsilon     () { return 0; }
    static inline unsigned short round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline unsigned short infinity      () { return 0;     }
    static inline unsigned short quiet_NaN     () { return 0;     }
    static inline unsigned short signaling_NaN () { return 0;     }
    static inline unsigned short denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(true);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for unsigned int.
//

class RWSTDExport numeric_limits<unsigned int>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline unsigned int min () { return 0;        }
    static inline unsigned int max () { return UINT_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(unsigned int));
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(false);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline unsigned int epsilon     () { return 0; }
    static inline unsigned int round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline unsigned int infinity      () { return 0;     }
    static inline unsigned int quiet_NaN     () { return 0;     }
    static inline unsigned int signaling_NaN () { return 0;     }
    static inline unsigned int denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(true);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for long.
//

class RWSTDExport numeric_limits<long>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline long min () { return LONG_MIN; }
    static inline long max () { return LONG_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(long)-1);
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline long epsilon     () { return 0; }
    static inline long round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline long infinity      () { return 0;     }
    static inline long quiet_NaN     () { return 0;     }
    static inline long signaling_NaN () { return 0;     }
    static inline long denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(numeric_limits<int>::is_modulo);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for unsigned long.
//

class RWSTDExport numeric_limits<unsigned long>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline unsigned long min () { return 0;         }
    static inline unsigned long max () { return ULONG_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(unsigned long));
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(false);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline unsigned long epsilon     () { return 0; }
    static inline unsigned long round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline unsigned long infinity      () { return 0;     }
    static inline unsigned long quiet_NaN     () { return 0;     }
    static inline unsigned long signaling_NaN () { return 0;     }
    static inline unsigned long denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(true);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for char.
//

class RWSTDExport numeric_limits<char>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline char min () { return CHAR_MIN; }
    static inline char max () { return CHAR_MAX; }

    static const bool is_signed  __RW_INIT(CHAR_MAX == SCHAR_MAX ? true : false);

    static const int digits   __RW_INIT(is_signed ? CHAR_BIT*sizeof(char) -1 : CHAR_BIT*sizeof(char));
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline char epsilon     () { return 0; }
    static inline char round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline char infinity      () { return 0;     }
    static inline char quiet_NaN     () { return 0;     }
    static inline char signaling_NaN () { return 0;     }
    static inline char denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(is_signed ? numeric_limits<int>::is_modulo : true);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for unsigned char.
//

class RWSTDExport numeric_limits<unsigned char>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline unsigned char min () { return 0;         }
    static inline unsigned char max () { return UCHAR_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(unsigned char));
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(false);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline unsigned char epsilon     () { return 0; }
    static inline unsigned char round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline unsigned char infinity      () { return 0;     }
    static inline unsigned char quiet_NaN     () { return 0;     }
    static inline unsigned char signaling_NaN () { return 0;     }
    static inline unsigned char denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(true);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

//
// Specialization for signed char.
//

class RWSTDExport numeric_limits<signed char>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline signed char min () { return SCHAR_MIN; }
    static inline signed char max () { return SCHAR_MAX; }

    static const int digits   __RW_INIT(CHAR_BIT*sizeof(signed char)-1);
    static const int digits10 __RW_INIT(int(digits/3.321928095));

    static const bool is_signed  __RW_INIT(true);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline signed char epsilon     () { return 0; }
    static inline signed char round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline signed char infinity      () { return 0;     }
    static inline signed char quiet_NaN     () { return 0;     }
    static inline signed char signaling_NaN () { return 0;     }
    static inline signed char denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(numeric_limits<int>::is_modulo);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};

#ifndef RWSTD_NO_BOOL
//
// Specialization for bool.
//

class RWSTDExport numeric_limits<bool>
{
  public:

    static const bool is_specialized __RW_INIT(true);

    static inline bool min () { return false; }
    static inline bool max () { return true;  }

    static const int digits   __RW_INIT(1);
    static const int digits10 __RW_INIT(0);

    static const bool is_signed  __RW_INIT(false);
    static const bool is_integer __RW_INIT(true);
    static const bool is_exact   __RW_INIT(true);

    static const int radix __RW_INIT(numeric_limits<int>::radix);

    static inline bool epsilon     () { return 0; }
    static inline bool round_error () { return 0; }

    static const int min_exponent   __RW_INIT(0);
    static const int min_exponent10 __RW_INIT(0);
    static const int max_exponent   __RW_INIT(0);
    static const int max_exponent10 __RW_INIT(0);

    static const bool has_infinity      __RW_INIT(false);
    static const bool has_quiet_NaN     __RW_INIT(false);
    static const bool has_signaling_NaN __RW_INIT(false);
    static const bool has_denorm        __RW_INIT(false);

    static inline int infinity      () { return 0;     }
    static inline int quiet_NaN     () { return 0;     }
    static inline int signaling_NaN () { return 0;     }
    static inline int denorm_min    () { return min(); }

    static const bool is_iec559  __RW_INIT(false);
    static const bool is_bounded __RW_INIT(true);
    static const bool is_modulo  __RW_INIT(false);

    static const bool traps           __RW_INIT(false);
    static const bool tinyness_before __RW_INIT(false);

    static const float_round_style round_style __RW_INIT(round_toward_zero);
};
#endif /*!RWSTD_NO_BOOL*/

#undef __RW_INIT

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif /*__STD_LIMITS*/

#endif /* __USING_STD_NAMES__ */
