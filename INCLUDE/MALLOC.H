/*  malloc.h

    memory management functions and variables.

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __MALLOC_H
#define __MALLOC_H

#include <alloc.h>

#ifdef __cplusplus
extern "C" {
#endif


#if !defined(_Windows) || defined(__FLAT__)
/* _HEAPINFO structure returned by heapwalk */

#pragma option -a-

typedef struct _heapinfo
{
    int     *_pentry;
    size_t  _size;
    int     _useflag;
} _HEAPINFO;

#pragma option -a.

#endif  /* _Windows */


#if !defined(__FLAT__)

#if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)

/* Near heap functions currently allowed only in small data models */

#define _nmalloc(size)          malloc(size)
#define _nfree(block)           free(block)
#define _nrealloc(block,size)   realloc(block,size)
#define _ncalloc(num,size)      calloc(num,size)
#define _nheapmin()             0
#if !defined(_Windows)
#define _memavl()               coreleft()
#endif

#endif  /* small data models */

/* Model-independent functions */

#define _fmalloc(size)          farmalloc((unsigned long)(size))
#define _ffree(block)           farfree(block)
#define _frealloc(block,size)   farrealloc(block,(unsigned long)(size))
#define _fcalloc(num,size)      farcalloc((unsigned long)(num),(unsigned long)(size))
#define halloc(num,size)        (void huge *)_farmalloc((unsigned long)(num)*(size))
#define hfree(block)            farfree((void far *)(block))
#define _heapmin()              0
#define _fheapmin()             0

#if !defined(_Windows)
int         _RTLENTRY _EXPFUNC _heapwalk   (_HEAPINFO *__entry);
#endif

/* Prototypes */

void *      _Cdecl alloca     (size_t __size);
void *      _Cdecl __alloca__ (size_t __size);
#if defined(__BCOPT__ ) && !defined(_Windows)
#define     alloca  __alloca__
#endif
size_t      _Cdecl stackavail (void);

#else  /* __FLAT__ */

/* Prototypes */

void *      __cdecl   _EXPFUNC alloca( size_t __size );
void *      __cdecl            __alloca__ (size_t __size);

size_t      _RTLENTRY _EXPFUNC stackavail  (void);
int         _RTLENTRY _EXPFUNC _heapadd    (void * __block, size_t __size);
int         _RTLENTRY _EXPFUNC _heapchk    (void);
int         _RTLENTRY _EXPFUNC _heapmin    (void);
int         _RTLENTRY _EXPFUNC _heapset    (unsigned int __fill);
int         _RTLENTRY _EXPFUNC _heapwalk   (_HEAPINFO *__entry);
int         _RTLENTRY _EXPFUNC _rtl_heapwalk (_HEAPINFO *__entry);
void *      _RTLENTRY _EXPFUNC _expand     (void * __block, size_t __size);
size_t      _RTLENTRY _EXPFUNC _msize      (void * __block );


#endif  /* __FLAT__ */

#ifdef __cplusplus
}
#endif

/* Obsolete functions */
#if !defined(RC_INVOKED) && !defined(_Windows) && !defined(__FLAT__)
#pragma obsolete _heapwalk
#endif

#endif  /* __MALLOC_H */
