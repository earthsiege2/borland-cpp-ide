//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mainform .h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormClrDlg *FormClrDlg;
//---------------------------------------------------------------------------
__fastcall TFormClrDlg::TFormClrDlg(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormClrDlg::ButtonClick(TObject *Sender)
{
    if (ColorDialog->Execute())
    {
        Color = ColorDialog->Color;
    }
}
//---------------------------------------------------------------------