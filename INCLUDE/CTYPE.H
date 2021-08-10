/*  ctype.h

    Defines the locale aware ctype macros.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.9  $ */

#ifndef __CTYPE_H
#define __CTYPE_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */
#ifndef __cplusplus
#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
#define _WCHAR_T
#define _WCHAR_T_DEFINED  /* For WINDOWS.H */
typedef unsigned short wchar_t;
#endif
#endif

#if !defined(_WINT_T)
typedef wchar_t wint_t;
#define _WINT_T
#endif

#if !defined(__FLAT__)

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

extern unsigned char _RTLENTRY  _ctype[ 257 ];

#ifdef __cplusplus
extern "C" {
#endif
int _CType isalnum (int __c);
int _CType isalpha (int __c);
int _CType iscntrl (int __c);
int _CType isdigit (int __c);
int _CType isgraph (int __c);
int _CType islower (int __c);
int _CType isprint (int __c);
int _CType ispunct (int __c);
int _CType isspace (int __c);
int _CType isupper (int __c);
int _CType isxdigit(int __c);
int _CType isascii (int __c);

#ifdef __cplusplus
}
#endif


/* character classes */

#define _IS_SP     1           /* space */
#define _IS_DIG    2           /* digit */
#define _IS_UPP    4           /* upper case */
#define _IS_LOW    8           /* lower case */
#define _IS_HEX   16           /* [0..9] or [A-F] or [a-f] */
#define _IS_CTL   32           /* control */
#define _IS_PUN   64           /* punctuation */
#define _IS_BLK  128           /* blank */

#define _IS_ALPHA    (_IS_UPP | _IS_LOW)
#define _IS_ALNUM    (_IS_DIG | _IS_ALPHA)
#define _IS_GRAPH    (_IS_ALNUM | _IS_HEX | _IS_PUN)

#ifndef __USELOCALES__

/* C locale character classification macros */

#define isalnum(c)   (_ctype[ (c)+1 ] & (_IS_ALNUM))

#define isalpha(c)   (_ctype[ (c)+1 ] & (_IS_ALPHA))

#define iscntrl(c)   (_ctype[ (c)+1 ] & (_IS_CTL))

#define isdigit(c)   (_ctype[ (c)+1 ] & (_IS_DIG))

#define isgraph(c)   (_ctype[ (c)+1 ] & (_IS_GRAPH))

#define islower(c)   (_ctype[ (c)+1 ] & (_IS_LOW))

#define isprint(c)   (_ctype[ (c)+1 ] & (_IS_GRAPH | _IS_BLK))

#define ispunct(c)   (_ctype[ (c)+1 ] & (_IS_PUN))

#define isspace(c)   (_ctype[ (c)+1 ] & (_IS_SP))

#define isupper(c)   (_ctype[ (c)+1 ] & (_IS_UPP))

#define isxdigit(c)  (_ctype[ (c)+1 ] & (_IS_HEX))

#endif /* __USELOCALES__ */

#define isascii(c)  ((unsigned)(c) < 128)
#define toascii(c)  ((c) & 0x7f)

#ifdef __cplusplus
extern "C" {
#endif

int _CType tolower(int __ch);
int _CType _ltolower(int __ch);
int _CType toupper(int __ch);
int _CType _ltoupper(int __ch);

#ifdef __cplusplus
}
#endif

#if !defined(__STDC__)
#define _toupper(c) ((c) + 'A' - 'a')
#define _tolower(c) ((c) + 'a' - 'A')
#endif

#if defined( __USELOCALES__ )

#define toupper    _ltoupper
#define tolower    _ltolower

#endif  /* defined __USELOCALES__  */

#else  /* defined __FLAT__  */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

extern unsigned short _RTLENTRY _EXPDATA _chartype[ 257 ];
extern unsigned char _RTLENTRY  _EXPDATA _lower[ 256 ];
extern unsigned char _RTLENTRY  _EXPDATA _upper[ 256 ];

#ifdef __cplusplus
extern "C" {
#endif
int _RTLENTRY _EXPFUNC isalnum (int __c);
int _RTLENTRY _EXPFUNC isalpha (int __c);
int _RTLENTRY _EXPFUNC iscntrl (int __c);
int _RTLENTRY _EXPFUNC isdigit (int __c);
int _RTLENTRY _EXPFUNC isgraph (int __c);
int _RTLENTRY _EXPFUNC islower (int __c);
int _RTLENTRY _EXPFUNC isprint (int __c);
int _RTLENTRY _EXPFUNC ispunct (int __c);
int _RTLENTRY _EXPFUNC isspace (int __c);
int _RTLENTRY _EXPFUNC isupper (int __c);
int _RTLENTRY _EXPFUNC isxdigit(int __c);
int _RTLENTRY _EXPFUNC isascii (int __c);

int _RTLENTRY _EXPFUNC iswalnum (wint_t __c);
int _RTLENTRY _EXPFUNC iswalpha (wint_t __c);
int _RTLENTRY _EXPFUNC iswcntrl (wint_t __c);
int _RTLENTRY _EXPFUNC iswdigit (wint_t __c);
int _RTLENTRY _EXPFUNC iswgraph (wint_t __c);
int _RTLENTRY _EXPFUNC iswlower (wint_t __c);
int _RTLENTRY _EXPFUNC iswprint (wint_t __c);
int _RTLENTRY _EXPFUNC iswpunct (wint_t __c);
int _RTLENTRY _EXPFUNC iswspace (wint_t __c);
int _RTLENTRY _EXPFUNC iswupper (wint_t __c);
int _RTLENTRY _EXPFUNC iswxdigit(wint_t __c);
int _RTLENTRY _EXPFUNC iswascii (wint_t __c);
#ifdef __cplusplus
}
#endif

/* character classes */

#define _IS_UPP    0x0001           /* upper case */
#define _IS_LOW    0x0002           /* lower case */
#define _IS_DIG    0x0004           /* digit */
#define _IS_SP     0x0008           /* space */
#define _IS_PUN    0x0010           /* punctuation */
#define _IS_CTL    0x0020           /* control */
#define _IS_BLK    0x0040           /* blank */
#define _IS_HEX    0x0080           /* [0..9] or [A-F] or [a-f] */
#define _IS_ALPHA  0x0100

#define _IS_ALNUM    (_IS_DIG | _IS_ALPHA)
#define _IS_GRAPH    (_IS_ALNUM | _IS_HEX | _IS_PUN)

#ifndef __USELOCALES__

/* C locale character classification macros */

#define isalnum(c)   (_chartype[ (c)+1 ] & (_IS_ALNUM))
#define isalpha(c)   (_chartype[ (c)+1 ] & (_IS_ALPHA))
#define iscntrl(c)   (_chartype[ (c)+1 ] & (_IS_CTL))
#define isdigit(c)   (_chartype[ (c)+1 ] & (_IS_DIG))
#define isgraph(c)   (_chartype[ (c)+1 ] & (_IS_GRAPH))
#define islower(c)   (_chartype[ (c)+1 ] & (_IS_LOW))
#define isprint(c)   (_chartype[ (c)+1 ] & (_IS_GRAPH | _IS_BLK))
#define ispunct(c)   (_chartype[ (c)+1 ] & (_IS_PUN))
#define isspace(c)   (_chartype[ (c)+1 ] & (_IS_SP))
#define isupper(c)   (_chartype[ (c)+1 ] & (_IS_UPP))
#define isxdigit(c)  (_chartype[ (c)+1 ] & (_IS_HEX))

#ifndef _UNICODE
#define iswalnum(c)   (_chartype[ (c)+1 ] & (_IS_ALNUM))
#define iswalpha(c)   (_chartype[ (c)+1 ] & (_IS_ALPHA))
#define iswcntrl(c)   (_chartype[ (c)+1 ] & (_IS_CTL))
#define iswdigit(c)   (_chartype[ (c)+1 ] & (_IS_DIG))
#define iswgraph(c)   (_chartype[ (c)+1 ] & (_IS_GRAPH))
#define iswlower(c)   (_chartype[ (c)+1 ] & (_IS_LOW))
#define iswprint(c)   (_chartype[ (c)+1 ] & (_IS_GRAPH | _IS_BLK))
#define iswpunct(c)   (_chartype[ (c)+1 ] & (_IS_PUN))
#define iswspace(c)   (_chartype[ (c)+1 ] & (_IS_SP))
#define iswupper(c)   (_chartype[ (c)+1 ] & (_IS_UPP))
#define iswxdigit(c)  (_chartype[ (c)+1 ] & (_IS_HEX))

#endif /* _UNICODE */

#endif /* __USELOCALES__ */

#define iswascii(c)  ((unsigned)(c) < 128)
#define isascii(c)  ((unsigned)(c) < 128)
#define toascii(c)  ((c) & 0x7f)

#ifdef __cplusplus
extern "C" {
#endif

int _RTLENTRY _EXPFUNC tolower(int __ch);
int _RTLENTRY _EXPFUNC _ltolower(int __ch);
int _RTLENTRY _EXPFUNC toupper(int __ch);
int _RTLENTRY _EXPFUNC _ltoupper(int __ch);

wint_t _RTLENTRY _EXPFUNC towlower(wint_t __ch);
wint_t _RTLENTRY _EXPFUNC towupper(wint_t __ch);
wchar_t _RTLENTRY _EXPFUNC _ltowupper(wchar_t __ch);
wchar_t _RTLENTRY _EXPFUNC _ltowlower(wchar_t __ch);

#if !defined(__STDC__)	/* NON-ANSI */
#define _toupper(c) ((c) + 'A' - 'a')
#define _tolower(c) ((c) + 'a' - 'A')
#endif


#ifdef __cplusplus
}
#endif

#if defined( __USELOCALES__ )

#define toupper    _ltoupper
#define tolower    _ltolower
#define towupper   _ltowupper
#define towlower   _ltowlower
#define _wcsupr    _lwcsupr
#define _wcslwr    _lwcslwr

#endif  /*  __USELOCALES__  */

#endif /* __FLAT__  */


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif /* __CTYPE_H */
