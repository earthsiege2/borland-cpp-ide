/*------------------------------------------------------------------------*/
/*                                                                        */
/*  HEAPSEL.CPP                                                           */
/*                                                                        */
/*  Copyright Borland International 1993                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

//  THeapSelector doesn't have to do anything special under WIN32. It's
//  only under Windows that we have to worry about multiple heaps.

#if !defined( __FLAT__ )

#if !defined( _Windows )
#define _Windows
#endif

#if !defined( __WINDOWS_H )
#include <windows.h>
#endif	// __WINDOWS_H

#if !defined( __DOS_H )
#include <dos.h>
#endif	// __DOS_H

#if !defined( __CLASSLIB_HEAPSEL_H )
#include "classlib\heapsel.h"
#endif	// __CLASSLIB_HEAPSEL_H

void _BIDSFARDATA *THeapSelector::Allocate( size_t sz ) const
{
    HeapSetup frame(FP_SEG(this));
    return MK_FP( _DS, LocalAlloc( sz, LMEM_MOVEABLE ) );
}

void THeapSelector::Free( void _BIDSFARDATA *block )
{
    HeapSetup frame(FP_SEG(block));
    HANDLE hMem = LocalHandle( FP_OFF(block) );
    if( hMem )
        LocalFree( hMem );
}

#endif  // __FLAT__
