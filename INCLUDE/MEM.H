/*  mem.h

    Memory manipulation functions

*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
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


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifdef __cplusplus
extern "C" {
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


#if !defined(__FLAT__) || defined(__DPMI32__)
void        _RTLENTRY  _EXPFUNC movedata(unsigned __srcseg, unsigned __srcoff,
                                         unsigned __dstseg, unsigned __dstoff, size_t __n);
#endif


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


#if defined(__cplusplus)
extern "C++"
{
          void _FAR * _RTLENTRY _EXPFUNC32 memchr(void _FAR *__s, int __c, size_t __n);
    const void _FAR * _RTLENTRY _EXPFUNC32 memchr(const void _FAR *__s, int __c, size_t __n);
}
#else
          void _FAR * _RTLENTRY _EXPFUNC32 memchr(const void _FAR *__s, int __c, size_t __n);
#endif


#if !defined(__STRING_H)
/* Intrinsic functions */

void _FAR * _RTLENTRY  _EXPFUNC16 __memchr__(const void _FAR * __s, int __c, size_t __n);
int         _RTLENTRY  _EXPFUNC16 __memcmp__(const void _FAR * __s1, const void _FAR * __s2, size_t __n);
void _FAR * _RTLENTRY  _EXPFUNC16 __memcpy__(void _FAR * __dest, const void _FAR * __src, size_t __n);
void _FAR * _RTLENTRYF _EXPFUNC16 __memset__(void _FAR * __s, int __c, size_t __n);
#endif


#if !defined(__FLAT__)

void        _RTLENTRY  _EXPFUNC movmem(const void _FAR *__src, void _FAR *__dest,
                                       unsigned __length);
void        _RTLENTRY  _EXPFUNC setmem(void _FAR *__dest,unsigned __length, char __value);


#if !defined(__STDC__) /* NON_ANSI  */
void  __far * _RTLENTRY _FARCALL _fmemccpy(void __far *__dest, const void __far *__src,
                                           int __c, size_t __n);
void  __far * _RTLENTRY _FARCALL _fmemchr(const void __far *__s, int __c, size_t __n);
int           _RTLENTRY _FARCALL _fmemcmp(const void __far *__s1, const void __far *__s2,
                                          size_t __n);
void  __far * _RTLENTRY _FARCALL _fmemcpy(void __far *__dest, const void __far *__src,
                                          size_t __n);
int           _RTLENTRY _FARCALL _fmemicmp(const void __far *__s1, const void __far *__s2,
                                           size_t __n);
void  __far * _RTLENTRY _FARCALL _fmemmove(void __far *__dest, const void __far *__src,
                                           size_t __n);
void  __far * _RTLENTRY _FARCALL _fmemset(void __far *__s, int __c, size_t __n);
void          _RTLENTRY _FARCALL _fmovmem(const void __far *__src, void __far *__dest,
                                          unsigned __length);
void          _RTLENTRY _FARCALL _fsetmem(void __far *__dest, unsigned __length,
                                          char __value);
#endif /* __STDC__  */


#else  /* defined __FLAT__ */


#define movmem(src,dest,length) (void)memmove(dest,src,length)
#define setmem(dest,length,value) (void)memset(dest,value,length)


#if !defined(__STDC__) /* NON_ANSI  */
#define _fmemccpy memccpy
#define _fmemchr  memchr
#define _fmemcmp  memcmp
#define _fmemcpy  memcpy
#define _fmemicmp memicmp
#define _fmemmove memmove
#define _fmemset  memset
#define _fmovmem  movmem
#define _fsetmem  setmem
#endif /* __STDC__  */


#endif  /* __FLAT__ */


#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __MEM_H */
