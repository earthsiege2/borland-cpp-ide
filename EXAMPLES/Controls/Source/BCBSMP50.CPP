//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEPACKAGE("vcl50.bpi");
USEPACKAGE("vclx50.bpi");
USEUNIT("ccalendr.cpp");
USEUNIT("cdiroutl.cpp");
USEUNIT("cgauges.cpp");
USEUNIT("cgrid.cpp");
USEUNIT("cspin.cpp");
USEUNIT("perfgrap.cpp");
USEUNIT("trayicon.cpp");
USEFORM("piereg.cpp", AngleEditorDlg);
USERES("bcbsmp50.res");
USERC("samp.rc");
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
