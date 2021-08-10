//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Default implementation of LibMain() for user DLLs
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlMain, true, 0);

#if defined(BI_PLAT_WIN32)

int WINAPI
DllEntryPoint(HINSTANCE hInstance, uint32 reason, LPVOID)
{
  TRACEX(OwlMain, 0, "DllEntryPoint(" << hInstance << ", " << reason << ", " <<
         ") called");
  
  switch (reason) {
    case DLL_PROCESS_ATTACH:
      // If no global ::Module ptr exists yet, provide a default now
      //
      if (!::Module) {
        static TModule module(0, hInstance);
        ::Module = &module;
      }
      TApplication::SetWinMainParams(hInstance, 0, 0, SW_SHOWNORMAL);
 
      TRY {
        int retVal = OwlMain(0, 0);
        TRACEX(OwlMain, 0, "DllEntryPoint() returns " << retVal);
        return retVal == 0;
      }
      CATCH( (xmsg& x) {return ::HandleGlobalException(x, 0) == 0;} )
  }
  return true;
}

#else   // !defined(BI_PLAT_WIN32)

//
// Make sure that the DLLs we use stay in memory while we perform static
// destructor cleanup
//
#if defined(_OWLDLL)

static HINSTANCE BidsInst;
static HINSTANCE OwlInst;
void lockDlls()
{
  BidsInst = ::LoadLibrary("BIDS45.DLL");  // load lowlevel to hilevel order
  OwlInst = ::LoadLibrary("OWL250.DLL");
}
#pragma startup lockDlls 0

void unlockDlls()
{
  ::FreeLibrary(OwlInst);  // unload hilevel to lowlevel order (reversed)
  ::FreeLibrary(BidsInst);
}
#pragma exit unlockDlls 0

#endif

int
FAR PASCAL
LibMain(HINSTANCE   hInstance,
        uint16    /*wDataSeg*/,
        uint16    /*cbHeapSize*/,
        char far*   cmdLine)
{
  TRACEX(OwlMain, 0, "LibMain(" << hex << uint(hInstance) << ", " << 
                                  TResId(cmdLine)  << ") called");

  // If no global ::Module ptr exists yet, provide a default now
  //
  if (!::Module) {
    static TModule module(0, hInstance);
    ::Module = &module;
  }

  TApplication::SetWinMainParams(hInstance, 0, cmdLine, SW_SHOWNORMAL);

  TRY {
    int retVal = OwlMain(0, 0);
    TRACEX(OwlMain, 0, "LibMain() returns " << retVal);
    return retVal == 0;
  }
  CATCH( (xmsg& x) {return ::HandleGlobalException(x, 0) == 0;} )
}

#endif  // defined(BI_PLAT_WIN32)
