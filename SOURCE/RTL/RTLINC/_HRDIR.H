/*-----------------------------------------------------------------------*
 * filename - _hrdir.h
 *
 *   Data types and prototypes for the heap redirector routines.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.7.2.1 $        */

#ifndef ___HRDIR_H
#define ___HRDIR_H

#include <stddef.h>

#pragma option push -b -a8

#ifdef __cplusplus
extern "C" {
#endif


typedef void   (_RTLENTRY *_hr_pfn_free)      (void *);
typedef void * (_RTLENTRY *_hr_pfn_malloc)    (size_t);
typedef void * (_RTLENTRY *_hr_pfn_realloc)   (void *, size_t);
typedef void   (_RTLENTRY *_hr_pfn_terminate) (void);

typedef void   (__fastcall *_hr_pfn_bormm_free)    (void *);
typedef void * (__fastcall *_hr_pfn_bormm_malloc)  (size_t);
typedef void * (__fastcall *_hr_pfn_bormm_realloc) (void *, size_t);

typedef int    (__fastcall *_hr_pfn_bormm_addref)  (void);
typedef int    (__fastcall *_hr_pfn_bormm_release) (void);


typedef enum              /* redirector state flags */
{
    _hrf_virgin       ,   /* redirector hasn't been initialized yet */
    _hrf_internal     ,   /* Using the internal allocator */
    _hrf_borlndmm     ,   /* Found a valid bormm, using it */
    _hrf_old_borlndmm ,   /* Found old incompatible borlndmm */
    _hrf_vcl_system   ,   /* Using static VCL.LIB system */
    _hrf_dballoc      ,   /* The debug allocator (not implemented yet) */
    _hrf_other        ,   /* Using some other unknown allocator */
}   _hrf_enum;

typedef struct
{
   size_t            size;      /* must be set to the size of this struct */

   unsigned int      allocated; /* defaults to 0, and is set to 1 after the
                                   first memory allocation occurs. */

   _hrf_enum         flags;     /* holds various state flags */

   _hr_pfn_free      free;

   _hr_pfn_malloc    malloc;

   _hr_pfn_realloc   realloc;

   _hr_pfn_terminate terminate; /* pfn that cleans up the heap */

   /* Additional members can be added to the end */

} _heap_redirector_t;

extern _heap_redirector_t _heap_redirector;

int _RTLENTRY _EXPFUNC __CRTL_MEM_GetBorMemPtrs (void **gMem, void **fMem, void **rMem);
#ifdef __CRTL_MEM_FORCE_NAKED
  void _RTLENTRY _EXPFUNC __declspec(naked) __CRTL_MEM_UseBorMM (void);
#else
  void _RTLENTRY _EXPFUNC __CRTL_MEM_UseBorMM (void);
#endif
_heap_redirector_t * _RTLENTRY _EXPFUNC _get_heap_redirector_info (void);

void _RTLENTRY __CRTL_VCL_HookSystem (void *gMem, void *fMem, void *rMem);

int  _RTLENTRY __CRTL_MEM_CheckBorMem (void);
void _RTLENTRY __CRTL_MEM_Revector (int allocated);


extern _hr_pfn_bormm_free     _bormm_pfn_FreeMem;
extern _hr_pfn_bormm_malloc   _bormm_pfn_GetMem;
extern _hr_pfn_bormm_realloc  _bormm_pfn_ReallocMem;
extern _hr_pfn_bormm_addref   _bormm_pfn_HeapAddRef;
extern _hr_pfn_bormm_release  _bormm_pfn_HeapRelease;


void   _RTLENTRY _bormm_stub_FreeMem (void *block);
void * _RTLENTRY _bormm_stub_GetMem (size_t size);
void * _RTLENTRY _bormm_stub_ReallocMem (void *block, size_t size);
void   _RTLENTRY _bormm_stub_Terminate (void);


#ifdef __cplusplus
} // extern "C"
#endif

#pragma option pop

#endif /* ___HRDIR_H */