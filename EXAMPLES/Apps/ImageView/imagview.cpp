//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//----------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("imagewn.cpp", ImageForm);
USEFORM("ViewFrm.cpp", ViewFrm);
USERES("imagview.res");
//----------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
    Application->Initialize();
    Application->CreateForm(__classid(TImageForm), &ImageForm);
    Application->CreateForm(__classid(TViewFrm), &ViewFrm);
    Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }

    return 0;
}
//---------------------------------------------------------------------
