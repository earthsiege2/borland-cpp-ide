//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlmod.h>
#include "ServData.h"
USERES("EmpSrvr.res");
USEFORM("ServMain.cpp", MainForm);
USETLB("EmpSrvr.tlb");
USEUNIT("EmpSrvr_TLB.cpp");
USEFORM("ServData.cpp", EmpServer_BCB); /* TCRemoteDataModule: DesignClass */ /* EmpServer_BCB: CoClass */
USEUNIT("EmpSrvr_ATL.cpp");
USEFILE("readmes.txt");
//---------------------------------------------------------------------------
TComModule _ProjectModule(0 /*InitATLServer*/);
TComModule &_Module = _ProjectModule;

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_EmpServer_BCB, TEmpServer_BCBImpl)
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
