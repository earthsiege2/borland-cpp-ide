/*------------------------------------------------------------------------
 * filename - _malloc.h
 *
 *   Internal memory management functions and definitions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifdef _DEBUG
#include <_heapdbg.h>
#endif

#ifdef __OS2__
#ifndef OS2DEF_INCLUDED
typedef unsigned long ULONG;
#endif
#endif

#ifdef __WIN32__
#ifndef BASETYPE_ULONG
typedef unsigned long ULONG;
#endif
#endif

#ifndef _STDDEF
#define _STDDEF
#ifndef _PTRDIFF_T
#define _PTRDIFF_T
typedef int ptrdiff_t;
#endif
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif
#endif

typedef char * PBLOCK;      /* pointer to a heap block */

#ifdef __cplusplus
extern "C" {
#endif

void * __cdecl _alloca       (size_t __size);
int           _getmem       (size_t __size);
size_t        _stackavail   (void);
int           _virt_commit  (void *__base, unsigned long __size);
int           _virt_decommit(void *__base, unsigned long __size);
int           _virt_release (void *__base);
int           _virt_reserve (unsigned long __size, void **__ptr,
                             unsigned long *__actual);

#ifdef _MT
void        _lock_heap  (void);
void        _unlock_heap(void);
#else
#define     _lock_heap()
#define     _unlock_heap()
#endif

#ifdef __OS2__
int         _same_seg       (PBLOCK __p, size_t __size);
#else
#define     _same_seg(p,size) (1)    /* on non-OS/2, no tiling needed */
#endif

#ifdef _DEBUG
int         _is_allocated   (PBLOCK p);
int         _is_free        (PBLOCK p);
void        _heap_error     (PBLOCK __ptr, _heaperr_t __type);
void        _unlink_alloc   (PBLOCK p);
#endif

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------
 * Macros for accessing hidden fields in a heap block:
 *
 * PSIZE    size of previous physical block
 * SIZE     size of this block (bit 0 is 1 if block is allocated)
 * PREV     pointer to previous block on free list
 * NEXT     pointer to next block on free list
 *
 * If _DEBUG is defined, the following fields are used
 * to store sentinel values for detecting overrun/underrun:
 *
 * PAFTER   space reserved for overrun sentinel of previous block; the
 *          overrun sentinel may actually fall below this location,
 *          depending on the granularity and block size.
 * USIZE    user's idea of the size of this block
 * BEFORE   underrun sentinel for this block
 * ALINK    pointer to next block on allocated block list
 * AFTER    overrun sentinel for this block (only valid if USIZE is set)
 */
#ifdef _DEBUG
#  define PAFTER(b)   (size_t)(*(ULONG *)((b)-24))
#  define PSIZE(b)    (size_t)(*(ULONG *)((b)-20))
#  define SIZE(b)     (size_t)(*(ULONG *)((b)-16))
#  define USIZE(b)    (size_t)(*(ULONG *)((b)-12))
#  define ALINK(b)    (*(PBLOCK *)((b)-8))
#  define BEFORE(b)   (size_t)(*(ULONG *)((b)-4))
#  define AFTER(b)    (size_t)(*(ULONG *)((b)+USIZE(b)))

#  define ALLOC_SENTINEL   0xabababab
#  define FREE_SENTINEL    0xfbfbfbfb

#  define OVERHEAD    24          /* no. of bytes used by boundary tags */
#  define MINBLOCK    32          /* minimum block size */
#else
#  define PSIZE(b)    (size_t)(*(ULONG *)((b)-8))
#  define SIZE(b)     (size_t)(*(ULONG *)((b)-4))

#  define OVERHEAD    8           /* no. of bytes used by boundary tags */
#  define MINBLOCK    16          /* minimum block size */
#endif

#define PREV(b)     (*(PBLOCK *)(b))
#define NEXT(b)     (*(PBLOCK *)((b)+4))


/*----------------------------------------------------------------------
 * Macros for rounding 'n' up or down to the next multiple of 's',
 * which must be a power of 2.
 */
#define ROUND_UP(n,s) (((ULONG)(n)+(s)-1)&~((s)-1))
#define ROUND_DOWN(n,s) ((ULONG)(n)&~((s)-1))

/*----------------------------------------------------------------------
 * Sizes of various boundaries
 */
#define WORD_SIZE   4           /* block pointer boundary */
#define PAGE_SIZE   0x1000      /* size of one page */
#define SEG_SIZE    0x10000     /* segment tile boundary */
#define HEAP_SIZE   0x400000    /* heap virtual address space size */
                                /*  (must be multiple of SEG_SIZE) */
#define SHEAP_SIZE  0x100000    /* small heap size for DOS systems */

/*----------------------------------------------------------------------
 * heap_rec - a list of all non-contiguous heap areas
 *
 * Each record in this array contains information about a non-contiguous
 * heap area.  In most programs there should be only one such area.
 */

#define MAXHEAPS 64
struct _heap_rec
{
    PBLOCK  base;           /* base of heap area */
    ULONG   len;            /* size of heap area */
};

extern struct _heap_rec _heaps[MAXHEAPS];  /* list of all non-contiguous heap areas */
extern int    _nheaps;                     /* no. of heaps in _heaps */

