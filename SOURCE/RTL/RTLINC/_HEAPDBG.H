/*      _heapdbg.h

        Definitions for heap debugging.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

#ifndef __HEAPDBG_H
#define __HEAPDBG_H

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T
  #define _SIZE_T
  typedef unsigned size_t;
#endif

#ifdef _DEBUG

/* Malloc debugging level:
 * 0 = no checking.
 * 1 = check individual blocks as they are freed, malloc'd, etc (DEFAULT).
 * 2 = call _heapchk() on each call.
 */
extern int  _malloc_debug;

/* Error types passed to _error_hook.
 */
typedef enum
{
    _heap_overrun,            /* block overrun */
    _heap_underrun,           /* block underrun */
    _heap_corrupt,            /* heap corrupted */
    _heap_notallocated,       /* block not allocated */
    _heap_notfree,            /* block not free */
    _heap_sizemismatch,       /* block size fields do not match */
    _heap_freenull,           /* attempt to free a NULL pointer */
    _heap_badsize,            /* bad size field detected */
    _heap_badblock,           /* bad block pointer */
    _heap_free                /* block already free */
} _heaperr_t;

/* User hooks for debugging versions of memory allocation routines.
 */
extern void (*_malloc_hook) (void *__block, size_t __size);
extern void (*_free_hook)   (void *__block);
extern void (*_expand_hook) (void *__block, size_t __newsize);
extern void (*_move_hook)   (void *__block, size_t __newsize, void *__oldblock);
extern void (*_error_hook)  (void *__block, _heaperr_t __errtype);

/* Memory allocation routines that DO NOT call the user hooks.
 */
void        _RTLENTRY _EXPFUNC _free(void * __block);
void *      _RTLENTRY _EXPFUNC _malloc(size_t __size);
void *      _RTLENTRY _EXPFUNC _realloc(void * __block, size_t __size);

#else   /* !_DEBUG */

#define _free(b) free(b)
#define _malloc(b) malloc(b)
#define _realloc(b,s) realloc(b,s)

#endif  /* _DEBUG */

#ifdef __cplusplus
}
#endif

#endif  /* __HEAPDBG_H */
