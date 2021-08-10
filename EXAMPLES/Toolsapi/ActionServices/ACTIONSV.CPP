//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("frmmain.cpp", FormMain);
//---------------------------------------------------------------------------
#include <toolsapi.hpp>
#include "wizmain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------

namespace Actionsv
{
  void __fastcall PACKAGE Register()
  {
    RegisterPackageWizard(new TActionServices);
  }
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  return 1;
}
//---------------------------------------------------------------------------
