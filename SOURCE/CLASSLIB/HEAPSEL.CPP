//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <services/defs.h>

//
// THeapSelector doesn't have to do anything special unless its under Win16.
// Then we have to worry about multiple heaps.
//
#if defined(BI_PLAT_WIN16)

#include <classlib/heapsel.h>
#include <services/wsysinc.h>

void _BIDSFARDATA *THeapSelector::Allocate( size_t sz ) const
{
    HeapSetup frame(FP_SEG(this));
    return MK_FP( _DS, ::LocalAlloc( sz, LMEM_MOVEABLE ) );
}

void THeapSelector::Free( void _BIDSFARDATA *block )
{
    HeapSetup frame(FP_SEG(block));
    HANDLE hMem = ::LocalHandle( (void NEAR*)FP_OFF(block) );
    if( hMem )
        ::LocalFree( hMem );
}

#endif
