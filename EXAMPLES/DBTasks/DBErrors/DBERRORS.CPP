//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("main.cpp", FmMain);
USERES("dberrors.res");
USEDATAMODULE("DM1.cpp", DM);
USEFORM("About.cpp", FmAboutBox);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
        Application->Initialize();
        Application->CreateForm(__classid(TFmMain), &FmMain);
        Application->CreateForm(__classid(TDM), &DM);
        Application->CreateForm(__classid(TFmAboutBox), &FmAboutBox);
        Application->Run();
   }
   catch (Exception &exception)
   {
        Application->ShowException(&exception);
   }
        return 0;
}
//---------------------------------------------------------------------------
