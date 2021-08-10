//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("dclversioninfo60.res");
USEPACKAGE("versioninfo60.bpi");
USEUNIT("VersionInfoDesignTimeCode.cpp");
USEUNIT("VersionInfoIdeInteraction.cpp");
USEPACKAGE("vcl60.bpi");
USEUNIT("VersionInfoRegistration.cpp");
USERC("VersionInfoRegistration.rc");
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
