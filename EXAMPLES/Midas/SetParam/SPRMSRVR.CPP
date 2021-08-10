//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <atl\atlmod.h>
#include "SetParamSrvrImpl.h"
USERES("SPrmSrvr.res");
USEFORM("FormMain.cpp", MainForm);
USETLB("SPrmSrvr.tlb");
USEUNIT("SPrmSrvr_TLB.cpp");
USEFORM("SetParamSrvrImpl.cpp", SetParamSrvr); /* TCRemoteDataModule: DesignClass */ /* SetParamSrvr: CoClass */
USEUNIT("SPrmSrvr_ATL.cpp");
USE("readmes.txt", File);
//---------------------------------------------------------------------------
TComModule _ProjectModule(0 /*InitATLServer*/);
TComModule &_Module = _ProjectModule;

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_SetParamSrvr, TSetParamSrvrImpl)
END_OBJECT_MAP()
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
