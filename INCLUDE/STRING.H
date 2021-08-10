/*  string.h

    Definitions for memory and string functions.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.16  $ */

#if !defined(__USING_STD_NAMES__)

#ifndef __STRING_H
#define __STRING_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef __STDDEF_H
#include <stddef.h>
#endif

#if !defined(NULL)
#include <_null.h>
#endif

#if !defined(__STDC__) && defined(__USELOCALES__)
#if !defined(__LOCALE_H)
#include <locale.h>
#endif
#endif  /* !__STDC__ && __USELOCALES__ */

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifdef __cplusplus
extern "C" {
#endif


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#define wcscmpi(s1,s2)      _wcsicmp(s1,s2)
#define _wcscmpi(s1,s2)     _wcsicmp(s1,s2)
#define wcsncmpi(s1,s2,n)   _wcsnicmp(s1,s2,n)
#define _wcsncmpi(s1,s2,n)  _wcsnicmp(s1,s2,n)

size_t          _RTLENTRY  _EXPFUNC wcslen(const wchar_t *__s);
wchar_t *       _RTLENTRY  _EXPFUNC wcscpy(wchar_t *__dst, const wchar_t *__src);
wchar_t *       _RTLENTRY  _EXPFUNC wcscat(wchar_t *__dest, const wchar_t *__src);
wchar_t *       _RTLENTRY  _EXPFUNC wcschr(const wchar_t *__s, int __c);
int             _RTLENTRY  _EXPFUNC wcscmp(const wchar_t *__s1, const wchar_t *__s2);
int             _RTLENTRY  _EXPFUNC wcscoll(const wchar_t * __s1, const wchar_t * __s2);
size_t          _RTLENTRY  _EXPFUNC wcscspn(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsdup(const wchar_t *__s);
int             _RTLENTRY  _EXPFUNC wcsncmp(const wchar_t *__s1, const wchar_t *__s2, size_t __maxlen);
wchar_t *       _RTLENTRY  _EXPFUNC wcsncpy(wchar_t *__dest, const wchar_t *__src, size_t __maxlen);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsnset(wchar_t *__s, wchar_t __ch, size_t __n);
wchar_t *       _RTLENTRY  _EXPFUNC wcspbrk(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcsrchr(const wchar_t *__s, wchar_t __c);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsrev(wchar_t *__s);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsset(wchar_t*__s, wchar_t __ch);
size_t          _RTLENTRY  _EXPFUNC wcsspn(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcsstr(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcstok(wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcsncat(wchar_t *__dest, const wchar_t *__src, size_t __maxlen);
wchar_t *       _RTLENTRY  _EXPFUNC wcspcpy(wchar_t *__dest, const wchar_t *__src);
wchar_t *       _RTLENTRY  _EXPFUNC _wcspcpy(wchar_t *__dest, const wchar_t *__src);
int             _RTLENTRY  _EXPFUNC _wcsicmp(const wchar_t *__s1, const wchar_t *__s2);
int             _RTLENTRY  _EXPFUNC _wcsnicmp(const wchar_t *__s1, const wchar_t *__s2, size_t __maxlen);
void *          _RTLENTRY  _EXPFUNC _wmemset(void *__s, int __c, size_t __n);
wchar_t *       _RTLENTRYF _EXPFUNC _wcslwr(wchar_t *__s);
wchar_t *       _RTLENTRYF _EXPFUNC _wcsupr(wchar_t *__s);
wchar_t *       _RTLENTRYF _EXPFUNC _lwcslwr(wchar_t *__s);
wchar_t *       _RTLENTRYF _EXPFUNC _lwcsupr(wchar_t *__s);
void *          _RTLENTRY  _EXPFUNC _wmemcpy(void *__dest, const void *__src, size_t __n);

int         _RTLENTRY  _EXPFUNC memcmp(const void _FAR *__s1,
                                       const void _FAR *__s2, size_t __n);
void _FAR * _RTLENTRY  _EXPFUNC memcpy(void _FAR *__dest, const void _FAR *__src,
                                       size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC memmove(void _FAR *__dest, const void _FAR *__src,
                                        size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC memset(void _FAR *__s, int __c, size_t __n);
char _FAR * _RTLENTRYF _EXPFUNC strcat(char _FAR *__dest, const char _FAR *__src);
int         _RTLENTRYF _EXPFUNC strcmp(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC strcpy(char _FAR *__dest, const char _FAR *__src);
size_t      _RTLENTRY  _EXPFUNC strcspn(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  _EXPFUNC strerror(int __errnum);
size_t      _RTLENTRYF _EXPFUNC strlen(const char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC strncat(char _FAR *__dest, const char _FAR *__src,
                                        size_t __maxlen);
int         _RTLENTRYF _EXPFUNC strncmp(const char _FAR *__s1, const char _FAR *__s2,
                                        size_t __maxlen);
char _FAR * _RTLENTRYF _EXPFUNC strncpy(char _FAR *__dest, const char _FAR *__src,
                                        size_t __maxlen);
size_t      _RTLENTRY  _EXPFUNC strspn(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC strtok(char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  _EXPFUNC _strerror(const char _FAR *__s);


#if !defined(__STDC__)
/* compatibility with other compilers */
#define strcmpi(s1,s2)      stricmp(s1,s2)
#define strncmpi(s1,s2,n)   strnicmp(s1,s2,n)

char _FAR * _RTLENTRYF _EXPFUNC   _lstrlwr(char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC   _lstrupr(char _FAR *__s);
void _FAR * _RTLENTRY  _EXPFUNC   memccpy(void _FAR *__dest, const void _FAR *__src,
                                          int __c, size_t __n);
int         _RTLENTRY  _EXPFUNC   memicmp(const void _FAR *__s1, const void _FAR *__s2,
                                          size_t __n);
char _FAR * _RTLENTRYF _EXPFUNC32 stpcpy(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC32 _stpcpy(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC   strdup(const char _FAR *__s);
int         _RTLENTRYF _EXPFUNC   stricmp(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC   strlwr(char _FAR *__s);
int         _RTLENTRYF _EXPFUNC   strnicmp(const char _FAR *__s1, const char _FAR *__s2,
                                           size_t __maxlen);
char _FAR * _RTLENTRY  _EXPFUNC   strnset(char _FAR *__s, int __ch, size_t __n);
char _FAR * _RTLENTRY  _EXPFUNC   strrev(char _FAR *__s);
char _FAR * _RTLENTRY  _EXPFUNC   strset(char _FAR *__s, int __ch);
char _FAR * _RTLENTRYF _EXPFUNC   strupr(char _FAR *__s);
#endif  /* !__STDC__ */


#if defined(__cplusplus)
extern "C++"
{
          void _FAR * _RTLENTRY  _EXPFUNC32 memchr(void _FAR *__s, int __c, size_t __n);
    const void _FAR * _RTLENTRY  _EXPFUNC32 memchr(const void _FAR *__s, int __c, size_t __n);
#if defined(__FLAT__)
          void      * _RTLENTRY  _EXPFUNC32 _wmemchr(void *__s, int __c, size_t __n);
    const void      * _RTLENTRY  _EXPFUNC32 _wmemchr(const void *__s, int __c, size_t __n);
#endif
          char _FAR * _RTLENTRYF _EXPFUNC   strchr(char _FAR * __s, int __c);
    const char _FAR * _RTLENTRYF _EXPFUNC   strchr(const char _FAR * __s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strrchr(char _FAR *__s, int __c);
    const char _FAR * _RTLENTRYF _EXPFUNC   strrchr(const char _FAR *__s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strpbrk(char _FAR *__s1, const char _FAR *__s2);
    const char _FAR * _RTLENTRYF _EXPFUNC   strpbrk(const char _FAR *__s1, const char _FAR *__s2);
          char _FAR * _RTLENTRY  _EXPFUNC   strstr(char _FAR *__s1, const char _FAR *__s2);
    const char _FAR * _RTLENTRY  _EXPFUNC   strstr(const char _FAR *__s1, const char _FAR *__s2);
}
#else
          void _FAR * _RTLENTRY  _EXPFUNC32 memchr(const void _FAR *__s, int __c, size_t __n);
#if defined(__FLAT__)
          void      * _RTLENTRY  _EXPFUNC32 _wmemchr(const void *__s, int __c, size_t __n);
#endif
          char _FAR * _RTLENTRYF _EXPFUNC   strchr(const char _FAR * __s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strrchr(const char _FAR *__s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strpbrk(const char _FAR *__s1, const char _FAR *__s2);
          char _FAR * _RTLENTRY  _EXPFUNC   strstr(const char _FAR *__s1, const char _FAR *__s2);
#endif


/* Intrinsic functions */
#if !defined(__MEM_H)
void _FAR * _RTLENTRY  _EXPFUNC16 __memchr__(const void _FAR *__s, int __c, size_t __n);
int         _RTLENTRY  _EXPFUNC16 __memcmp__(const void _FAR *__s1,
                                             const void _FAR *__s2, size_t __n);
void _FAR * _RTLENTRY  _EXPFUNC16 __memcpy__(void _FAR *__dest, const void _FAR *__src,
                                             size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC16 __memset__(void _FAR *__s, int __c, size_t __n);
#endif

char _FAR * _RTLENTRY             __stpcpy__(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRYF _EXPFUNC16 __strcat__(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC16 __strchr__(const char _FAR *__s, int __c);
int         _RTLENTRYF _EXPFUNC16 __strcmp__(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC16 __strcpy__(char _FAR *__dest, const char _FAR *__src);
size_t      _RTLENTRYF _EXPFUNC16 __strlen__(const char _FAR *__s);
char _FAR * _RTLENTRY  _EXPFUNC16 __strncat__(char _FAR *__dest, const char _FAR *__src,
                                              size_t __maxlen);
int         _RTLENTRY  _EXPFUNC16 __strncmp__(const char _FAR *__s1, const char _FAR *__s2,
                                              size_t __maxlen);
char _FAR * _RTLENTRYF _EXPFUNC16 __strncpy__(char _FAR *__dest, const char _FAR *__src,
                                              size_t __maxlen);
char _FAR * _RTLENTRY  _EXPFUNC16 __strnset__(char _FAR *__s, int __ch, size_t __n);
char _FAR * _RTLENTRYF _EXPFUNC16 __strrchr__(const char _FAR *__s, int __c);
char _FAR * _RTLENTRY  _EXPFUNC16 __strset__(char _FAR *__s, int __ch);

#if defined(__MSC) && !defined(__MFC_COMPAT__)
#define _stricmp(s1,s2) stricmp(s1,s2)
#define _strdup(s1)     strdup(s1)
#define _strupr(s1)     strupr(s1)
#define _strlwr(s1)     strlwr(s1)
#define _strrev(s1)     strrev(s1)
#endif  /* __MSC */

#if defined(__MFC_COMPAT__)
inline char _FAR * _RTLENTRY  _strrev(char _FAR *__s) { return strrev(__s); }

inline char _FAR * _RTLENTRY  _strset(char _FAR *__s, int __ch)
                              { return strset(__s, __ch); }
inline char _FAR * _RTLENTRY  _strnset(char _FAR *__s, int __ch, size_t __n)
                              { return strnset(__s, __ch, __n); }
inline char _FAR * _RTLENTRYF _strupr(char _FAR *__s) { return strupr(__s); }

inline char _FAR * _RTLENTRYF _strlwr(char _FAR *__s) { return strlwr(__s); }

inline char _FAR * _RTLENTRY  _strdup(const char _FAR *__s)
                              { return strdup(__s); }
inline int         _RTLENTRYF _strcmpi(const char _FAR *__s1, const char _FAR *__s2)
                              { return stricmp (__s1, __s2); }
inline int         _RTLENTRYF _stricmp(const char _FAR *__s1, const char _FAR *__s2)
                              { return stricmp (__s1, __s2); }
inline int         _RTLENTRYF _strcmp(const char _FAR *__s1, const char _FAR *__s2)
                              { return strcmp (__s1, __s2); }
inline int         _RTLENTRYF _strnicmp(const char _FAR *__s1, const char _FAR *__s2, size_t __maxlen)
                              { return strnicmp (__s1, __s2, __maxlen); }
#endif

#if !defined(__FLAT__) || defined(__DPMI32__)
void        _RTLENTRY  _EXPFUNC movedata(unsigned __srcseg,unsigned __srcoff,
                                         unsigned __dstseg,unsigned __dstoff, size_t __n);
#endif


#if !defined(__FLAT__)
int           _RTLENTRYF _EXPFUNC _lstrcoll(const char _FAR *__s1, const char _FAR *__s2);
size_t        _RTLENTRYF _EXPFUNC _lstrxfrm(char _FAR *__s1, const char _FAR *__s2,
                                            size_t __n );
int           _RTLENTRYF          strcoll(const char _FAR *__s1, const char _FAR *__s2);
size_t        _RTLENTRYF          strxfrm(char _FAR *__s1, const char _FAR *__s2,
                                          size_t __n );

#if !defined(__STDC__)
void  __far * _RTLENTRY _FARCALL  _fmemccpy(void __far *__dest, const void __far *__src,
                                            int c, size_t __n);
void  __far * _RTLENTRY _FARCALL  _fmemchr(const void __far *__s, int c, size_t __n);
int           _RTLENTRY _FARCALL  _fmemcmp(const void __far *__s1, const void __far *__s2,
                                           size_t __n);
void  __far * _RTLENTRY _FARCALL  _fmemcpy(void __far *__dest, const void __far *__src,
                                           size_t __n);
int           _RTLENTRY _FARCALL  _fmemicmp(const void __far *__s1, const void __far *__s2,
                                            size_t __n);
void  __far * _RTLENTRY _FARCALL  _fmemmove(void __far *__dest, const void __far *__src,
                                            size_t __n);
void  __far * _RTLENTRY _FARCALL  _fmemset(void __far *__s, int c, size_t __n);
void          _RTLENTRY _FARCALL  _fmovmem(const void __far *__src, void __far *__dest,
                                           unsigned __length);
void          _RTLENTRY _FARCALL  _fsetmem(void __far *__dest,unsigned __length,
                                           char __value);
char  __far * _RTLENTRY _FARCALL  _fstrcat(char __far *__dest, const char __far *__src);
char  __far * _RTLENTRY _FARCALL  _fstrchr(const char __far *__s, int c);
int           _RTLENTRY _FARCALL  _fstrcmp(const char __far *__s1, const char __far *__s2);
char  __far * _RTLENTRY _FARCALL  _fstrcpy(char __far *__dest, const char __far *__src);
size_t        _RTLENTRY _FARCALL  _fstrcspn(const char __far *__s1, const char __far *__s2);
char  __far * _RTLENTRY _FARCALL  _fstrdup(const char __far *__s);
int           _RTLENTRY _FARCALL  _fstricmp(const char __far *__s1, const char __far *__s2);
size_t        _RTLENTRY _FARCALL  _fstrlen(const char __far *__s);
char  __far * _RTLENTRY _FARCALL  _fstrlwr(char __far *__s);
char  __far * _RTLENTRY _FARCALL  _fstrncat(char __far *__dest, const char __far *__src,
                                            size_t maxlen);
int           _RTLENTRY _FARCALL  _fstrncmp(const char __far *__s1, const char __far *__s2,
                                            size_t maxlen);
char  __far * _RTLENTRY _FARCALL  _fstrncpy(char __far *__dest, const char __far *__src,
                                            size_t maxlen);
int           _RTLENTRY _FARCALL  _fstrnicmp(const char __far *__s1, const char __far *__s2,
                                             size_t maxlen);
char  __far * _RTLENTRY _FARCALL  _fstrnset(char __far *__s, int ch, size_t __n);
char  __far * _RTLENTRY _FARCALL  _fstrpbrk(const char __far *__s1, const char __far *__s2);
char  __far * _RTLENTRY _FARCALL  _fstrrchr(const char __far *__s, int c);
char  __far * _RTLENTRY _FARCALL  _fstrrev(char __far *__s);
char  __far * _RTLENTRY _FARCALL  _fstrset(char __far *__s, int ch);
size_t        _RTLENTRY _FARCALL  _fstrspn(const char __far *__s1, const char __far *__s2);
char  __far * _RTLENTRY _FARCALL  _fstrstr(const char __far *__s1, const char __far *__s2);
char  __far * _RTLENTRY _FARCALL  _fstrtok(char __far *__s1, const char __far *__s2);
char  __far * _RTLENTRY _FARCALL  _fstrupr(char __far *__s);
#endif  /* ! __STDC__ */


#else    /* defined __FLAT__ */


int    _RTLENTRY  _EXPFUNC _lstrcoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _lstricoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _lstrncoll(const char * __s1, const char * __s2, const int len);
int    _RTLENTRY  _EXPFUNC _lstrnicoll(const char * __s1, const char * __s2, int len);
size_t _RTLENTRY  _EXPFUNC _lstrxfrm(char * __s1, const char * __s2,size_t __n );
int    _RTLENTRY  _EXPFUNC strcoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _stricoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _strncoll(const char * __s1, const char * __s2, size_t __n);
int    _RTLENTRY  _EXPFUNC _strnicoll(const char * __s1, const char * __s2, int len);
size_t _RTLENTRY  _EXPFUNC strxfrm(char * __s1, const char * __s2,size_t __n );

int    _RTLENTRY  _EXPFUNC _lwcscoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _lwcsicoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _lwcsncoll(const wchar_t * __s1, const wchar_t * __s2, const int len);
int    _RTLENTRY  _EXPFUNC _lwcsnicoll(const wchar_t * __s1, const wchar_t * __s2, int len);
size_t _RTLENTRY  _EXPFUNC _lwcsxfrm(wchar_t * __s1, const wchar_t * __s2,size_t __n );
int    _RTLENTRY  _EXPFUNC wcscoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _wcsicoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _wcsncoll(const wchar_t * __s1, const wchar_t * __s2, size_t __n);
int    _RTLENTRY  _EXPFUNC _wcsnicoll(const wchar_t * __s1, const wchar_t * __s2, int len);
size_t _RTLENTRY  _EXPFUNC wcsxfrm(wchar_t * __s1, const wchar_t * __s2, size_t __n );


#if !defined(__STDC__) /* NON_ANSI  */
#define _fmemccpy  memccpy
#define _fmemchr   memchr
#define _fmemcmp   memcmp
#define _fmemcpy   memcpy
#define _fmemicmp  memicmp
#define _fmemmove  memmove
#define _fmemset   memset
#define _fmovmem   movmem
#define _fsetmem   setmem
#define _fstrcat   strcat
#define _fstrchr   strchr
#define _fstrcmp   strcmp
#define _fstrcpy   strcpy
#define _fstrcspn  strcspn
#define _fstrdup   strdup
#define _fstricmp  stricmp
#define _fstrlen   strlen
#define _fstrlwr   strlwr
#define _fstrncat  strncat
#define _fstrncmp  strncmp
#define _fstrncpy  strncpy
#define _fstrnicmp strnicmp
#define _fstrnset  strnset
#define _fstrpbrk  strpbrk
#define _fstrrchr  strrchr
#define _fstrrev   strrev
#define _fstrset   strset
#define _fstrspn   strspn
#define _fstrstr   strstr
#define _fstrtok   strtok
#define _fstrupr   strupr
#endif /* __STDC__  */

#endif  /* __FLAT__ */

#if defined(__USELOCALES__)
#define  strupr     _lstrupr
#define  strlwr     _lstrlwr
#define  strcoll    _lstrcoll
#define  stricoll   _lstricoll
#define  strncoll   _lstrncoll
#define  strnicoll  _lstrnicoll
#define  strxfrm    _lstrxfrm
#endif  /* __USELOCALES__ */

#ifdef __cplusplus
}
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __STRING_H */

#else   /* __USING_STD_NAMES__ */

#ifndef __STD_STRING
#define __STD_STRING

/***************************************************************************
 *
 * string - Declarations for the Standard Library string classes
 *
 * $Id: string,v 1.116 1995/10/03 00:03:27 smithey Exp $
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
#include <cstddef>
#include <cstring>
#include <cctype>
#else
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#endif

#include <memory>     // For allocator.
#include <algorith>
#include <iterator>

#ifdef RWSTD_MULTI_THREAD
#include <stdmutex.h>
#endif

#ifndef RWSTD_NO_WSTR
#ifndef RWSTD_NO_NEW_HEADER
#include <cwctype>
#include <cwchar>
#else
#ifndef RWSTD_NO_WCTYPE_H
# include <wctype.h>
#endif
#include <wchar.h>
#endif
#endif

#ifdef RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif

//
// Temporarily turn off the warnings under the Borland compiler that
// say 'Functions containing ... cannot be inlined'
//
#if defined(__BORLANDC__)
#pragma warn -inl
#endif


//
// Extra comment after = d keeps > and > from being put together
// if the default parameter is a templated type and is also the
// last in the template parameter list
//

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
#define RWSTD_TDFLT(d) = d /* */
#else
#define RWSTD_TDFLT(d) /* */
#endif

#ifdef RW_STD_ALLOCATOR
#define RWSTD_ALLOC_TYPE(t) allocator
#else
#define RWSTD_ALLOC_TYPE(t) allocator<t>
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Global error message declarations
//

extern char RWSTDExport rwse_InvalidSizeParam[];
extern char RWSTDExport rwse_PosBeyondEndOfString[];
extern char RWSTDExport rwse_ResultLenInvalid[];
extern char RWSTDExport rwse_StringIndexOutOfRange[];
extern char RWSTDExport rwse_UnexpectedNullPtr[];

//
// Class & Structure Declarations
//

template<class charT> struct ios_traits;
template<class charT> struct string_char_traits;

template< class charT, class traits RWSTD_TDFLT(string_char_traits<charT>),
  class Allocator RWSTD_TDFLT(RWSTD_ALLOC_TYPE(charT)) >
class string_ref;

template< class charT,  class traits RWSTD_TDFLT(string_char_traits<charT>),
 class Allocator RWSTD_TDFLT(RWSTD_ALLOC_TYPE(charT)) >
class basic_string;

//
// string_char_traits structure definition
//
// Header right out of the working paper.
//

template <class charT>
struct string_char_traits
{
  typedef charT char_type;

#ifdef RW_STD_IOSTREAM
  typedef basic_istream<char_type, ios_traits<char_type> > istream_type;
  typedef basic_ostream<char_type, ios_traits<char_type> > ostream_type;
#endif

  static void assign (char_type& c1, const char_type& c2)   { c1 = c2;         }
  static bool eq (const char_type& c1, const char_type& c2) { return c1 == c2; }
  static bool ne (const char_type& c1, const char_type& c2) { return !(c1==c2);}
  static bool lt (const char_type& c1, const char_type& c2) { return c1 < c2;  }
  static char_type eos ()  { return char_type(); }

#ifdef RW_STD_IOSTREAM
  static istream_type& char_in  (istream_type& is, char_type& a) { is.get(a); return is;}
  static ostream_type& char_out (ostream_type& os, char_type  a) { return os<<a;}
#endif

  static bool is_del (char_type a)  { return isspace(a); }   // Delimiter

  static int compare (const char_type* s1, const char_type* s2, size_t n)
  {
    int result = 0;
    for (size_t i = 0; i < n && result == 0; ++i, ++s1, ++s2)
      if (ne(*s1, *s2))
        result = lt(*s1, *s2) ? -1 : 1;
    return result;
  }
  static size_t length (const char_type * s)
  {
    size_t l = 0;
    while (ne(*s++, eos()))  ++l;
    return l;
  }
  static char_type* copy (char_type* s1, const char_type* s2, size_t n)
  {
    char_type* s = s1;
    for (size_t i = 0; i < n; i++)  assign(*s1++, *s2++);
    return s;
  }
  static char_type* move (char_type* s1, const char_type* s2, size_t n)
  {
    char_type * s = s1;
    if (s1 < s2)
      copy(s1, s2, n);
    else if (s1 > s2)
    {
      s1 += n;
      s2 += n;
      for(size_t i = 0; i < n; ++i) assign(*--s1, *--s2);
    }
    return s;
  }
};

class RWSTDExport string_char_traits<char>
{
 public:
  typedef char char_type;

#ifdef RW_STD_IOSTREAM
  typedef basic_istream<char, ios_traits<char> > istream_type;
  typedef basic_ostream<char, ios_traits<char> > ostream_type;
#else
  typedef istream istream_type;
  typedef ostream ostream_type;
#endif

  static void assign (char_type& c1, const char_type& c2)   { c1 = c2; }
  static bool eq (const char_type& c1, const char_type& c2) { return c1 == c2;}
  static bool ne (const char_type& c1, const char_type& c2) { return c1 != c2;}
  static bool lt (const char_type& c1, const char_type& c2) { return c1 < c2;}
  static char_type eos () { return 0; }

  static istream_type& char_in  (istream_type& is, char_type& a) { is.get(a); return is;}
  static ostream_type& char_out (ostream_type& os, char_type  a) { os.put(a); return os; }

  static bool is_del (char_type a)  { return isspace(a); }

  static int compare (const char_type* s1, const char_type* s2, size_t n)
  {
    return memcmp(s1, s2, n);
  }
  static size_t length (const char_type* s)
  {
    return strlen(s);
  }
  static char_type * copy (char_type* s1, const char_type* s2, size_t n)
  {
    return (char_type *) memcpy(s1, s2, n);
  }
  static char_type * move (char_type* s1, const char_type* s2, size_t n)
  {
#ifndef RWSTD_NO_MEMMOVE
    return (char_type *) memmove(s1, s2, n);
#else
    char_type * s = s1;
    if (s1 < s2)
      copy(s1, s2, n);
    else if (s1 > s2)
    {
      s1 += n;
      s2 += n;
      for(size_t i = 0; i < n; ++i) assign(*--s1, *--s2);
    }
    return s;
#endif
  }
};

#ifndef RWSTD_NO_WSTR
struct RWSTDExport string_char_traits<wchar_t>
{
  typedef wchar_t char_type;

#ifdef RW_STD_IOSTREAM
  typedef basic_istream<char_type, ios_traits<char_type> > istream_type;
  typedef basic_ostream<char_type, ios_traits<char_type> > ostream_type;
#else
  typedef istream istream_type;
  typedef ostream ostream_type;
#endif

  static void assign (char_type& c1, const char_type& c2)   { c1 = c2; }
  static bool eq (const char_type& c1, const char_type& c2) { return c1 == c2;}
  static bool ne (const char_type& c1, const char_type& c2) { return c1 != c2;}
  static bool lt (const char_type& c1, const char_type& c2) { return c1 < c2;}
  static char_type eos ()  { return 0; }

#ifdef RW_STD_IOSTREAM
  static istream_type& char_in  (istream_type& is, char_type& a) { is.get(a); return is;}
  static ostream_type& char_out (ostream_type& os, char_type  a) { return os<<a;}
#else
  static istream_type& char_in (istream_type& is, char_type& a)
  {
    char c;
    is.get(c);
    char_type wc;
    mbtowc(&wc,&c,1);
    a = wc;
    return is;
  }
  static ostream_type& char_out (ostream_type& os, char_type a)
  {
    char c[RWSTD_MB_CUR_MAX+1];
    int i;
    if (i = wctomb(c,a) > 0)
    {
      c[i] = '\0';
      os << c;
    }
    return os;
  }
#endif

  static bool is_del (char a)  { return iswspace(a); }

  static int compare (const char_type* s1, const char_type* s2, size_t n)
  {
    return wcsncmp(s1, s2, n);
  }
  static size_t length(const char_type* s)  { return wcslen(s); }
  static char_type* copy(char_type* s1, const char_type* s2, size_t n)
  {
    return (char_type *) wcsncpy(s1, s2, n);
  }
  static char_type* move(char_type* s1, const char_type* s2, size_t n)
  {
    return (char_type *) wcsncpy(s1, s2, n);
  }
};
#endif /* not defined RWSTD_NO_WSTR */

template <class Allocator>
class string_ref_rep
{
 public:
  string_ref_rep() : refs_(0), capacity_(0), nchars_(0) {;}

#ifdef RWSTD_MULTI_THREAD
  RWSTDMutex mutex_;
#endif

  typedef typename Allocator::size_type    size_type;

 protected:

  unsigned long   refs_;      // (1 less than) number of references

  size_type       capacity_;  // Size of allocated memory
  size_type       nchars_;    // Number of actual data values stored
};

template <class charT, class traits, class Allocator>
struct null_string_ref_rep
{
  //
  // ref_hdr has to be immediately followed by eos_char !
  //
  string_ref_rep<Allocator>      ref_hdr;
  charT                          eos_char;

  null_string_ref_rep () : eos_char(traits::eos())  {;}
};

#ifdef RWSTD_NO_STATIC_DEF3
extern unsigned long RWSTDExport nullref[];
#endif

template <class charT, class traits, class Allocator>
class string_ref : public string_ref_rep<Allocator>
{
  typedef string_ref_rep<Allocator> string_ref_rep_type;

  string_ref (long initRef = 0) { refs_ = (unsigned long)initRef - 1; }

  unsigned references () const { return refs_+1; }

  void setRefCount (unsigned r)
  {
#ifdef RWSTD_MULTI_THREAD
      RWSTDGuard guard(this->mutex_);
#endif
      refs_ = r-1;
  }

  void addReference ()
  {
#ifdef RWSTD_MULTI_THREAD
      RWSTDGuard guard(this->mutex_);
#endif
      refs_++;
  }
  unsigned  removeReference ()
  {
#ifdef RWSTD_MULTI_THREAD
      RWSTDGuard guard(this->mutex_);
#endif
      return unSafeRemoveReference();
  }
unsigned  unSafeRemoveReference ()
  {
      return refs_--;
  }

  size_type length         () const           { return nchars_; }
  size_type getCapac       () const           { return capacity_;}
  charT*    data           () const           { return (charT*)(this+1); }

  charT&    operator[]     (size_type i)      { return ((charT*)(this+1))[i]; }
  charT     operator[]     (size_type i) const{ return ((charT*)(this+1))[i]; }

  //
  // Disconnect from this ref, maybe delete it.
  //
  void      unLink          (Allocator& alloc);
  void      unSafeunLink    (Allocator& alloc);

  friend class basic_string<charT, traits, Allocator>;
};


template <class charT, class traits, class Allocator >
class basic_string
{
  public:
    //
    // types
    //
    typedef traits                                            traits_type;
    typedef typename traits::char_type                        value_type;

#ifndef RWSTD_NO_COMPLICATED_TYPEDEF
    typedef typename Allocator::size_type                     size_type;
#else
    typedef size_t                                            size_type;
#endif
    typedef typename Allocator::difference_type               difference_type;

#ifdef RW_STD_ALLOCATOR
    typedef typename Allocator::types<charT>::reference       reference;
    typedef typename Allocator::types<charT>::const_reference const_reference;
    typedef typename Allocator::types<charT>::pointer         pointer;
    typedef typename Allocator::types<charT>::const_pointer   const_pointer;

    typedef typename Allocator::types<charT>::pointer         iterator;
    typedef typename Allocator::types<charT>::const_pointer   const_iterator;
#else
    typedef typename Allocator::reference                     reference;
    typedef typename Allocator::const_reference               const_reference;
    typedef typename Allocator::pointer                       pointer;
    typedef typename Allocator::const_pointer                 const_pointer;

    typedef typename Allocator::pointer                       iterator;
    typedef typename Allocator::const_pointer                 const_iterator;
#endif

    typedef reverse_iterator<const_iterator, value_type,
                    const_reference, difference_type>   const_reverse_iterator;
    typedef reverse_iterator<iterator, value_type,
                    reference, difference_type>         reverse_iterator;

    static const size_type npos;

    explicit basic_string (const Allocator& = Allocator());
    basic_string (const basic_string<charT, traits, Allocator>&);
    basic_string (const basic_string<charT, traits, Allocator>&, size_type,
                  size_type = npos, const Allocator& = Allocator());
    basic_string (const charT*, size_type, const Allocator& = Allocator());
    basic_string (const charT*, const Allocator& = Allocator());
    basic_string (size_type, charT, const Allocator& = Allocator());
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class InputIterator>
      basic_string (InputIterator, InputIterator, const Allocator&=Allocator());
#else
    basic_string (const charT*, const charT*, const Allocator& = Allocator());
#endif

   ~basic_string ();

    basic_string<charT, traits, Allocator>& operator= (const basic_string<charT, traits, Allocator>&);
    basic_string<charT, traits, Allocator>& operator= (const charT*);
    basic_string<charT, traits, Allocator>& operator= (charT);
    //
    // iterators
    //
    iterator       begin ()        { return data_;          }
    const_iterator begin () const  { return data_;          }
    iterator       end   ()        { return data_+length(); }
    const_iterator end   () const  { return data_+length(); }

    reverse_iterator rbegin ()
    {
        reverse_iterator tmp(end()); return tmp;
    }
    const_reverse_iterator rbegin () const
    {
        const_reverse_iterator tmp(end()); return tmp;
    }
    reverse_iterator rend ()
    {
        reverse_iterator tmp(begin()); return tmp;
    }
    const_reverse_iterator rend () const
    {
        const_reverse_iterator tmp(begin()); return tmp;
    }
    //
    // capacity
    //
    size_type length () const;
    size_type size () const      { return length(); }
    size_type max_size () const
    {
        return npos - sizeof(string_ref_rep<Allocator>);
    }
    void resize (size_type, charT);
    void resize (size_type);
    size_type capacity () const;
    void reserve (size_type);
    bool empty () const  { return length() == 0; }
    //
    // element access
    //
    charT           operator[] (size_type) const;
    reference       operator[] (size_type);
    const_reference at (size_type) const;
    reference       at (size_type);
    //
    // modifiers
    //
    basic_string<charT, traits, Allocator>& operator+= (const basic_string<charT, traits, Allocator>&);
    basic_string<charT, traits, Allocator>& operator+= (const charT*);
    basic_string<charT, traits, Allocator>& operator+= (charT);

    basic_string<charT, traits, Allocator>& append (const basic_string<charT, traits, Allocator>&,
                                                    size_type = 0,
                                                    size_type = npos);
    basic_string<charT, traits, Allocator>& append (const charT*, size_type);
    basic_string<charT, traits, Allocator>& append (const charT*);
    //
    // The WP defaults the second argument here.
    //
    basic_string<charT, traits, Allocator>& append (size_type, charT);
    //
    // This is currently not in the WP.
    //
    basic_string<charT, traits, Allocator>& append (charT c)
    {
        return append(1,c);
    }
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    basic_string<charT, traits, Allocator>& append (InputIterator,
                                                    InputIterator);
#else
    basic_string<charT, traits, Allocator>& append (const charT*,
                                                    const charT*);
#endif

    basic_string<charT, traits, Allocator>& assign (const basic_string<charT, traits, Allocator>&,
                                                    size_type = 0,
                                                    size_type = npos);
    basic_string<charT, traits, Allocator>& assign (const charT*, size_type);
    basic_string<charT, traits, Allocator>& assign (const charT*);
    //
    // The WP defaults the second argument here.
    //
    basic_string<charT, traits, Allocator>& assign (size_type, charT);
    //
    // This is currently not in the WP.
    //
    basic_string<charT, traits, Allocator>& assign (charT c)
    {
      return assign(1,c);
    }
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    basic_string<charT, traits, Allocator>& assign (InputIterator,
                                                    InputIterator);
#else
    basic_string<charT, traits, Allocator>& assign (const charT*,
                                                    const charT*);
#endif

    basic_string<charT, traits, Allocator>& insert (size_type,
                                                    const basic_string<charT, traits, Allocator>&,
                                                    size_type = 0,
                                                    size_type = npos);
    basic_string<charT, traits, Allocator>& insert (size_type,
                                                    const charT*,
                                                    size_type);
    basic_string<charT, traits, Allocator>& insert (size_type, const charT*);
    //
    // The WP defaults the third argument here.
    //
    basic_string<charT, traits, Allocator>& insert (size_type,size_type,charT);
    //
    // This is not currently defined by the WP.
    //
    basic_string<charT, traits, Allocator>& insert (size_type pos, charT c)
    {
        return insert(pos,1,c);
    }
    //
    // The WP defaults the third argument here.
    //
    iterator insert (iterator, size_type, charT);
    //
    // The WP defaults the second argument here.
    //
    iterator insert (iterator pos, charT c)
    {
        return insert(pos,1,c);
    }
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (iterator, InputIterator, InputIterator);
#else
    void insert (iterator, const charT*, const charT*);
#endif

    basic_string<charT, traits, Allocator>& remove (size_type = 0,
                                                    size_type = npos);
    basic_string<charT, traits, Allocator>& remove (iterator);
    basic_string<charT, traits, Allocator>& remove (iterator, iterator);

    void erase (iterator it) { remove(it); }
    void erase (iterator first, iterator last) { remove(first,last); }

private:
    //
    // Used for effiency
    //
    basic_string<charT, traits, Allocator>::iterator replace (size_type,
                                                              size_type,
                                                              const charT*,
                                                              size_type,
                                                              size_type,
                                                              size_type);
    basic_string<charT, traits, Allocator>::iterator replace_aux (size_type,
                                                                  size_type,
                                                                  const basic_string<charT, traits, Allocator>&,
                                                                  size_type =0,
                                                                  size_type =npos);
public:

    basic_string<charT, traits, Allocator>& replace (size_type,
                                                     size_type,
                                                     const basic_string<charT, traits, Allocator>&,
                                                     size_type = 0,
                                                     size_type = npos);
    basic_string<charT, traits, Allocator>& replace (size_type,
                                                     size_type,
                                                     const charT*,
                                                     size_type);
    basic_string<charT, traits, Allocator>& replace (size_type,
                                                     size_type,
                                                     const charT*);
    basic_string<charT, traits, Allocator>& replace (size_type,
                                                     size_type,
                                                     size_type,
                                                     charT);
    basic_string<charT, traits, Allocator>& replace (iterator,
                                                     iterator,
                                                     const basic_string<charT, traits, Allocator>&);
    basic_string<charT, traits, Allocator>& replace (iterator,
                                                     iterator,
                                                     const charT*,
                                                     size_type);
    basic_string<charT, traits, Allocator>& replace (iterator,
                                                     iterator,
                                                     const charT*);
    basic_string<charT, traits, Allocator>& replace (iterator,
                                                     iterator,
                                                     size_type,
                                                     charT);
    basic_string<charT, traits, Allocator>& replace (iterator first,
                                                     iterator last,
                                                     charT c)
    {
        return replace(first,last,1,c);
    }
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    basic_string<charT, traits, Allocator>& replace (iterator, iterator,
                                                     InputIterator,
                                                     InputIterator);
#else
    basic_string<charT, traits, Allocator>& replace (iterator, iterator,
                                                     const charT*,
                                                     const charT*);
#endif

    size_type copy (charT*, size_type, size_type = 0);
    basic_string<charT, traits, Allocator> copy () const; // Returns deep copy
    void swap(basic_string<charT, traits, Allocator>& s)
    {
        charT * temp = data_; data_ = s.data_; s.data_ = temp;
    }
    //
    // string operations
    //
    const charT* c_str () const;
    const charT* data  () const;

    size_type find (const basic_string<charT, traits, Allocator>&,
                    size_type = 0) const;
    size_type find (const charT*, size_type, size_type) const;
    size_type find (const charT*, size_type = 0) const;
    size_type find (charT, size_type = 0) const;

    size_type rfind (const basic_string<charT, traits, Allocator>&,
                     size_type = npos) const;
    size_type rfind (const charT*, size_type, size_type) const;
    size_type rfind (const charT*, size_type = npos) const;
    size_type rfind (charT, size_type = npos) const;

    size_type find_first_of (const basic_string<charT, traits, Allocator>&,
                             size_type = 0) const;
    size_type find_first_of (const charT*, size_type, size_type) const;
    size_type find_first_of (const charT*, size_type = 0) const;
    size_type find_first_of (charT, size_type = 0) const;

    size_type find_last_of (const basic_string<charT, traits, Allocator>&,
                            size_type = npos) const;
    size_type find_last_of (const charT*, size_type, size_type) const;
    size_type find_last_of (const charT*, size_type = npos) const;
    size_type find_last_of (charT, size_type = npos) const;

    size_type find_first_not_of (const basic_string<charT, traits, Allocator>&,
                                 size_type = 0) const;
    size_type find_first_not_of (const charT*, size_type ,
                                 size_type) const;
    size_type find_first_not_of (const charT*, size_type = 0) const;
    size_type find_first_not_of (charT, size_type = 0) const;

    size_type find_last_not_of (const basic_string<charT, traits, Allocator>&,
                                size_type = npos) const;
    size_type find_last_not_of (const charT*, size_type, size_type) const;
    size_type find_last_not_of (const charT*, size_type = npos) const;
    size_type find_last_not_of (charT, size_type = npos) const;

    basic_string<charT, traits, Allocator> substr (size_type = 0,
                                                   size_type = npos) const;

    int compare(const basic_string<charT, traits, Allocator>&,
                size_type = 0,
                size_type = npos) const;
    int compare (charT*, size_type, size_type) const;
    int compare (charT*, size_type = 0) const;

 protected:

    size_type getCapac () const { return pref()->getCapac(); }

    void clobber (size_type); // Remove old contents
    void cow ()               // Do copy on write as necessary
    {
#ifdef RWSTD_MULTI_THREAD
        RWSTDGuard guard(pref()->mutex_);
#endif
        if (pref()->references() > 1)
            unSafeClone();
    }
    void cow (size_type nc)     // Do copy on write w/ new capacity
    {
#ifdef RWSTD_MULTI_THREAD
        RWSTDGuard guard(pref()->mutex_);
#endif
        if (pref()->references() > 1 || getCapac() < nc)
            unSafeClone(nc);
    }

 private:

    typedef string_ref<charT,traits,Allocator> string_ref_type;

    static charT eos () { return traits::eos(); }

    //
    // Make a distinct copy of self
    //
    void clone ()
    {
#ifdef RWSTD_MULTI_THREAD
        RWSTDGuard guard(pref()->mutex_);
#endif
        unSafeClone();
    }
    void unSafeClone ();
    //
    // Make a distinct copy w/ new capacity nc
    //
    void clone (size_type nc)
    {
#ifdef RWSTD_MULTI_THREAD
        RWSTDGuard guard(pref()->mutex_);
#endif
        unSafeClone(nc);
    }
    void unSafeClone (size_type);

    string_ref_type *  pref () const
    {
        return (string_ref_type*) (((string_ref_type*) data_) - 1);
    }
    //
    // Null string ref
    //
#ifndef RWSTD_NO_STATIC_DEF3
    static const null_string_ref_rep<charT, traits, Allocator> nullref;
#endif

    static string_ref<charT, traits, Allocator> * getNullRep ()
#ifndef RWSTD_NO_STATIC_DEF3
    { return (string_ref<charT, traits, Allocator> *) &nullref; }
#else
    { return (string_ref<charT, traits, Allocator> *) &nullref[0]; }
#endif

    string_ref<charT, traits, Allocator> * getRep (size_type capac,
                                                   size_type nchar,
                                                   Allocator& alloc);
    charT*    data_;
    Allocator alloc_;
};

#ifndef RWSTD_NO_EXPLICIT_INSTANTIATION
template class RWSTDExportTemplate RWSTD_ALLOC_TYPE(char);

template class RWSTDExportTemplate string_ref<char,string_char_traits<char>, allocator<char> >;

template class RWSTDExportTemplate
 basic_string<char, string_char_traits<char>, RWSTD_ALLOC_TYPE(char) >;

#ifndef RWSTD_NO_WSTR
template class RWSTDExportTemplate
 basic_string<wchar_t, string_char_traits<wchar_t>, RWSTD_ALLOC_TYPE(wchar_t) >;
#endif
#endif

//
// Standard Type Definitions
//
typedef basic_string<char, string_char_traits<char>, RWSTD_ALLOC_TYPE(char) >
  string;

#ifndef RWSTD_NO_WSTR
typedef basic_string<wchar_t, string_char_traits<wchar_t>, RWSTD_ALLOC_TYPE(wchar_t) >
  wstring;
#endif

#ifndef RWSTD_NO_NAMESPACE
}
#endif

//
// The following has to go after the declaration of the string
// classes because of cross references.
//
#ifdef RW_STD_EXCEPT
#include <stdexcep>
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#if defined(RWSTD_NO_DESTROY_BUILTIN) || defined(RWSTD_NO_DESTROY_NONBUILTIN)
//
// Specializations for STL destroy
//
inline void destroy (string**)    {;}
inline void destroy (string***)   {;}
inline void destroy (string****)  {;}
#ifndef RWSTD_NO_WSTR
inline void destroy (wstring**)   {;}
inline void destroy (wstring***)  {;}
inline void destroy (wstring****) {;}
#endif
#endif

//
// Inline member functions for class string_ref
//

template <class charT, class traits, class Allocator >
inline void string_ref<charT, traits, Allocator>::unLink(Allocator& alloc)
{
    if (removeReference() == 0)
        alloc.deallocate((charT*)this);
}

template <class charT, class traits, class Allocator >
inline void string_ref<charT, traits, Allocator>::unSafeunLink(Allocator& alloc)
{
    if (unSafeRemoveReference() == 0)
        alloc.deallocate((charT*)this);
}

//
// Inline member functions for class basic_string
//

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>
  ::basic_string (const Allocator& alloc)
{
    data_ = getNullRep()->data();
    getNullRep()->addReference();
    alloc_ = alloc;
}

template <class charT, class traits, class Allocator >
inline
basic_string<charT, traits, Allocator>
  ::basic_string (const basic_string<charT, traits, Allocator> & s)
{
    data_ = s.data_;
    pref()->addReference();
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template <class charT, class traits, class Allocator>
template <class InputIterator>
basic_string<charT, traits, Allocator>::basic_string (InputIterator first,
                                                      InputIterator last,
                                                      const Allocator& alloc)
{
    data_ = getNullRep()->data();
    getNullRep()->addReference();
    alloc_ = alloc;
    while (first != last) append(1,*first++);
}
#else
template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::basic_string (const charT* first,
                                                      const charT* last,
                                                      const Allocator& alloc)
{
    data_ = getNullRep()->data();
    getNullRep()->addReference();
    alloc_ = alloc;
    while (first != last) append(1,*first++);
}
#endif

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::~basic_string ()
{
    pref()->unLink(alloc_);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::operator= (charT c)
{
    return *this = basic_string<charT, traits, Allocator>(1,c);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::operator+= (const basic_string<charT, traits, Allocator>& s)
{
    return append(s);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::operator+= (const charT* s)
{
    return append(s);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::operator+= (charT c)
{
    return append((size_type) 1, c);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::append (const charT* s, size_type n)
{
    return append(basic_string<charT,traits,Allocator>(s,n));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::append (const charT* s)
{
    return append(basic_string<charT,traits,Allocator>(s));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::append (size_type n, charT c)
{
    return append(basic_string<charT,traits,Allocator>(n,c));
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class charT, class traits, class Allocator>
template<class InputIterator>
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::append (InputIterator first,
                                                InputIterator last )
{
    return append(basic_string<charT, traits, Allocator>(first, last));
}
#else
template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::append (const charT* first,
                                                const charT* last)
{
    return append(basic_string<charT, traits, Allocator>(first, last));
}
#endif

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::assign (const charT* s, size_type n)
{
    return assign(basic_string<charT,traits,Allocator>(s,n));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::assign (const charT* s)
{
    return assign(basic_string<charT,traits,Allocator>(s));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::assign (size_type n, charT c)
{
    return assign(basic_string<charT,traits,Allocator>(n,c));
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class charT, class traits, class Allocator>
template<class InputIterator>
basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::assign (InputIterator first,
                                                InputIterator last)
{
    return assign(basic_string<charT, traits, Allocator>(first, last));
}
#else
template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::assign (const charT* first,
                                                const charT* last)
{
    return assign(basic_string<charT, traits, Allocator>(first, last));
}
#endif

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::insert (size_type pos,
                                                const charT* s,
                                                size_type n)
{
    return insert(pos, basic_string<charT,traits,Allocator>(s,n));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::insert (size_type pos, const charT* s)
{
    return insert(pos, basic_string<charT,traits,Allocator>(s));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::insert(size_type pos,
                                               size_type n,
                                               charT c)
{
    return insert(pos, basic_string<charT,traits,Allocator>(n,c));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::iterator
basic_string<charT, traits, Allocator>::insert (iterator p,
                                                size_type n,
                                                charT c)
{
    return replace_aux(p-begin(),0,basic_string<charT,traits,Allocator>(n,c));
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class charT, class traits, class Allocator>
template<class InputIterator>
inline void
basic_string<charT, traits, Allocator>::insert (iterator p,
                                                InputIterator first,
                                                InputIterator last)
{
    replace(p-begin(), 0, basic_string<charT, traits, Allocator>(first, last));
}
#else
template <class charT, class traits, class Allocator >
inline void
basic_string<charT, traits, Allocator>::insert (iterator p,
                                                const charT* first,
                                                const charT* last)
{
    replace(p-begin(), 0, basic_string<charT, traits, Allocator>(first, last));
}
#endif

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::remove (size_type pos, size_type n)
{
    RWSTD_THROW(pos > length(), out_of_range, rwse_StringIndexOutOfRange);
    return replace(pos,
                   min(n, length() - pos),
                   basic_string<charT, traits, Allocator>((size_type)0, (charT)0));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::remove (iterator it)
{
    return replace(it - begin(),
                   1,
                   basic_string<charT, traits, Allocator>((size_type)0, (charT)0));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::remove (iterator first, iterator last)
{
    return replace(first-begin(),
                   min(last - first, end() - first),
                   basic_string<charT, traits, Allocator>((size_type)0, (charT)0));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::replace (size_type pos1,
                                                 size_type n1,
                                                 const basic_string<charT, traits, Allocator> & str,
                                                 size_type pos2,
                                                 size_type n2)
{
    replace(pos1, n1, str.data(), str.length(), pos2, n2);
    return *this;
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::iterator
basic_string<charT, traits, Allocator>::replace_aux (size_type pos1,
                                                     size_type n1,
                                                     const basic_string<charT, traits, Allocator> & str,
                                                     size_type pos2,
                                                     size_type n2)
{
    return replace(pos1, n1, str.data(), str.length(), pos2, n2);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::replace (size_type pos,
                                                 size_type n1,
                                                 const charT* s,
                                                 size_type n2)
{
    replace(pos, n1, basic_string<charT,traits,Allocator>(s,n2));
    return *this;
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::replace (size_type pos,
                                                 size_type n1,
                                                 const charT* s)
{
    replace(pos, n1, basic_string<charT,traits,Allocator>(s));
    return *this;
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::replace (size_type pos,
                                                 size_type n,
                                                 size_type n2,
                                                 charT c)
{
    return replace(pos, n, basic_string<charT, traits, Allocator>(n2,c));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::replace (iterator first,
                                                 iterator last,
                                                 const basic_string<charT, traits, Allocator>& str)
{
    return replace(first - begin(), last - first, str);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::replace (iterator first,
                                                 iterator last,
                                                 const charT* s,
                                                 size_type n)
{
    return replace(first,last,basic_string<charT,traits,Allocator>(s,n));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::replace (iterator first,
                                                 iterator last,
                                                 const charT* s)
{
    return replace(first,last,basic_string<charT,traits,Allocator>(s));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::replace (iterator first,
                                                 iterator last,
                                                 size_type n,
                                                 charT c)
{
    return replace(first,last,basic_string<charT,traits,Allocator>(n,c));
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class charT, class traits, class Allocator>
template<class InputIterator>
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::replace (iterator first1,
                                                 iterator last1,
                                                 InputIterator first2,
                                                 InputIterator last2)
{
    return replace(first1,last1,
                   basic_string<charT,traits,Allocator>(first2,last2));
}
#else
template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>&
basic_string<charT, traits, Allocator>::replace (iterator first1,
                                                 iterator last1,
                                                 const charT* first2,
                                                 const charT* last2)
{
    return replace(first1,last1,
                   basic_string<charT,traits,Allocator>(first2,last2));
}
#endif

template <class charT, class traits, class Allocator >
inline charT basic_string<charT, traits, Allocator>::operator[] (size_type pos) const
{
    RWSTD_THROW(pos > size(), out_of_range, rwse_PosBeyondEndOfString);
    return pos == size() ? traits::eos() : data_[pos];
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::reference
basic_string<charT, traits, Allocator>::operator[] (size_type pos)
{
    RWSTD_THROW(pos >= size(), out_of_range, rwse_PosBeyondEndOfString);
    cow();
    return data_[pos];
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::const_reference
basic_string<charT, traits, Allocator>::at (size_type pos) const
{
    RWSTD_THROW(pos >= size(), out_of_range, rwse_PosBeyondEndOfString);
    return data_[pos];
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::reference
basic_string<charT, traits, Allocator>::at (size_type pos)
{
    RWSTD_THROW(pos >= size(), out_of_range, rwse_PosBeyondEndOfString);
    return data_[pos];
}

template <class charT, class traits, class Allocator >
inline const charT* basic_string<charT, traits, Allocator>::c_str () const
{
    return data_;
}

template <class charT, class traits, class Allocator >
inline const charT* basic_string<charT, traits, Allocator>::data () const
{
    return length() == 0 ? (charT*) 0 : data_;
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::length () const
{
    return pref()->nchars_;
}

template <class charT, class traits, class Allocator >
void
basic_string<charT, traits, Allocator>::resize (size_type n)
{
    resize(n, eos());
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::capacity () const
{
    return getCapac();
}

template <class charT, class traits, class Allocator >
inline void basic_string<charT, traits, Allocator>::reserve(size_type res_arg)
{
    if (res_arg > getCapac()) clone(res_arg);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>
basic_string<charT, traits, Allocator>::copy () const
{
    basic_string<charT, traits, Allocator> temp(*this); // Make referenced copy
    temp.clone();   // Make a distinct copy
    return temp;
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find (const charT* s,
                                              size_type pos,
                                              size_type n) const
{
    return find(basic_string<charT, traits, Allocator>(s, n), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find (const charT* s,
                                              size_type pos) const
{
    return find(basic_string<charT, traits, Allocator>(s), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find (charT c, size_type pos) const
{
    return find(basic_string<charT, traits, Allocator>(1, c), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::rfind (const charT* s,
                                               size_type pos,
                                               size_type n) const
{
    return rfind(basic_string<charT, traits, Allocator>(s,n), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::rfind (const charT* s, size_type pos)
const
{
    return rfind(basic_string<charT, traits, Allocator>(s), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::rfind (charT c, size_type pos) const
{
    return rfind(basic_string<charT, traits, Allocator>(1, c), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_of (const charT* s,
                                                       size_type pos,
                                                       size_type n) const
{
    return find_first_of(basic_string<charT, traits, Allocator>(s, n), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_of (const charT* s,
                                                       size_type pos) const
{
    return find_first_of(basic_string<charT, traits, Allocator>(s), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_of (charT c, size_type pos) const
{
    return find_first_of(basic_string<charT, traits, Allocator>(1, c), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_of (const charT* s,
                                                      size_type pos,
                                                      size_type n) const
{
    return find_last_of(basic_string<charT, traits, Allocator>(s,n), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_of (const charT* s,
                                                      size_type pos) const
{
    return find_last_of(basic_string<charT, traits, Allocator>(s), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_of (charT c, size_type pos)
const
{
    return find_last_of(basic_string<charT, traits, Allocator>(1, c), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_not_of (const charT* s,
                                                           size_type pos,
                                                           size_type n) const
{
    return find_first_not_of(basic_string<charT,traits,Allocator>(s, n), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_not_of (const charT* s,
                                                           size_type pos) const
{
    return find_first_not_of(basic_string<charT, traits, Allocator>(s), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_not_of (charT c,
                                                           size_type pos) const
{
    return find_first_not_of(basic_string<charT,traits,Allocator>(1, c), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_not_of(const charT* s,
                                                         size_type pos,
                                                         size_type n) const
{
    return find_last_not_of(basic_string<charT, traits, Allocator>(s,n), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_not_of (const charT* s,
                                                          size_type pos) const
{
    return find_last_not_of(basic_string<charT, traits, Allocator>(s), pos);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_not_of (charT c,
                                                          size_type pos) const
{
    return find_last_not_of(basic_string<charT, traits, Allocator>(1, c), pos);
}

template <class charT, class traits, class Allocator >
inline int
basic_string<charT, traits, Allocator>::compare (charT* s,
                                                 size_type pos,
                                                 size_type n) const
{
    return compare(basic_string<charT, traits, Allocator>(s,n), pos);
}

template <class charT, class traits, class Allocator >
inline int
basic_string<charT, traits, Allocator>::compare (charT* s, size_type pos) const
{
    return compare(basic_string<charT, traits, Allocator>(s), pos);
}

//
// Inlined non-member operators
//

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> operator+(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return basic_string<charT, traits, Allocator>(lhs).append(rhs);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> operator+(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return basic_string<charT, traits, Allocator>(lhs).append(rhs);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> operator+(
  charT lhs, const basic_string<charT, traits, Allocator>& rhs)
{
    return basic_string<charT, traits, Allocator>(1,lhs).append(rhs);
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> operator+(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
    return basic_string<charT,traits,Allocator>(lhs).append(basic_string<charT, traits, Allocator>(rhs));
}

template <class charT, class traits, class Allocator >
inline basic_string<charT, traits, Allocator> operator+(
  const basic_string<charT, traits, Allocator>& lhs,
  charT                                         rhs)
{
    return basic_string<charT,traits,Allocator>(lhs).append(basic_string<charT, traits, Allocator>(1,rhs));
}

template <class charT, class traits, class Allocator >
inline bool operator==(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return lhs.compare(rhs) == 0 ? true : false ;
}

template <class charT, class traits, class Allocator >
inline bool operator==(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
   return basic_string<charT,traits,Allocator>(lhs).compare(rhs)==0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator==(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
   return lhs.compare(basic_string<charT,traits,Allocator>(rhs))==0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator<(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return lhs.compare(rhs) < 0 ? true:false ;
}

template <class charT, class traits, class Allocator >
inline bool operator<(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return basic_string<charT,traits,Allocator>(lhs).compare(rhs)<0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator<(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
  return lhs.compare(basic_string<charT,traits,Allocator>(rhs))<0?true:false;
}

#ifndef RWSTD_NO_PART_SPEC_OVERLOAD
template <class charT, class traits, class Allocator >
inline bool operator!=(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return lhs.compare(rhs) != 0 ? true : false;
}
#endif

template <class charT, class traits, class Allocator >
inline bool operator!=(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
   return basic_string<charT,traits,Allocator>(lhs).compare(rhs)!=0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator!=(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
   return lhs.compare(basic_string<charT,traits,Allocator>(rhs))!=0?true:false;
}

#ifndef RWSTD_NO_PART_SPEC_OVERLOAD
template <class charT, class traits, class Allocator >
inline bool operator>(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return lhs.compare(rhs) > 0 ? true : false;
}
#endif

template <class charT, class traits, class Allocator >
inline bool operator>(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
   return basic_string<charT,traits,Allocator>(lhs).compare(rhs)>0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator>(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
   return lhs.compare(basic_string<charT,traits,Allocator>(rhs))>0?true:false;
}

#ifndef RWSTD_NO_PART_SPEC_OVERLOAD
template <class charT, class traits, class Allocator >
inline bool operator<=(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return lhs.compare(rhs) <= 0 ? true : false;
}
#endif

template <class charT, class traits, class Allocator >
inline bool operator<=(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
  return basic_string<charT,traits,Allocator>(lhs).compare(rhs)<=0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator<=(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
  return lhs.compare(basic_string<charT,traits,Allocator>(rhs))<=0?true:false;
}

#ifndef RWSTD_NO_PART_SPEC_OVERLOAD
template <class charT, class traits, class Allocator >
inline bool operator>=(
  const basic_string<charT, traits, Allocator>& lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
    return lhs.compare(rhs) >= 0 ? true:false;
}
#endif

template <class charT, class traits, class Allocator >
inline bool operator>=(
  const charT*                                  lhs,
  const basic_string<charT, traits, Allocator>& rhs)
{
   return basic_string<charT,traits,Allocator>(lhs).compare(rhs)>=0?true:false;
}

template <class charT, class traits, class Allocator >
inline bool operator>=(
  const basic_string<charT, traits, Allocator>& lhs,
  const charT*                                  rhs)
{
   return lhs.compare(basic_string<charT,traits,Allocator>(rhs))>=0?true:false;
}

#ifdef RW_STD_IOSTREAM

template<class charT, class traits, class IS_traits, class Allocator>
basic_istream<charT, IS_traits > &
operator >> (
  basic_istream<charT, IS_traits >& is,
  basic_string<charT, traits, Allocator >&  str);

template<class charT, class traits, class IS_traits, class Allocator>
basic_ostream<charT, IS_traits > &
operator << (
  basic_ostream<charT, IS_traits > &     os,
  const basic_string<charT, traits, Allocator >& str);

template<class charT, class IS_traits, class STR_traits, class STR_Alloc>
basic_istream<charT, IS_traits>&
getline(
  basic_istream<charT, IS_traits>&            is,
  basic_string<charT, STR_traits, STR_Alloc>& str,
  charT delim
#if 0
= IS_traits::newline()
#endif
);

#else

template<class charT, class traits, class Allocator>
istream & operator >> (
  istream & is, basic_string<charT, traits, Allocator > & str);

template<class charT, class traits, class Allocator>
ostream& operator << (
  ostream & os, const basic_string<charT, traits, Allocator > & str);

#ifdef RWSTD_NO_SPEC_OVERLOAD
ostream& RWSTDExport operator<< (ostream&, const string&);
#ifndef RWSTD_NO_WSTR
ostream& RWSTDExport operator <<(ostream&,wstring&);
#endif
#endif

template<class charT, class traits, class Allocator>
istream& getline(istream& is,
          basic_string<charT, traits,Allocator>& str, charT delim);

#endif
#ifndef RWSTD_NO_NAMESPACE
}
#endif

#ifdef RWSTD_COMPILE_INSTANTIATE
#include <string.cc>
#endif

#endif  /*defined __STD_STRING*/

#endif  /* __USING_STD_NAMES__ */
