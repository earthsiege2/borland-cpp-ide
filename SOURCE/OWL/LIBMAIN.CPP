//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Default implementation of LibMain() for user DLLs
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

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

#if !defined(BIDS_DLLNAME)
# if defined(__TRACE)
#   define BIDS_DLLNAME "BIDS50D"
# else
#   define BIDS_DLLNAME "BIDS50"
# endif
#endif
#if !defined(OWL_DLLNAME)
# if defined(__TRACE)
#   define OWL_DLLNAME "OWL50D"
# else
#   define OWL_DLLNAME "OWL50"
# endif
#endif

static char BidsDllName[] = BIDS_DLLNAME ".DLL";
static char OwlDllName[] = OWL_DLLNAME ".DLL";

static HINSTANCE BidsInst = 0;
static HINSTANCE OwlInst = 0;

void lockDlls()
{
  BidsInst = ::LoadLibrary(BidsDllName);  // load lowlevel to hilevel order
  OwlInst = ::LoadLibrary(OwlDllName);
}
#pragma startup lockDlls 0

void unlockDlls()
{
  if (BidsInst > HINSTANCE(HINSTANCE_ERROR))
    ::FreeLibrary(OwlInst);  // unload hilevel to lowlevel order (reversed)
  if (OwlInst > HINSTANCE(HINSTANCE_ERROR))
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
