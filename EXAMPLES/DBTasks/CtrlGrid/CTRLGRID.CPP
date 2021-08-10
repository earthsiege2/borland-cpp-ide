//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("ABOUT.CPP", FMAboutBox);
USEFORM("CTRLFORM.CPP", FmCtrlGrid);
USEDATAMODULE("DM.CPP", DM1);
USERES("ctrlgrid.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
        Application->Initialize();
        Application->CreateForm(__classid(TFmCtrlGrid), &FmCtrlGrid);
        Application->CreateForm(__classid(TFMAboutBox), &FMAboutBox);
        Application->CreateForm(__classid(TDM1), &DM1);
        Application->Run();
   }
   catch (Exception &exception)
   {
        Application->ShowException(&exception);
   }
        return 0;
}
//---------------------------------------------------------------------------
