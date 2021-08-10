//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "filters.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFilterDlg *FilterDlg;
//---------------------------------------------------------------------------
__fastcall TFilterDlg::TFilterDlg(TComponent* Owner)
                      : TForm(Owner)
{
}

//========================================= TFilterDlg ==========
void __fastcall TFilterDlg::SetFilter(const AnsiString Value)
{
   int P;

  Description->Text = "";
  Extension->Text = "";
  if (Value > "")
  {
    P = Value.Pos("|");
    if (!P) P = 256;
    Description->Text = Value.SubString(1, P - 1);
    Extension->Text = Value.SubString(P + 1, 255);
  }
} // end of TFilterDlf::SetFilter()

//========================================= TFilterDlg ==========
String __fastcall TFilterDlg::GetFilter(void)
{
  AnsiString Result = Description->Text + "|" + Extension->Text;
  return Result;
} // end of TFilterDlg::GetFilter()

//---------------------------------------------------------------------------
