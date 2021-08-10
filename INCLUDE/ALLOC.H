/*  alloc.h

    memory management functions and variables.

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__ALLOC_H)
#define __ALLOC_H

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


#if !defined(__FLAT__)

#define _HEAPEMPTY      1
#define _HEAPOK         2
#define _FREEENTRY      3
#define _USEDENTRY      4
#define _HEAPEND        5
#define _HEAPCORRUPT    -1
#define _BADNODE        -2
#define _BADVALUE       -3

#ifndef _STDDEF
#define _STDDEF
#ifndef _PTRDIFF_T
#define _PTRDIFF_T
#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
  typedef long  ptrdiff_t;
#else
  typedef int ptrdiff_t;
#endif
#endif
#ifndef _SIZE_T
  #define _SIZE_T
  typedef unsigned size_t;
#endif
#endif

#if !defined(_Windows)

#if !defined(__STDC__)  /* NON_ANSI */
struct farheapinfo
  {
  void huge *ptr;
  unsigned long size;
  int in_use;
  };
#endif

#if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
struct heapinfo
  {
  void _FAR *ptr;
  unsigned int size;
  int in_use;
  };
#else
#define heapinfo farheapinfo
#endif

#endif  /* WINDOWS */

#ifdef __cplusplus
extern "C" {
#endif

void  _FAR *_RTLENTRY calloc(size_t __nitems, size_t __size);
void        _RTLENTRY free(void _FAR *__block);
void  _FAR *_RTLENTRY malloc(size_t __size);
void  _FAR *_RTLENTRY realloc(void _FAR *__block, size_t __size);

#if !defined(_Windows)
#if defined(__COMPACT__) || defined(__LARGE__) || defined(__HUGE__)
unsigned long _RTLENTRY coreleft (void);
#else
unsigned      _RTLENTRY coreleft(void);
#endif
#endif

#if defined(__DPMI16__) || !defined(_Windows)
int           _RTLENTRY heapcheck(void);
unsigned long _RTLENTRY farcoreleft(void);
#endif

#if defined(__DPMI16__)
#define farheapcheck heapcheck
#define coreleft     farcoreleft
#endif

#if !defined(_Windows)

int         _RTLENTRY brk(void *__addr);
void       *_RTLENTRY sbrk(int __incr);

int         _RTLENTRY heapfillfree(unsigned int __fillvalue);
int         _RTLENTRY heapcheckfree(unsigned int __fillvalue);

#if defined(__COMPACT__) || defined(__LARGE__) || defined(__HUGE__)

#if !defined(__STDC__)  /* NON_ANSI */
int         _RTLENTRY heapchecknode(void far *__node);
int         _RTLENTRY heapwalk(struct farheapinfo far *__hi);
#endif

#else

int         _RTLENTRY heapchecknode(void *__node);
int         _RTLENTRY heapwalk(struct heapinfo *__hi);

#endif

#if !defined(__STDC__)  /* NON_ANSI */
unsigned long _RTLENTRY farcoreleft(void);
int         _RTLENTRY farheapcheck(void);
int         _RTLENTRY farheapchecknode(void far *__node);
int         _RTLENTRY farheapfillfree(unsigned int __fillvalue);
int         _RTLENTRY farheapcheckfree(unsigned int __fillvalue);
int         _RTLENTRY farheapwalk(struct farheapinfo *__hi);
#endif

#endif  /* WINDOWS */

#if !defined(__STDC__)  /* NON_ANSI */
void far  * _RTLENTRY farcalloc(unsigned long __nunits, unsigned long __unitsz);
void        _RTLENTRY farfree(void far *__block);
void far  * _RTLENTRY farmalloc(unsigned long __nbytes);
void far  * _RTLENTRY farrealloc(void far *__oldblock, unsigned long __nbytes);
#endif

#ifdef __cplusplus
}
#endif


#else  /* defined __FLAT__ */


#ifndef _STDDEF
#  define _STDDEF
#  ifndef _PTRDIFF_T
#    define _PTRDIFF_T
     typedef int ptrdiff_t;
#  endif
#  ifndef _SIZE_T
#    define _SIZE_T
     typedef unsigned size_t;
#  endif
#endif

#if !defined(__STDC__)
struct heapinfo
{
  void *    ptr;
  unsigned  size;
  int       in_use;
};
#endif

#ifdef __cplusplus
extern "C" {
#endif

void *   _RTLENTRY _EXPFUNC calloc(size_t __nitems, size_t __size);
void     _RTLENTRY _EXPFUNC free(void * __block);
void *   _RTLENTRY _EXPFUNC malloc(size_t  __size);
void *   _RTLENTRY _EXPFUNC realloc(void * __block, size_t __size);
int      _RTLENTRY _EXPFUNC heapcheck(void);
int      _RTLENTRY _EXPFUNC heapfillfree(unsigned int __fillvalue);
int      _RTLENTRY _EXPFUNC heapcheckfree(unsigned int __fillvalue);
int      _RTLENTRY _EXPFUNC heapchecknode(void *__node);
int      _RTLENTRY _EXPFUNC heapwalk(struct heapinfo *__hi);

#if defined(__DPMI32__)
unsigned _RTLENTRY          coreleft(void);
#endif

#ifdef __cplusplus
}
#endif

/* Values returned by heap??? and _heap??? functions */

#define _HEAPEMPTY      1
#define _HEAPOK         2
#define _FREEENTRY      3
#define _USEDENTRY      4
#define _HEAPEND        5
#define _HEAPCORRUPT    -1
#define _BADNODE        -2
#define _BADVALUE       -3
#define _HEAPBADBEGIN   -4
#define _HEAPBADNODE    -5
#define _HEAPBADPTR     -6

#if !defined(__STDC__)
#define farcalloc   calloc
#define farcoreleft coreleft
#define farfree     free
#define farmalloc   malloc
#define farrealloc  realloc
#endif

#endif  /* __FLAT__ */


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __ALLOC_H */


