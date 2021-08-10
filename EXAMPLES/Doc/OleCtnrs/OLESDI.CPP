//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("sdimain.cpp", MainForm);
USEFORM("about.cpp", AboutBox);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Initialize();
    Application->CreateForm(__classid(TMainForm), &MainForm);
    Application->Run();

    return 0;
}
//---------------------------------------------------------------------------
