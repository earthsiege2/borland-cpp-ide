//----------------------------------------------------------------------------
//Borland C++ Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("BKQUERY.res");
USEFORM("QueryFrm.cpp", AdhocForm);
USEFORM("RESLTFRM.CPP", QueryForm);
USEFORM("SAVEQAS.CPP", SaveQueryAs);
USERC("bkstring.rc");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
        Application->Initialize();
	Application->CreateForm(__classid(TAdhocForm), &AdhocForm);
	Application->Run();

    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
	return 0;
}
//---------------------------------------------------------------------------
