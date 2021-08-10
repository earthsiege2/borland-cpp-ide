//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop
USEFORM("ClxAbout.cpp", AboutBox);
USEFORM("ClxChildWin.CPP", MDIChild);
USEFORM("ClxMain.cpp", MainForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
