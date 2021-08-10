//---------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("colordlg.res");
USEFORM("mainform.cpp", FormClrDlg);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
      Application->Initialize();
      Application->CreateForm(__classid(TFormClrDlg), &FormClrDlg);
      Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }


    return 0;
}
//---------------------------------------------------------------------------
