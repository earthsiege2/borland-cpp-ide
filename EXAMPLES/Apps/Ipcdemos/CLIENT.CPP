//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("CLNTFORM.cpp", ClientForm);
USEUNIT("IPCTHRD.cpp");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Initialize();
    Application->CreateForm(__classid(TClientForm), &ClientForm);
    Application->Run();

    return 0;
}
//---------------------------------------------------------------------------
