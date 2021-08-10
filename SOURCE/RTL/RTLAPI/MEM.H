/*  mem.h

    Memory manipulation functions

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__MEM_H)
#define __MEM_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif


#ifndef _STDDEF
#define _STDDEF
#ifndef _PTRDIFF_T
#define _PTRDIFF_T
#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
   typedef long    ptrdiff_t;
#else
   typedef int ptrdiff_t;
#endif
#endif
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif
#endif


#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__FLAT__)

void _FAR * _RTLENTRY  _EXPFUNC memccpy(void _FAR *__dest, const void _FAR *__src,
                           int __c, size_t __n);
int         _RTLENTRY  _EXPFUNC memcmp(const void _FAR *__s1, const void _FAR *__s2,
                          size_t __n);
void _FAR * _RTLENTRY  _EXPFUNC memcpy(void _FAR *__dest, const void _FAR *__src,
                          size_t __n);
int         _RTLENTRY  _EXPFUNC memicmp(const void _FAR *__s1, const void _FAR *__s2,
                          size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC memmove(void _FAR *__dest, const void _FAR *__src,
                          size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC memset(void _FAR *__s, int __c, size_t __n);
void        _RTLENTRY  _EXPFUNC movedata(unsigned __srcseg, unsigned __srcoff,
                            unsigned __dstseg,unsigned __dstoff, size_t __n);
void        _RTLENTRY  _EXPFUNC movmem(const void _FAR *__src, void _FAR *__dest,
                          unsigned __length);
void        _RTLENTRY  _EXPFUNC setmem(void _FAR *__dest,unsigned __length, char __value);


#if !defined(__STDC__) /* NON_ANSI  */
void  far * _RTLENTRY _FARCALL _fmemccpy(void far *__dest, const void far *__src,
                       int __c, size_t __n);
void  far * _RTLENTRY _FARCALL _fmemchr(const void far *__s, int __c, size_t __n);
int         _RTLENTRY _FARCALL _fmemcmp(const void far *__s1, const void far *__s2,
                       size_t __n);
void  far * _RTLENTRY _FARCALL _fmemcpy(void far *__dest, const void far *__src,
                       size_t __n);
int         _RTLENTRY _FARCALL _fmemicmp(const void far *__s1, const void far *__s2,
                       size_t __n);
void  far * _RTLENTRY _FARCALL _fmemmove(void far *__dest, const void far *__src,
                       size_t __n);
void  far * _RTLENTRY _FARCALL _fmemset(void far *__s, int __c, size_t __n);
void        _RTLENTRY _FARCALL _fmovmem(const void far *__src, void far *__dest,
                       unsigned __length);
void        _RTLENTRY _FARCALL _fsetmem(void far *__dest, unsigned __length,
                       char __value);
#endif /* __STDC__  */


#else  /* defined __FLAT__ */


void * _RTLENTRY  _EXPFUNC memccpy(void * __dest, const void * __src,
                                  int __c, size_t __n);
int    _RTLENTRY  _EXPFUNC memcmp(const void * __s1, const void * __s2,
                                  size_t __n);
void * _RTLENTRY  _EXPFUNC memcpy(void * __dest, const void * __src,
                                  size_t __n);
int    _RTLENTRY  _EXPFUNC memicmp(const void * __s1, const void * __s2,
                                   size_t __n);
void * _RTLENTRYF _EXPFUNC memmove(void * __dest, const void * __src,
                                   size_t __n);
void * _RTLENTRYF _EXPFUNC memset(void * __s, int __c, size_t __n);

#define movmem(src,dest,length) (void)memmove(dest,src,length)
#define setmem(dest,length,value) (void)memset(dest,value,length)

#endif  /* __FLAT__ */

#ifdef __cplusplus
}
#endif

#if defined(__cplusplus)
extern "C++" {
      void _FAR * _RTLENTRY _EXPFUNC32 memchr(void _FAR *__s, int __c, size_t __n);
const void _FAR * _RTLENTRY _EXPFUNC32 memchr(const void _FAR *__s, int __c, size_t __n);
}
#else
      void _FAR * _RTLENTRY _EXPFUNC32 memchr(const void _FAR *__s, int __c, size_t __n);
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__STRING_H)
/* Intrinsic functions */

void _FAR * _RTLENTRY  _EXPFUNC16 __memchr__(const void _FAR * __s, int __c, size_t __n);
int         _RTLENTRY  _EXPFUNC16 __memcmp__(const void _FAR * __s1, const void _FAR * __s2, size_t __n);
void _FAR * _RTLENTRY  _EXPFUNC16 __memcpy__(void _FAR * __dest, const void _FAR * __src, size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC16 __memset__(void _FAR * __s, int __c, size_t __n);
#endif

#ifdef __cplusplus
}
#endif

#endif  /* __MEM_H */
