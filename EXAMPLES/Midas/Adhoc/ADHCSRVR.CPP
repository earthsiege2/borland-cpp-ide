//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <atl\atlmod.h>
#include "AdHcDMImpl.h"
USERES("adhcsrvr.res");
USEFORM("adhcmain.cpp", FormMain);
USETLB("adhcsrvr.tlb");
USEUNIT("adhcsrvr_TLB.cpp");
USEFORM("AdHcDMImpl.cpp", AdHcDM); /* TCRemoteDataModule: DesignClass */ /* AdHcDM: CoClass */
USEUNIT("adhcsrvr_ATL.cpp");
//---------------------------------------------------------------------------
TComModule _ProjectModule(0 /*InitATLServer*/);
TComModule &_Module = _ProjectModule;

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_AdHcDM, TAdHcDMImpl)
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
