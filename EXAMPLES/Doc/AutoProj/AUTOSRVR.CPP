//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlmod.h>
#include "MyAutoImpl.h"
USERES("autosrvr.res");
USEFORM("main.cpp", FormMain);
USETLB("autosrvr.tlb");
USEUNIT("autosrvr_TLB.cpp");
USEUNIT("MyAutoImpl.cpp"); /* MyAuto: CoClass */
USEUNIT("autosrvr_ATL.cpp");
//---------------------------------------------------------------------------
TComModule _ProjectModule(0 /*InitATLServer*/);
TComModule &_Module = _ProjectModule;

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_MyAuto, TMyAutoImpl)
END_OBJECT_MAP()
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormMain), &FormMain);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
