//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("SingleAppInstance50.res");
USEUNIT("SingleAppInstance.cpp");
USEPACKAGE("vcl50.bpi");
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
   return 1;
}
//---------------------------------------------------------------------------
