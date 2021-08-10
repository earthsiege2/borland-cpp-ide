//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("inetxcustom_bcb.res");
USEPACKAGE("vcl50.bpi");
USEUNIT("ReconcileProd.cpp");
USEPACKAGE("webmid50.bpi");
USEPACKAGE("Inet50.bpi");
USEPACKAGE("Vclmid50.bpi");
USEPACKAGE("Vcldb50.bpi");
USEPACKAGE("Inetdb50.bpi");
USEUNIT("showxml.cpp");
USEPACKAGE("Vclbde50.bpi");
USEUNIT("ImgButtons.cpp");
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
