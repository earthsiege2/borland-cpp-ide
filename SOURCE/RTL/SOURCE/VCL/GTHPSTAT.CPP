/*-----------------------------------------------------------------------*
 * filename - gthpstat.cpp
 *
 * function(s)
 *
 *   System::GetHeapStatus()
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <windows.h>
#include <_defs.h>
#include "delphimm.h"

using System::THeapStatus;

#define BORLNDMM                 "borlndmm"
#define BORLNDMM_GETHEAPSTATUS   "GetHeapStatus"

THeapStatus _EXPFUNC _vcl_GetHeapStatus(void)
{
#if defined(_BUILDRTLDLL)
    /* By getting here we know the user linked with CP32MTI.LIB and is thus
       using BORLNDMM.DLL.  So in order for the function
       System::GetHeapStatus() to work, we must get its address from the
       BORLNDMM.DLL and use it when the function gets called.

    */

    typedef THeapStatus __fastcall (* pfn_GetHeapStatus)();
    static pfn_GetHeapStatus _GetHeapStatus = NULL;
    static HANDLE mm;

    if (!_GetHeapStatus)
    {
        if (!mm)
        {
            mm = GetModuleHandle(BORLNDMM);
            if (!mm)
                return System::GetHeapStatus();
        }


        _GetHeapStatus = (pfn_GetHeapStatus)
                         GetProcAddress(mm, BORLNDMM_GETHEAPSTATUS);
    }

    return _GetHeapStatus();

#else // _BUILDRTLDLL
    /* By getting here we know that the user linked with CP32MT.LIB and
       should therefore not be using packages.  This means that we should
       simply re-vector the call to System::GetHeapStatus().
    */
    return System::GetHeapStatus();

#endif // _BUILDRTLDLL
}


