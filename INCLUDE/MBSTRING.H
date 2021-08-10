/*  mbstring.h

    Definitions for MBCS string functions.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.7  $ */

#ifndef __MBSTRING_H
#define __MBSTRING_H

#ifdef _MSC
#if !defined(__STRING_H)
#include <string.h>
#endif
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#include <mbctype.h>

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbscpy   (unsigned char *__dest, const unsigned char *__src);
unsigned char * _RTLENTRY _EXPFUNC _mbscat   (unsigned char *__dest, const unsigned char *__src);
unsigned char * _RTLENTRY _EXPFUNC _mbsncpy  (unsigned char *__dest, const unsigned char *__src, size_t __maxlen);
unsigned char * _RTLENTRY _EXPFUNC _mbsncat  (unsigned char *__dest, const unsigned char *__src, size_t __maxlen);
unsigned char * _RTLENTRY _EXPFUNC _mbsnbcpy (unsigned char *__dest, const unsigned char *__src, size_t __maxlen);
unsigned char * _RTLENTRY _EXPFUNC _mbsnbcat (unsigned char *__dest, const unsigned char *__src, size_t __maxlen);
void            _RTLENTRY _EXPFUNC _mbccpy   (unsigned char *__dest, const unsigned char *__src);
unsigned char * _RTLENTRY _EXPFUNC _mbsdup   (const unsigned char *__s);
unsigned char * _RTLENTRY _EXPFUNC _mbschr   (const unsigned char *__s, unsigned int __c);
unsigned char * _RTLENTRY _EXPFUNC _mbsrchr  (const unsigned char *__s, unsigned int __c);
size_t          _RTLENTRY _EXPFUNC _mbscspn  (const unsigned char *__s1, const unsigned char *__s2);
size_t          _RTLENTRY _EXPFUNC _mbsspn   (const unsigned char *__s1, const unsigned char *__s2);
unsigned char * _RTLENTRY _EXPFUNC _mbspbrk  (const unsigned char *__s1, const unsigned char *__s2);
unsigned char * _RTLENTRY _EXPFUNC _mbsspnp  (const unsigned char *__s1, const unsigned char *__s2);
unsigned char * _RTLENTRY _EXPFUNC _mbsinc   (const unsigned char *__p);
unsigned char * _RTLENTRY _EXPFUNC _mbsninc  (const unsigned char *__p, size_t __n);
unsigned char * _RTLENTRY _EXPFUNC _mbsdec   (const unsigned char *__s, const unsigned char *__p);
unsigned char * _RTLENTRY _EXPFUNC _mbstok   (unsigned char *__s1, const unsigned char *__s2);
unsigned char * _RTLENTRY _EXPFUNC _mbsrev   (unsigned char *__s);
unsigned char * _RTLENTRY _EXPFUNC _mbsstr   (const unsigned char *__s1, const unsigned char *__s2);
int             _RTLENTRY _EXPFUNC _mbscmp   (const unsigned char *__s1, const unsigned char *__s2);
int             _RTLENTRY _EXPFUNC _mbsicmp  (const unsigned char *__s1, const unsigned char *__s2);
int             _RTLENTRY _EXPFUNC _mbsncmp  (const unsigned char *__s1, const unsigned char *__s2, size_t __maxlen);
int             _RTLENTRY _EXPFUNC _mbsnicmp (const unsigned char *__s1, const unsigned char *__s2, size_t __maxlen);
int             _RTLENTRY _EXPFUNC _mbsnbcmp (const unsigned char *__s1, const unsigned char *__s2, size_t __maxlen);
int             _RTLENTRY _EXPFUNC _mbsnbicmp(const unsigned char *__s1, const unsigned char *__s2, size_t __maxlen);
size_t          _RTLENTRY _EXPFUNC _mbslen   (const unsigned char *__s);
size_t          _RTLENTRY _EXPFUNC _mbclen   (const unsigned char *__s);
unsigned char * _RTLENTRY _EXPFUNC _mbsupr   (unsigned char *__s);
unsigned char * _RTLENTRY _EXPFUNC _mbslwr   (unsigned char *__s);
unsigned char * _RTLENTRY _EXPFUNC _mbsset   (unsigned char *__s, unsigned int __c);
unsigned char * _RTLENTRY _EXPFUNC _mbsnset  (unsigned char *__s, unsigned int __c, size_t __maxlen);
unsigned char * _RTLENTRY _EXPFUNC _mbsnbset (unsigned char *__s, unsigned int __c, size_t __maxlen);
size_t          _RTLENTRY _EXPFUNC _mbsnccnt (const unsigned char *__s, size_t __nbyte);
size_t          _RTLENTRY _EXPFUNC _mbsnbcnt (const unsigned char *__s, size_t __nmbc);
unsigned int    _RTLENTRY _EXPFUNC _mbsnextc (const unsigned char *__p);
int             _RTLENTRY _EXPFUNC _mbbtype  (unsigned char __c, int __mode);
int             _RTLENTRY _EXPFUNC _mbsbtype (const unsigned char *__s, size_t __nbyte);

#ifndef __MBCS_LEADTRAIL
#define __MBCS_LEADTRAIL
int _RTLENTRY _EXPFUNC _ismbblead  (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbbtrail (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbslead  (const unsigned char *__s1, const unsigned char *__s2);
int _RTLENTRY _EXPFUNC _ismbstrail (const unsigned char *__s1, const unsigned char *__s2);

#endif  /* ! __MBCS_LEADTRAIL */

#define _mbccmp(__s1, __s2) _mbsncmp((__s1),(__s2),1)

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
int _RTLENTRY _EXPFUNC _ismbclegal(unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcalpha(unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcdigit(unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcprint(unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcspace(unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbclower(unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcupper(unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbctolower(unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbctoupper(unsigned int __c);
#ifdef __cplusplus
}
#endif


/* Japanese DBCS special functions */
#ifdef __cplusplus
extern "C" {
#endif
int _RTLENTRY _EXPFUNC _ismbchira  (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbckata  (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcl0    (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcl1    (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcl2    (unsigned int __c);
int _RTLENTRY _EXPFUNC _ismbcsymbol(unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbctohira  (unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbctokata  (unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbctombb   (unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbbtombc   (unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbcjistojms(unsigned int __c);
unsigned int _RTLENTRY _EXPFUNC _mbcjmstojis(unsigned int __c);
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

int _RTLENTRY _EXPFUNC _mbscoll( const unsigned char *__S1, const unsigned char *__S2 );
int _RTLENTRY _EXPFUNC _mbsicoll( const unsigned char *__S1, const unsigned char *__S2 );
int _RTLENTRY _EXPFUNC _mbsncoll( const unsigned char *__S1, const unsigned char *__S2, size_t n );
int _RTLENTRY _EXPFUNC _mbsnicoll( const unsigned char *__S1, const unsigned char *__S2, size_t n );
int _RTLENTRY _EXPFUNC _mbsnbcoll( const unsigned char *__S1, const unsigned char *__S2, size_t n );
int _RTLENTRY _EXPFUNC _mbsnbicoll( const unsigned char *__S1, const unsigned char *__S2, size_t n );

int _RTLENTRY _EXPFUNC _ismbcalnum( unsigned int __c );
int _RTLENTRY _EXPFUNC _ismbcgraph( unsigned int __c );
int _RTLENTRY _EXPFUNC _ismbcpunct( unsigned int __c );
#ifdef __cplusplus
}
#endif

#endif /* __MBSTRING_H */
