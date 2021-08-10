//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000-2002 Borland Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("PWordComp.res");
USEFORM("main.cpp", PWordForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TPWordForm), &PWordForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
