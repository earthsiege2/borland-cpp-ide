//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("adhcclnt.res");
USEFORM("clntmain.cpp", FormMain);
USEUNIT("adhcsrvr_TLB.cpp");
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
