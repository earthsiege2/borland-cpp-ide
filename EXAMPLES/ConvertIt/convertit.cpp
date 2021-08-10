//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987 - 2001 Borland International Inc. All Rights Reserved.
//---------------------------------------------------------------------------
// ConverIt : Conversion Utilities Demo v.1 
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("ConvertIt.res");
USEUNIT("StdConvs.pas");     // VCL conversion utilities.
USEUNIT("EuroConv.cpp");     // Included only to project so it's initialized.
USEFORM("Unit1.cpp", Form1); // Main form
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 TForm1 *Form1;
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
