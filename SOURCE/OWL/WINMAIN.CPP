//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\winmain.cpp
//   Implementation of WinMain for user exes
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>

DIAG_DECLARE_GROUP(OwlApp);        // General Application diagnostic group

//
// Default WinMain calls OwlMain, after setting params into TApplication
//
int PASCAL
WinMain(HINSTANCE instance, HINSTANCE prevInstance, char far* cmdLine, int cmdShow)
{
  TRACEX(OwlApp, 0, "WinMain(" << hex << UINT(instance) << ", " << 
                                  hex << UINT(prevInstance) << ", \"" << 
                                  TResId(cmdLine) << "\", " << 
                                  cmdShow << ") called");
  TApplication::SetWinMainParams(instance, prevInstance, cmdLine, cmdShow);
  int retVal = OwlMain(_argc, _argv);
  TRACEX(OwlApp, 0, "WinMain() returns " << retVal);

  return retVal;
}
