//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Default OwlMain to satisfy LibMain in DLLs that aren't components
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

OWL_DIAGINFO;

int
OwlMain(int argc, char* argv[])
{
  // This OwlMain should be called only when the user builds a DLL.
  // If it's called from an EXE, that means the user did not provide
  // an OwlMain with the proper prototype.  Issue a warning.
  //
  // When LibMain/DllEntryPoint calls this OwlMain, both arguments
  // are 0.  If either argument is non-zero, an EXE is running.
  //
  PRECONDITION(argc == 0);
  PRECONDITION(argv == 0);

  if (argc != 0 && argv != 0) {
    ::MessageBox(0, "You have accidently used the dummy version of OwlMain.",
                "Error", MB_ICONHAND | MB_OK);
  }

  return 0;
}
