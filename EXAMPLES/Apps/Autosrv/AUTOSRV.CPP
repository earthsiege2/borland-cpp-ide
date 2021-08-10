//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlmod.h>
#include "EditServerImpl.h"
USERES("autosrv.res");
USEFORM("main.cpp", Form1);
USETLB("autosrv.tlb");
USEUNIT("autosrv_TLB.cpp");
USEUNIT("EditServerImpl.cpp"); /* EditServer: CoClass */
USEUNIT("autosrv_ATL.cpp");
//---------------------------------------------------------------------------
TComModule _ProjectModule(0 /*InitATLServer*/);
TComModule &_Module = _ProjectModule;

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_EditServer, TEditServerImpl)
END_OBJECT_MAP()
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
