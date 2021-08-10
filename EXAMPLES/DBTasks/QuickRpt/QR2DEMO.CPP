//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("grplist.cpp", GrpListForm);
USEFORM("list.cpp", ListForm);
USEFORM("manygrp.cpp", ManyGrpForm);
USEFORM("MD.cpp", MDForm);
USEFORM("menu.cpp", MainForm);
USERES("qr2demo.res");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
           Application->Initialize();
           Application->CreateForm(__classid(TMainForm), &MainForm);
           Application->CreateForm(__classid(TListForm), &ListForm);
           Application->CreateForm(__classid(TGrpListForm), &GrpListForm);
           Application->CreateForm(__classid(TMDForm), &MDForm);
           Application->CreateForm(__classid(TManyGrpForm), &ManyGrpForm);
           Application->Run();
        }
        catch (Exception &exception)
        {
           Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
