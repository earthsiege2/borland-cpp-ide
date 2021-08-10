/*  jstring.h

    Definitions for Japanese string functions.

*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#ifndef __JSTRING_H
#define __JSTRING_H

#include <_stddef.h>

#if !defined(__MBCTYPE_H)
#include <mbctype.h>
#endif

#if !defined(__MBSTRING_H)
#include <mbstring.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
char _FAR * _RTLENTRYF jstrncpy (char _FAR *__dest, const char _FAR *__src, _SIZE_T __maxlen);
char _FAR * _RTLENTRYF jstrncat (char _FAR *__dest, const char _FAR *__src, _SIZE_T __maxlen);
char _FAR * _RTLENTRYF jstrchr  (const char _FAR *__s, unsigned short __c);
char _FAR * _RTLENTRYF jstrrchr (const char _FAR *__s, unsigned short __c);
char _FAR * _RTLENTRYF jstrtok  (char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF jstradv  (const char _FAR *__s, int __n);
char _FAR * _RTLENTRYF jstrmatch(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  jstrskip (const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  jstrrev  (char _FAR *__s);
char _FAR * _RTLENTRY  jstrstr  (const char _FAR *__s1, const char _FAR *__s2);
int         _RTLENTRYF jstrcmp  (const char _FAR *__s1, const char _FAR *__s2);
int         _RTLENTRYF jstricmp (const char _FAR *__s1, const char _FAR *__s2);
int         _RTLENTRYF jstrncmp (const char _FAR *__s1, const char _FAR *__s2, _SIZE_T __maxlen);
int         _RTLENTRYF jstrnicmp(const char _FAR *__s1, const char _FAR *__s2, _SIZE_T __maxlen);
_SIZE_T      _RTLENTRYF jstrlen  (const char _FAR *__s);
char _FAR * _RTLENTRYF jstrupr  (char _FAR *__s);
char _FAR * _RTLENTRYF jstrlwr  (char _FAR *__s);
_SIZE_T      _RTLENTRY  jstrcspn (const char _FAR *__s1, const char _FAR *__s2);
_SIZE_T      _RTLENTRY  jstrspn  (const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  jstrset  (char _FAR *__s, unsigned short __c);
char _FAR * _RTLENTRY  jstrnset (char _FAR *__s, unsigned short __c, _SIZE_T __maxlen);
int         _RTLENTRYF btom     (const char _FAR *__s, int __nbyte);
int         _RTLENTRYF mtob     (const char _FAR *__s, int __nmoji);


#ifdef __cplusplus
}
#endif

#ifndef __CHKCTYPE
#define __CHKCTYPE

/* values used in chkctype(), nthctype() */
#define CT_ANK          _MBC_SINGLE
#define CT_KJ1          _MBC_LEAD
#define CT_KJ2          _MBC_TRAIL
#define CT_ILGL         _MBC_ILLEGAL

#ifdef __cplusplus
extern "C" {
#endif
int _RTLENTRYF chkctype(char __c, int __mode);
int _RTLENTRYF nthctype(const char _FAR *__s, int __nbyte);
#ifdef __cplusplus
}
#endif
#endif /* __CHKCTYPE */

#ifdef _MSC
#define jiszen      _ismbclegal
#define jisl0       _ismbcl0
#define jisl1       _ismbcl1
#define jisl2       _ismbcl2
#define jiskata     _ismbckata
#define jishira     _ismbchira
#define jiskigou    _ismbcsymbol
#define jisprint    _ismbcprint
#define jtohira     _mbctohira
#define jtokata     _mbctokata
#define zentohan    _mbctombb
#define hantozen    _mbbtombc
#define jistojms    _mbcjistojms
#define jmstojis    _mbcjmstojis
#define jisalpha    _ismbcalpha
#define jisupper    _ismbcupper
#define jislower    _ismbclower
#define jisdigit    _ismbcdigit
#define jisspace    _ismbcspace
#define jtolower    _mbctolower
#define jtoupper    _mbctoupper
#define jstrncpy    _mbsncpy
#define jstrncat    _mbsncat
#define jstrchr     _mbschr
#define jstrrchr    _mbsrchr
#define jstrtok     _mbstok
#define jstradv     _mbsninc
#define jstrmatch   _mbspbrk
#define jstrskip    _mbsspnp
#define jstrrev     _mbsrev
#define jstrstr     _mbsstr
#define jstrcmp     _mbscmp
#define jstrncmp    _mbsncmp
#define jstrlen     _mbslen
#define jstrcspn    _mbscspn
#define jstrspn     _mbsspn
#define jstrset     _mbsset
#define jstrnset    _mbsnset
#define btom        _mbsnccnt
#define mtob        _mbsnbcnt
#define jstricmp    _mbsicmp
#define jstrnicmp   _mbsnicmp
#define jstrupr     _mbsupr
#define jstrlwr     _mbslwr
#define chkctype    _mbbtype
#define nthctype    _mbsbtype
#endif  /* _MSC */


#endif /* __JSTRING_H */
