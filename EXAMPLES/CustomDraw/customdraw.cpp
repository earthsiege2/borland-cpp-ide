//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("CustomDraw.res");
USEFORM("CustDraw.cpp", CustomDrawForm);
USE("ReadMe.txt", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TCustomDrawForm), &CustomDrawForm);
                 Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------
