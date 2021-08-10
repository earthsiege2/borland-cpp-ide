//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
HINSTANCE g_hinst;
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("traymain.cpp", FormMain);
USERES("trayicon.res");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE hInstance, LPSTR, int)
{
    Application->Initialize();
    g_hinst = hInstance;
    Application->CreateForm(__classid(TFormMain), &FormMain);
        Application->Run();

    return 0;
}
//---------------------------------------------------------------------------

