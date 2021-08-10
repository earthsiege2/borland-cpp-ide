//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("richedit.res");
USEFORM("Richabt.cpp", Form2);
USEFORM("Romain.cpp", MainForm);
USEUNIT("reinit.pas");
USEUNIT("ReConst.pas");
USE("readme.txt", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
