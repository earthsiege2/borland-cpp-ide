//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("proc.cpp", FormMain);
USEFORM("another.cpp", Form2);
USERES("Procview.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
      Application->Initialize();
      Application->CreateForm(__classid(TFormMain), &FormMain);
      Application->CreateForm(__classid(TForm2), &Form2);
      Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }

   return 0;
}
//---------------------------------------------------------------------
