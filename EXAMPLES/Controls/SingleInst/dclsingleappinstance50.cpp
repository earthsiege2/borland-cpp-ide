//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("dclSingleAppInstance50.res");
USEUNIT("SingleAppInstanceDesignTimeCode.cpp");
USEPACKAGE("SingleAppInstance50.bpi");
USEFORM("SingleAppInstanceDesignMarkerForm.cpp", frmMarkerPropertyEditor);
USEPACKAGE("vcl50.bpi");
USERC("SingleAppInstanceDesignTimeCode.rc");
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
