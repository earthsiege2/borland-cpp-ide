/*  string.h

    Definitions for memory and string functions.

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __STRING_H
#define __STRING_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef __OS2__

#ifndef __STDC__

#if !defined(__LOCALE_H)
#include <locale.h>
#endif

#endif  /* !__STDC__ */

#endif  /* __OS2__ */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#if !defined(__FLAT__)

#ifdef __cplusplus
extern "C" {
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
int         _RTLENTRYF  strcoll(const char _FAR *__s1, const char _FAR *__s2);
int         _RTLENTRYF _EXPFUNC _lstrcoll(const char _FAR *__s1, const char _FAR *__s2);
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
size_t      _RTLENTRYF strxfrm(char _FAR *__s1, const char _FAR *__s2,
                        size_t __n );
size_t      _RTLENTRYF _EXPFUNC _lstrxfrm(char _FAR *__s1, const char _FAR *__s2,
                        size_t __n );
char _FAR * _RTLENTRY  _EXPFUNC _strerror(const char _FAR *__s);


#if !__STDC__
/* compatibility with other compilers */
#define strcmpi(s1,s2)      stricmp(s1,s2)
#define strncmpi(s1,s2,n)   strnicmp(s1,s2,n)

void _FAR * _RTLENTRY  _EXPFUNC memccpy(void _FAR *__dest, const void _FAR *__src,
                        int __c, size_t __n);
int         _RTLENTRY  _EXPFUNC memicmp(const void _FAR *__s1, const void _FAR *__s2,
                           size_t __n);
void        _RTLENTRY  _EXPFUNC movedata(unsigned __srcseg,unsigned __srcoff,
                            unsigned __dstseg,unsigned __dstoff, size_t __n);
char _FAR * _RTLENTRYF stpcpy(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _stpcpy(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC strdup(const char _FAR *__s);
int         _RTLENTRYF _EXPFUNC stricmp(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC strlwr(char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC _lstrlwr(char _FAR *__s);
int         _RTLENTRYF _EXPFUNC strnicmp(const char _FAR *__s1, const char _FAR *__s2,
                        size_t __maxlen);
char _FAR * _RTLENTRY  _EXPFUNC strnset(char _FAR *__s, int __ch, size_t __n);
char _FAR * _RTLENTRY  _EXPFUNC strrev(char _FAR *__s);
char _FAR * _RTLENTRY  _EXPFUNC strset(char _FAR *__s, int __ch);
char _FAR * _RTLENTRYF _EXPFUNC strupr(char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC _lstrupr(char _FAR *__s);

void  far * _RTLENTRY _FARCALL _fmemccpy(void far *__dest, const void far *__src,
                        int c, size_t __n);
void  far * _RTLENTRY _FARCALL _fmemchr(const void far *__s, int c, size_t __n);
int         _RTLENTRY _FARCALL _fmemcmp(const void far *__s1, const void far *__s2,
                        size_t __n);
void  far * _RTLENTRY _FARCALL _fmemcpy(void far *__dest, const void far *__src,
                        size_t __n);
int         _RTLENTRY _FARCALL _fmemicmp(const void far *__s1, const void far *__s2,
                        size_t __n);
void  far * _RTLENTRY _FARCALL _fmemmove(void far *__dest, const void far *__src,
                        size_t __n);
void  far * _RTLENTRY _FARCALL _fmemset(void far *__s, int c, size_t __n);
void        _RTLENTRY _FARCALL _fmovmem(const void far *__src, void far *__dest,
                        unsigned __length);
void        _RTLENTRY _FARCALL _fsetmem(void far *__dest,unsigned __length,
                        char __value);

char  far * _RTLENTRY _FARCALL _fstrcat(char far *__dest, const char far *__src);
char  far * _RTLENTRY _FARCALL _fstrchr(const char far *__s, int c);
int         _RTLENTRY _FARCALL _fstrcmp(const char far *__s1, const char far *__s2);
char  far * _RTLENTRY _FARCALL _fstrcpy(char far *__dest, const char far *__src);
size_t      _RTLENTRY _FARCALL _fstrcspn(const char far *__s1, const char far *__s2);
char  far * _RTLENTRY _FARCALL _fstrdup(const char far *__s);
int         _RTLENTRY _FARCALL _fstricmp(const char far *__s1, const char far *__s2);
size_t      _RTLENTRY _FARCALL _fstrlen(const char far *__s);
char  far * _RTLENTRY _FARCALL _fstrlwr(char far *__s);
char  far * _RTLENTRY _FARCALL _fstrncat(char far *__dest, const char far *__src,
             size_t maxlen);
int         _RTLENTRY _FARCALL _fstrncmp(const char far *__s1, const char far *__s2,
             size_t maxlen);
char  far * _RTLENTRY _FARCALL _fstrncpy(char far *__dest, const char far *__src,
             size_t maxlen);
int         _RTLENTRY _FARCALL _fstrnicmp(const char far *__s1, const char far *__s2,
              size_t maxlen);
char  far * _RTLENTRY _FARCALL _fstrnset(char far *__s, int ch, size_t __n);
char  far * _RTLENTRY _FARCALL _fstrpbrk(const char far *__s1, const char far *__s2);
char  far * _RTLENTRY _FARCALL _fstrrchr(const char far *__s, int c);
char  far * _RTLENTRY _FARCALL _fstrrev(char far *__s);
char  far * _RTLENTRY _FARCALL _fstrset(char far *__s, int ch);
size_t      _RTLENTRY _FARCALL _fstrspn(const char far *__s1, const char far *__s2);
char  far * _RTLENTRY _FARCALL _fstrstr(const char far *__s1, const char far *__s2);
char  far * _RTLENTRY _FARCALL _fstrtok(char far *__s1, const char far *__s2);
char  far * _RTLENTRY _FARCALL _fstrupr(char far *__s);


#ifdef __MSC
#define _stricmp(s1,s2) stricmp(s1,s2)
#define _strdup(s1)     strdup(s1)
#define _strupr(s1)     strupr(s1)
#define _strlwr(s1)     strlwr(s1)
#define _strrev(s1)     strrev(s1)
#endif

#endif  /* ! __STDC__ */

#ifdef __cplusplus
}
#endif

#if defined( __USELOCALES__ )

#define  strupr   _lstrupr
#define  strlwr   _lstrlwr
#define  _fstrupr _lstrupr
#define  _fstrlwr _lstrlwr
#define  strcoll  _lstrcoll
#define  strxfrm  _lstrxfrm

#endif

#else    /* defined __FLAT__ */

#ifdef __cplusplus
extern "C" {
#endif
int    _RTLENTRY  _EXPFUNC memcmp(const void * __s1,
                                  const void * __s2, size_t __n);
void * _RTLENTRY  _EXPFUNC memcpy(void * __dest, const void * __src,
                                  size_t __n);
void * _RTLENTRYF _EXPFUNC memmove(void * __dest, const void * __src,
                                   size_t __n);
void * _RTLENTRYF _EXPFUNC memset(void * __s, int __c, size_t __n);
char * _RTLENTRYF _EXPFUNC strcat(char * __dest, const char * __src);
int    _RTLENTRYF _EXPFUNC strcmp(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC strcoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _lstrcoll(const char * __s1, const char * __s2);
char * _RTLENTRYF _EXPFUNC strcpy(char * __dest, const char * __src);
size_t _RTLENTRY  _EXPFUNC strcspn(const char * __s1, const char * __s2);
char * _RTLENTRY  _EXPFUNC strerror(int __errnum);
size_t _RTLENTRYF _EXPFUNC strlen(const char * __s);
char * _RTLENTRYF _EXPFUNC strncat(char * __dest, const char * __src,
                                   size_t __maxlen);
int    _RTLENTRYF _EXPFUNC strncmp(const char * __s1, const char * __s2,
                                   size_t __maxlen);
char * _RTLENTRYF _EXPFUNC strncpy(char * __dest, const char * __src,
                                   size_t __maxlen);
size_t _RTLENTRY  _EXPFUNC strspn(const char * __s1, const char * __s2);
char * _RTLENTRYF _EXPFUNC strtok(char * __s1, const char * __s2);
size_t _RTLENTRY  _EXPFUNC strxfrm(char * __s1, const char * __s2,
                                   size_t __n );
size_t _RTLENTRY  _EXPFUNC _lstrxfrm(char * __s1, const char * __s2,
                                   size_t __n );
char * _RTLENTRY  _EXPFUNC _strerror(const char * __s);


#if !__STDC__
/* compatibility with other compilers */
#define strcmpi(s1,s2)      stricmp(s1,s2)
#define strncmpi(s1,s2,n)   strnicmp(s1,s2,n)

void * _RTLENTRY _EXPFUNC memccpy(void * __dest, const void * __src,
                                  int __c, size_t __n);
int    _RTLENTRY _EXPFUNC memicmp(const void * __s1, const void * __s2,
                                  size_t __n);
char * _RTLENTRYF _EXPFUNC stpcpy(char * __dest, const char * __src);
char * _RTLENTRY  _EXPFUNC _stpcpy(char * __dest, const char * __src);
char * _RTLENTRY  _EXPFUNC strdup(const char * __s);
int    _RTLENTRYF _EXPFUNC stricmp(const char * __s1, const char * __s2);
char * _RTLENTRYF _EXPFUNC strlwr(char * __s);
char * _RTLENTRYF _EXPFUNC _lstrlwr(char * __s);
int    _RTLENTRYF _EXPFUNC strnicmp(const char * __s1, const char * __s2,
                                    size_t __maxlen);
char * _RTLENTRY  _EXPFUNC strnset(char * __s, int __ch, size_t __n);
char * _RTLENTRY  _EXPFUNC strrev(char * __s);
char * _RTLENTRY  _EXPFUNC strset(char * __s, int __ch);
char * _RTLENTRYF _EXPFUNC strupr(char * __s);
char * _RTLENTRYF _EXPFUNC _lstrupr(char * __s);

#endif  /* ! __STDC__ */

#ifdef __cplusplus
}
#endif

#if defined( __USELOCALES__ )

#define  strupr   _lstrupr
#define  strlwr   _lstrlwr
#define  _fstrupr _lstrupr
#define  _fstrlwr _lstrlwr
#define  strcoll  _lstrcoll
#define  strxfrm  _lstrxfrm

#endif

#endif  /* __FLAT__ */

#if defined(__cplusplus)
extern "C++" {
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

#ifdef __cplusplus
extern "C" {
#endif

/* Intrinsic functions */

#if !defined(__MEM_H)
void _FAR * _RTLENTRY  _EXPFUNC16 __memchr__  (const void _FAR *__s, int __c, size_t __n);
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

#ifdef __cplusplus
}
#endif

#endif  /* __STRING_H */
