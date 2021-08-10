//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\libmain.cpp
//   Implementation of LibMain()
//----------------------------------------------------------------------------
#undef _BUILDOWLDLL
#include <owl\owlpch.h>
#include <owl\module.h>

DIAG_DECLARE_GROUP(OwlApp);        // General Application diagnostic group

#if defined(__WIN32__)

BOOL WINAPI
DllEntryPoint(HINSTANCE hInstance, DWORD reason, LPVOID)
{
  TRACEX(OwlApp, 0, "DllEntryPoint(" << hInstance << ", " << reason << ", " <<
         ") called");
  
  switch (reason) {
    case DLL_PROCESS_ATTACH:
      if (!::Module)
        ::Module = new TModule(0, hInstance);
  }
  return TRUE;
}

#else   // !defined(__WIN32__)

int
FAR PASCAL
LibMain(HINSTANCE   hInstance,
        WORD      /*wDataSeg*/,
        WORD      /*cbHeapSize*/,
        char far* /*cmdLine*/)
{
  TRACEX(OwlApp, 0, "LibMain(" << (unsigned)hInstance << ",,,) called");
  ::Module = new TModule(0, hInstance);
  return TRUE;
}

#endif  // defined(__WIN32__)
