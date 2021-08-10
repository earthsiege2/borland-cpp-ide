//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("SPrmClnt.res");
USEFORM("ClntMain.cpp", FormMain);
USEFORM("ClntDM.cpp", DataModule1); /* TDataModule: DesignClass */
USE("readmec.txt", File);
USEFORM("ClntAbout.cpp", AboutBox);
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
