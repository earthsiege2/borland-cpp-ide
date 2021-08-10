//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("GRAPHEX.res");
USEFORM("GRAPHWIN.CPP", FormMain);
USEFORM("BMPDLG.CPP", NewBMPForm);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TFormMain), &FormMain);
	Application->CreateForm(__classid(TNewBMPForm), &NewBMPForm);
	Application->Run();

	return 0;
}
//---------------------------------------------------------------------------
