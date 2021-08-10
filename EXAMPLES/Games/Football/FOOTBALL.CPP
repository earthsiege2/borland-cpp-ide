//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("footmain.cpp", FormMain);
USEFORM("instr.cpp", About);
USERES("football.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
    Application->Initialize();
    Application->CreateForm(__classid(TFormMain), &FormMain);
    Application->CreateForm(__classid(TAbout), &About);
    Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }

    return 0;
}
//---------------------------------------------------------------------------
