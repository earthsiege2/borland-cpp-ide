//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of WinMain for user exes
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(WINSYS_LCLSTRNG_H)
# include <winsys/lclstrng.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlMain);

//
// Default WinMain calls OwlMain, after setting params into TApplication
//
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char far* cmdLine, int cmdShow)
{
  TRACEX(OwlMain, 0, "WinMain(" << hex << uint(hInstance) << ", " <<
                                  hex << uint(hPrevInstance) << ", \"" <<
                                  TResId(cmdLine) << "\", " <<
                                  cmdShow << ") called");

  // If no global ::Module ptr exists yet, provide a default now
  //
  if (!::Module) {
    static TModule module(0, hInstance);
    ::Module = &module;
  }

  TApplication::SetWinMainParams(hInstance, hPrevInstance, cmdLine, cmdShow);
  TRY {
#if defined(BI_COMP_BORLANDC)
    int retVal = OwlMain(_argc, _argv);
#else
    int retVal = OwlMain(__argc, __argv);
#endif
    TRACEX(OwlMain, 0, "WinMain() returns " << retVal);
    return retVal;
  }
  CATCH( (xmsg& x) {return ::HandleGlobalException(x, 0);} )
}
