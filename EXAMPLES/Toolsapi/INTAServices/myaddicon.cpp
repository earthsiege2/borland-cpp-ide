//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("FormMain.cpp", DisplayForm);
//---------------------------------------------------------------------------
#include <toolsapi.hpp>

#include "wizmain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------

namespace Myaddicon
{
  void __fastcall PACKAGE Register()
  {
    RegisterPackageWizard(new TNTAServices);
  }
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  return 1;
}
//---------------------------------------------------------------------------
