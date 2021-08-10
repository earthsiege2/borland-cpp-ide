//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
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
