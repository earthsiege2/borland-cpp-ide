//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("versioninfo50.res");
USEUNIT("VersionInfoComponent.cpp");
USEUNIT("VersionInfoUI.cpp");
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
