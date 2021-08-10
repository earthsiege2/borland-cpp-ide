//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("MDClnt.res");
USEFORM("ClntMain.cpp", FormMain);
USEFORM("MDClntDM.cpp", DataModule1); /* TDataModule: DesignClass */
USEUNIT("MDSrvr_TLB.cpp");
USEFORM("ClntAbout.cpp", AboutBox);
USEFORM("RecError.cpp", ReconcileErrorForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TDataModule1), &DataModule1);
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
