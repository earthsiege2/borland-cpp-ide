//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("dclversioninfo50.res");
USEPACKAGE("versioninfo50.bpi");
USEUNIT("VersionInfoDesignTimeCode.cpp");
USEUNIT("VersionInfoIdeInteraction.cpp");
USEPACKAGE("vcl50.bpi");
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
