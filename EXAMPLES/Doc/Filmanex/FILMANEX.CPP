//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("FILMANEX.res");
USEFORM("FATTRDLG.CPP", FileAttrDlg);
USEFORM("Fchngdlg.cpp", ChangeDlg);
USEUNIT("fmxUtils.cpp");
USEFORM("fmxwin.cpp", FormMain);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TFormMain), &FormMain);
	Application->CreateForm(__classid(TFileAttrDlg), &FileAttrDlg);
	Application->CreateForm(__classid(TChangeDlg), &ChangeDlg);
	Application->Run();

	return 0;
}
//---------------------------------------------------------------------------
