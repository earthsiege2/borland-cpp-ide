//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("Toolbar.cpp", fmToolbar);
USEFORM("CustData.cpp", fmCustomer);
USEFORM("CustOrds.cpp", fmCustOrd);
USEFORM("About.cpp", fmAboutBox);
USEDATAMODULE("DM.cpp", DM1);
USERES("navmdi.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TfmToolbar), &fmToolbar);
       Application->CreateForm(__classid(TDM1), &DM1);
       Application->CreateForm(__classid(TfmCustomer), &fmCustomer);
       Application->CreateForm(__classid(TfmCustOrd), &fmCustOrd);
       Application->CreateForm(__classid(TfmAboutBox), &fmAboutBox);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
       return 0;
}
//---------------------------------------------------------------------------
