//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("Gdsstd.cpp", GDSStdForm);
USEFORM("GdsData.cpp", StdDataForm);
USEFORM("GridForm.cpp", GridViewForm);
USEFORM("RecForm.cpp", RecViewForm);
USERES("gdsdemo.res");
//---------------------------------------------------------------------
#pragma resource "*.res"
#pragma link "forms.obj"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
        Application->Initialize();
        Application->CreateForm(__classid(TGridViewForm), &GridViewForm);
        Application->CreateForm(__classid(TRecViewForm), &RecViewForm);
        Application->Run();
   }
   catch (Exception &exception)
   {
        Application->ShowException(&exception);
   }
        return 0;
}
//---------------------------------------------------------------------------
