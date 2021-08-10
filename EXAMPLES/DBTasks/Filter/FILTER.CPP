//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("FILTER1.cpp", fmFilterFrm);
USEFORM("CUSTVIEW.cpp", fmCustView);
USEDATAMODULE("DM.cpp", DM1);
USEFORM("ABOUT.cpp", fmAboutBox);
USERES("filter.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
        Application->Initialize();
        Application->CreateForm(__classid(TfmCustView), &fmCustView);
        Application->CreateForm(__classid(TDM1), &DM1);
        Application->CreateForm(__classid(TfmFilterFrm), &fmFilterFrm);
        Application->Run();
   }
   catch (Exception &exception)
   {
        Application->ShowException(&exception);
   }
    return 0;
}
//---------------------------------------------------------------------------
