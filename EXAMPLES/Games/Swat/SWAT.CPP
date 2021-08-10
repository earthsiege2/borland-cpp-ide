//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("swatmain.cpp", SwatForm);
USEFORM("about.cpp", AboutBox);
USEFORM("options.cpp", OptionsDlg);
USERES("swat.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
    Application->Initialize();
    Application->Title = "Swat!";
    Application->CreateForm(__classid(TSwatForm), &SwatForm);
    Application->CreateForm(__classid(TAboutBox), &AboutBox);
    Application->CreateForm(__classid(TOptionsDlg), &OptionsDlg);
    Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }

   return 0;
}
//---------------------------------------------------------------------------
