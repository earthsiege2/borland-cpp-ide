//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("packapi.res");
USEPACKAGE("vcl50.bpi");
USEUNIT("wizmain.cpp");
USEFORM("FormMain.cpp", PackageForm);
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <toolsapi.hpp>

#include "wizmain.h"

//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------

namespace Packapi
{
  void __fastcall PACKAGE Register()
  {
    RegisterPackageWizard(new TPackageServices);
  }
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  return 1;
}
//---------------------------------------------------------------------------
