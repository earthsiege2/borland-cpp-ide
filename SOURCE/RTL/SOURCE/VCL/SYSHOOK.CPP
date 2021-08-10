/*-----------------------------------------------------------------------*
 * filename - syshook.cpp
 *
 * function(s)
 *
 *   __CRTL_VCL_HookSystem
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <_defs.h>
#include "_io.h"
#include "delphimm.h"
#include "_hrdir.h"

typedef System::Pointer __fastcall (*GetMemPtr)(System::Integer);
typedef System::Integer __fastcall (*FreeMemPtr)(System::Pointer);
typedef System::Pointer __fastcall (*ReallocMemPtr)(System::Pointer, System::Integer);

extern "C" {

void _RTLENTRY __CRTL_VCL_HookSystem (void *gMem, void *fMem, void *rMem)
{
    if (!System::IsMemoryManagerSet())
    {
        System::TMemoryManager mngr;
        mngr.GetMem = (GetMemPtr)         gMem;
        mngr.FreeMem = (FreeMemPtr)       fMem;
        mngr.ReallocMem = (ReallocMemPtr) rMem;

        System::SetMemoryManager(mngr);
    }
}

} // "C"
