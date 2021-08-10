/*  string.h

    Definitions for memory and string functions.

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __STRING_H
#define __STRING_H

#if !defined(___DEFS_H)
#include <_defs.h>
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


#if !__STDC__
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


#if defined(__MSC)
#define _stricmp(s1,s2) stricmp(s1,s2)
#define _strdup(s1)     strdup(s1)
#define _strupr(s1)     strupr(s1)
#define _strlwr(s1)     strlwr(s1)
#define _strrev(s1)     strrev(s1)
#endif  /* __MSC */


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

#if !__STDC__
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
size_t _RTLENTRY  _EXPFUNC _lstrxfrm(char * __s1, const char * __s2,
                                     size_t __n );
int    _RTLENTRY  _EXPFUNC strcoll(const char * __s1, const char * __s2);
size_t _RTLENTRY  _EXPFUNC strxfrm(char * __s1, const char * __s2,
                                   size_t __n );


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
#define  strupr   _lstrupr
#define  strlwr   _lstrlwr
#define  strcoll  _lstrcoll
#define  strxfrm  _lstrxfrm
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
