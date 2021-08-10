//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of WinMain for user exes
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <osl/locale.h>

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlMain, true, 0);

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
    int retVal = OwlMain(_argc, _argv);
    TRACEX(OwlMain, 0, "WinMain() returns " << retVal);
    return retVal;
  }
  CATCH( (xmsg& x) {return ::HandleGlobalException(x, 0);} )
}
