//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
// Default implementation of DLlEntryPoint()/LibMain() for user DLLs
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlMain);

#if defined(BI_PLAT_WIN32)

int WINAPI
DllEntryPoint(HINSTANCE hInstance, uint32 reason, LPVOID)
{
  TRACEX(OwlMain, 0, "DllEntryPoint(" << hInstance << ", " << reason << ", " <<
         ") called");

  switch (reason) {
    case DLL_PROCESS_ATTACH:

      // If you provide your own version of DLL EntryPoint, make sure
      // you call OwlInitUserDLL to allow OWL to initialize '::Module'
      //
      return OWLInitUserDLL(hInstance, 0) ? 1 : 0;
  }
  return 1;
}

#else   // !defined(BI_PLAT_WIN32)

int
FAR PASCAL
LibMain(HINSTANCE   hInstance,
        WORD      /*wDataSeg*/,
        WORD      /*cbHeapSize*/,
        LPSTR       cmdLine)
{
  TRACEX(OwlMain, 0, "LibMain(" << hex << uint(hInstance) << ", " <<
                                  TResId(cmdLine)  << ") called");

  // Allow OWL to initialize global '::Module' pointer and store
  // cmdLine information...
  //
  return OWLInitUserDLL(hInstance, cmdLine) ? 1 : 0;
}

#endif  // defined(BI_PLAT_WIN32)
