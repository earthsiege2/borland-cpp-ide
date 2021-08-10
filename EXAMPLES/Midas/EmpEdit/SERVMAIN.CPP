//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// This program represents the "Application Server" portion of the
// distributed datasets demo.  The other part is the client which will access
// the data provided by this server.  You must compile and run this program
// once before running the EmpEdit project.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ServMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// These procedures update the display of the application server form for
// the purposes of this demo.  A typical Application Server would probably
// not have any visible UI.  You can add a line to your project file to
// prevent the application server icon from being displayed on the taskbar.
//
void __fastcall TMainForm::UpdateClientCount(int Incr)
{
  FClientCount += Incr;
  ClientCount->Caption = IntToStr(FClientCount);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::IncQueryCount(void)
{
  FQueryCount++;
  QueryCount->Caption = IntToStr(FQueryCount);
}

