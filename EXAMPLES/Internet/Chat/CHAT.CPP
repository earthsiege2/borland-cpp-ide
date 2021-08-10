//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("main.cpp", ChatForm);
USERES("chat.res");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
          Application->Initialize();
          Application->CreateForm(__classid(TChatForm), &ChatForm);
          Application->Run();
        }
        catch (Exception &exception)
        {
          Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
