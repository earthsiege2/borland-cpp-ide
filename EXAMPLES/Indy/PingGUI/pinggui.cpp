//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USEFORM("Main.cpp", TfrmPing);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TTfrmPing), &TfrmPing);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
