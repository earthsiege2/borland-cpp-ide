//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Module used to explicit expand/export templates used by ObjectWindows
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(CLASSLIB_LISTIMP_H)
# include <classlib/listimp.h>
#endif
#if !defined(CLASSLIB_STACKS_H)
# include <classlib/stacks.h>
#endif
#if !defined(CLASSLIB_ALLOCTR_H)
# include <classlib/alloctr.h>
#endif
#if !defined(CLASSLIB_MEMMGR_H)
# include <classlib/memmgr.h>
#endif

OWL_DIAGINFO;

#if defined(BI_IMPEXP_TEMPLATES)
# if defined(_BUILDOWLDLL)

//
// The template instances only need to be generated when building the 
// ObjectWindows DLL - These instances are exported by OWL and imported 
// by user code.
//
template class _OWLCLASS  TMListElement<TVoidPointer, TStandardAllocator>;
template class _OWLCLASS  TMListBlockInitializer<TVoidPointer, TStandardAllocator>;
template class _OWLCLASS  TMListImp<TVoidPointer, TStandardAllocator>;

# endif
#endif
