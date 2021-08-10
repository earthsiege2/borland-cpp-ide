//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GridForm.h"
#include "RecForm.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TGridViewForm *GridViewForm;
//---------------------------------------------------------------------------
__fastcall TGridViewForm::TGridViewForm(TComponent* Owner)
  : TStdDataForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGridViewForm::DBGrid1DblClick(TObject *Sender)
{
  RecViewForm->Show();
}
//---------------------------------------------------------------------
void __fastcall TGridViewForm::FormShow(TObject *Sender)
{
  Cust->Open();
  Orders->Open();
}
//---------------------------------------------------------------------------
