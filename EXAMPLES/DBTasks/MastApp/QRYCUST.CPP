//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "qrycust.h"
#include "pickdate.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TQueryCustDlg *QueryCustDlg;
//---------------------------------------------------------------------------
void TQueryCustDlg::SetFromDate(TDateTime NewDate)
{
  FromEdit->Text = DateToStr(NewDate);
}
//---------------------------------------------------------------------------
void TQueryCustDlg::SetToDate(TDateTime NewDate)
{
  ToEdit->Text = DateToStr(NewDate);
}

//---------------------------------------------------------------------------
TDateTime TQueryCustDlg::GetFromDate()
{
  if (FromEdit->Text.c_str())
     return StrToDate(FromEdit->Text);
  else
     return 0;
}
//---------------------------------------------------------------------------
TDateTime TQueryCustDlg::GetToDate()
{
  if (ToEdit->Text.c_str())
     return StrToDate(ToEdit->Text);
  else
     return 0;
}
//---------------------------------------------------------------------------
__fastcall TQueryCustDlg::TQueryCustDlg(TComponent* Owner)
	: TForm(Owner)
{
  Msglab->Caption = "Customers with LastInvoiceDate ranging:";
  FromDate = EncodeDate(1995, 01, 01);
  ToDate = Now();
}
//---------------------------------------------------------------------------
void __fastcall TQueryCustDlg::OkBtnClick(TObject *Sender)
{
  TDateTime Test;
  try
  {
    Test = StrToDate(FromEdit->Text); // validate date strings
    Test = StrToDate(ToEdit->Text);
    if (((int)ToDate != 0) && (ToDate < FromDate))
    {
      ShowMessage("\"TO\" date cannot be less than \"FROM\" date");
      ModalResult = mrNone;
    }
    else ModalResult = mrOk;
  }
  catch(EConvertError * ece)
  {
    ShowMessage("  Invalid date specified");
    ModalResult = mrNone;
  }
}
//---------------------------------------------------------------------------
void __fastcall TQueryCustDlg::PopupCalBtnFromClick(TObject *Sender)
{
  BrDateForm->Date = StrToDate(FromEdit->Text);  //start with current date }
  if (BrDateForm->ShowModal() == mrOk)
     FromEdit->Text = DateToStr(BrDateForm->Date);
}
//---------------------------------------------------------------------------
void __fastcall TQueryCustDlg::PopupCalToBtnClick(TObject *Sender)
{
  BrDateForm->Date = StrToDate(ToEdit->Text);   //start with current date }
  if (BrDateForm->ShowModal() == mrOk)
    ToEdit->Text = DateToStr(BrDateForm->Date);
}
//---------------------------------------------------------------------------
