/*  locale.h

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.9  $ */

#ifndef __LOCALE_H
#define __LOCALE_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__STDDEF_H)
#include <stddef.h>
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

#if defined (__USELOCALES__) || defined (__FLAT__)

#define LOCALE_ERROR(code) 0x00000100 + code
#define ERROR_LOCALE_INVALID   (APPLICATION_ERROR_MASK + LOCALE_ERROR(1))
#define ERROR_CATEGORY_INVALID (APPLICATION_ERROR_MASK + LOCALE_ERROR(2))
#define ERROR_LOCALE_NOTINSTALLED (APPLICATION_ERROR_MASK + LOCALE_ERROR(3))
#define ERROR_LOCALE_NOTSUPPORTED (APPLICATION_ERROR_MASK + LOCALE_ERROR(4))
#define ERROR_CATEGORY_NOTOPEN (APPLICATION_ERROR_MASK + LOCALE_ERROR(5))

#define LC_COLLATE  0x01
#define LC_CTYPE    0x02
#define LC_MONETARY 0x04
#define LC_NUMERIC  0x10
#define LC_TIME     0x20
#define LC_ALL      0xFF
#define LC_MIN      LC_COLLATE
#define LC_MAX      LC_ALL
#define LC_LAST     LC_MAX

#else

#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5
#define LC_MESSAGES 6
#define LC_userdef  7
#define LC_LAST     LC_userdef

#endif /* __USELOCALES__ */

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

#if !defined(__FLAT__)

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

#ifdef __cplusplus
extern "C" {
#endif
char *         _RTLENTRY _EXPFUNC setlocale( int __category, const char *__locale );
char *         _RTLENTRY _EXPFUNC _lsetlocale( int __category, const char *__locale );
struct lconv * _RTLENTRY _EXPFUNC localeconv( void );
struct lconv * _RTLENTRY _EXPFUNC _llocaleconv( void );
wchar_t *      _RTLENTRY _EXPFUNC _wsetlocale( int __category, const wchar_t *__locale );
wchar_t *      _RTLENTRY _EXPFUNC _lwsetlocale( int __category, const wchar_t *__locale );
#ifdef __cplusplus
}
#endif

#pragma pack(pop) /* restore default packing */

#endif  /* __FLAT__ */

#if defined( __USELOCALES__ )
#ifndef _UNICODE
  #define setlocale  _lsetlocale
#else
  #define _wsetlocale  _lwsetlocale
#endif
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __LOCALE_H */

