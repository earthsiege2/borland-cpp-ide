//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("appevents.res");
USEFORM("main.cpp", AppEventForm);
USE("readme.txt", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TAppEventForm), &AppEventForm);
                 Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
