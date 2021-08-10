//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("autoclnt.res");
USEFORM("mainclnt.cpp", FormMain);
USEUNIT("autosrvr_TLB.cpp");
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
