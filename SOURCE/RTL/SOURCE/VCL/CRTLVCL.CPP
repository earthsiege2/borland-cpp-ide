/*-----------------------------------------------------------------------*
 * filename - crtlvcl.cpp
 *
 * function(s)
 *
 *   __CRTL_VCL_Init
 *   __CRTL_VCL_Exit
 *
 *
 *   Both functions are called from the startup code.  Init happens
 *   very early and Exit happens very late.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1997, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.19.2.1 $        */

#include <windows.h>
#include <_defs.h>
#include "delphimm.h"

namespace System {
    extern __declspec(package) HINSTANCE MainInstance;
    extern __declspec(package) bool      IsMultiThread;
};

extern "C"
{

void _RTLENTRY __CRTL_VCL_Sharemem (void);
extern unsigned char __isDLL;
extern unsigned char __isVCLPackage;

void _RTLENTRY __CRTL_VCL_Init (void)
{
    unsigned int hinst = _EDX;

    // We must set the VCL copy of hInstance (called MainInstance).
    // The startup code has placed this value into the EDX register for us.

    // Always set MainInstance in an EXE, and only set it in a DLL if it
    // hasn't been set.  Also, never set it in a PACKAGE.

    if (!__isVCLPackage)
        if ((!__isDLL) || (__isDLL && !System::MainInstance))
          System::MainInstance = (HINSTANCE) hinst;

    // We must tell the Pascal RTL to enforce multithread issues in its
    // memory allocation routines, since we are in the multi-threaded RTL
    // on the C/C++ side.

    System::IsMultiThread = true;

    // Now initialize the Pascal RTL

    System::initialization();

#if defined(_BUILDRTLDLL)
    __CRTL_VCL_Sharemem();
#endif
}

void _RTLENTRY __CRTL_VCL_Exit (void)
{
// This cannot be preformed now, since it prematurely unloads the memory
// manager DLL.  If the RTLDLL is being used, the RTL cannot free its memory
// without jumping into the non-existant memory manager DLL.  Therefore SYSTEM
// is initialized but never finalized.

//  #if defined(_BUILDRTLDLL)
//    System::Finalization();
//  #endif
}

//
// These functions start up and shut down VCL at the appropriate times.
//

void __stdcall __InitVCL(void);
void __stdcall __ExitVCL(void);

#pragma startup __InitVCL 28     // Initialization of early VCL routines.
                                 // Priority 28 is two eariler than what DCC32
                                 // uses for .PAS Units' Initialization
                                 // sections (which defaults to 30)

                                 // User's can now make a #29 priority startup
                                 // routine that will set IsLibrary = false
                                 // for statically linked DLLs that use VCL
                                 // Packages.

#pragma exit  __ExitVCL 31       // Finalization of VCL routines.
                                 // Priority 31 is one eariler than what DCC32
                                 // uses for .PAS Units' Finalization sections
                                 // (which defaults to 30)


} // extern "C"