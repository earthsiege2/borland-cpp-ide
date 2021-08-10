//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("dclinetxcustom_bcb.res");
USEPACKAGE("vcl50.bpi");
USEUNIT("inetxcustomreg.cpp");
USERES("inetxcustomreg.dcr");
USEPACKAGE("inetxcustom_bcb.bpi");
USEPACKAGE("Vclmid50.bpi");
USEPACKAGE("Vcldb50.bpi");
USEPACKAGE("Inetdb50.bpi");
USEPACKAGE("Inet50.bpi");
USEPACKAGE("Vclbde50.bpi");
USEPACKAGE("webmid50.bpi");
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
        return 1;
}
//---------------------------------------------------------------------------
