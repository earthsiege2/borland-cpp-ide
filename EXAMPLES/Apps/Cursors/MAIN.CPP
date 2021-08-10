//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
  ComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ComboBox1Change(TObject *Sender)
{
        static int cursors[] = {
         crDefault, crNone, crArrow, crCross, crIBeam,
         crSize, crSizeNESW, crSizeNS, crSizeNWSE,
         crSizeWE, crUpArrow, crHourGlass, crDrag,
         crNoDrop, crHSplit, crVSplit, crMultiDrag,
         crSQLWait, crNo, crAppStart, crHelp};

        Cursor = TCursor(cursors[ComboBox1->ItemIndex]);
}
//---------------------------------------------------------------------
