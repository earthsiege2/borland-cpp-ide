//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("find.res");
USEFORM("FindCust.cpp", fmFindCust);
USEFORM("CUST.CPP", fmCustomers);
USEFORM("ABOUT.CPP", fmAboutBox);
USEDATAMODULE("DM.cpp", DM2);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
	Application->Initialize();
	Application->CreateForm(__classid(TfmCustomers), &fmCustomers);
	Application->CreateForm(__classid(TfmFindCust), &fmFindCust);
	Application->CreateForm(__classid(TDM2), &DM2);
	Application->Run();
   }
   catch (Exception &exception)
   {
        Application->ShowException(&exception);
   }
	return 0;
}
//---------------------------------------------------------------------------
