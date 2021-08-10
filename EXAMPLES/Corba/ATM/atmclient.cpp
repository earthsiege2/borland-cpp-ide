//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("atmclient.res");
USEFORM("atmunit.cpp", FormATM);
USEIDL("xaction.idl");
USEFORM("servname.cpp", ServerNameDlg);
USEFILE("readme.txt");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TFormATM), &FormATM);
       Application->CreateForm(__classid(TServerNameDlg), &ServerNameDlg);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------
