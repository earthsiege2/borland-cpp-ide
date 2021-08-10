//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Default OwlMain to satisfy LibMain in DLLs that aren't components
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlMain);

// Lock BIDS and OWL when building user DLL - 16-bit Windows may/does not
// always unload DLLs in proper order.
//      
#if defined(_OWLDLL) && !defined(BI_PLAT_WIN32)
               
static char BidsDllName[] = BIDS_DLLNAME ".DLL";
static char OwlDllName[] = OWL_DLLNAME ".DLL";

static HINSTANCE BidsInst = 0;
static HINSTANCE OwlInst = 0;

//
// Add extra ref. counts on BIDS and OWL DLLs since Windows may (does) unload
// DLLs in 'wrong' order causing a crash at shut-down.
//
void lockDlls()
{
  BidsInst = ::LoadLibrary(BidsDllName);  
  OwlInst = ::LoadLibrary(OwlDllName);
}
#pragma startup lockDlls 0

//
// Remove extra ref. counts on BIDS and OWL DLLs
//
void unlockDlls()
{
  if (OwlInst > HINSTANCE(HINSTANCE_ERROR))
    ::FreeLibrary(OwlInst);  
  if (BidsInst > HINSTANCE(HINSTANCE_ERROR))
    ::FreeLibrary(BidsInst);
}
#pragma exit unlockDlls 0

#endif

// Routine which initializes an OWL User DLL..
// NOTE: Must be explicitly invoked if your DLL provides it's own
//       LibMain, DllEntryPoint (or DllMain).
//
bool
OWLInitUserDLL(HINSTANCE hInstance, LPSTR cmdLine)
{
  // If no global ::Module ptr exists yet, provide a default now
  //
  if (!::Module) {
    static TModule module(0, hInstance);
    ::Module = &module;
  }

  // Store away information about this instance
  //
  TApplication::SetWinMainParams(hInstance, 0, cmdLine, SW_SHOWNORMAL);

  TRY {
    int retVal = OwlMain(0, 0);
    TRACEX(OwlMain, 0, "DllEntryPoint() returns " << retVal);
    return retVal == 0;
  }
  CATCH( (xmsg& x) {return ::HandleGlobalException(x, 0) == 0;} )
}

