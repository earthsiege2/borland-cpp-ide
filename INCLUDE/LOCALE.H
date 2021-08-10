/*  locale.h

*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __LOCALE_H
#define __LOCALE_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifndef _SIZE_T
#    define _SIZE_T
typedef unsigned size_t;
#endif


#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5
#define LC_MESSAGES 6
#define LC_userdef  7
#define LC_LAST     LC_userdef

#if !defined(__FLAT__)

struct lconv {

   char _FAR *decimal_point;
   char _FAR *thousands_sep;
   char _FAR *grouping;
   char _FAR *int_curr_symbol;
   char _FAR *currency_symbol;
   char _FAR *mon_decimal_point;
   char _FAR *mon_thousands_sep;
   char _FAR *mon_grouping;
   char _FAR *positive_sign;
   char _FAR *negative_sign;
   char int_frac_digits;
   char frac_digits;
   char p_cs_precedes;
   char p_sep_by_space;
   char n_cs_precedes;
   char n_sep_by_space;
   char p_sign_posn;
   char n_sign_posn;
};

#ifdef __cplusplus
extern "C" {
#endif
char _FAR * _CType _FARFUNC setlocale( int __category, const char _FAR *__locale );
char _FAR * _CType _FARFUNC _lsetlocale( int __category, const char _FAR *__locale );
struct lconv _FAR * _CType localeconv( void );
struct lconv _FAR * _CType _FARFUNC _llocaleconv( void );
#ifdef __cplusplus
}
#endif

#else  /* defined __FLAT__ */

#pragma pack(push, 1)

struct lconv {

   char *decimal_point;
   char *thousands_sep;
   char *grouping;
   char *int_curr_symbol;
   char *currency_symbol;
   char *mon_decimal_point;
   char *mon_thousands_sep;
   char *mon_grouping;
   char *positive_sign;
   char *negative_sign;
   char int_frac_digits;
   char frac_digits;
   char p_cs_precedes;
   char p_sep_by_space;
   char n_cs_precedes;
   char n_sep_by_space;
   char p_sign_posn;
   char n_sign_posn;
};

#ifdef __cplusplus
extern "C" {
#endif
char *         _RTLENTRY _EXPFUNC setlocale( int __category, const char _FAR *__locale );
char *         _RTLENTRY _EXPFUNC _lsetlocale( int __category, const char _FAR *__locale );
struct lconv * _RTLENTRY _EXPFUNC localeconv( void );
struct lconv * _RTLENTRY _EXPFUNC _llocaleconv( void );
#ifdef __cplusplus
}
#endif

#pragma pack(pop)	/* restore default packing */

#endif  /* __FLAT__ */

#if defined( __USELOCALES__ )
#define setlocale  _lsetlocale
#define localeconv _llocaleconv
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __LOCALE_H */

