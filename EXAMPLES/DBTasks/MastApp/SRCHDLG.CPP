//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "srchdlg.h"
#include "Datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TSearchDlg *SearchDlg;
//---------------------------------------------------------------------------
__fastcall TSearchDlg::TSearchDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSearchDlg::DBGrid1DblClick(TObject *Sender)
{
  ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TSearchDlg::SearchButtonClick(TObject *Sender)
{
  TLocateOptions flags;
  flags << loPartialKey << loCaseInsensitive;
  if (!DataSource->DataSet->Locate(OrderCombo->Text, SearchEd->Text, flags))
      MessageBox(NULL,"No matching record found.", "Information", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TSearchDlg::OrderComboChange(TObject *Sender)
{
  SrchFld = DataSource->DataSet->FieldByName(OrderCombo->Text);
  SearchEd->Text = " ";
}
//---------------------------------------------------------------------------
void __fastcall TSearchDlg::SearchEdKeyPress(TObject *Sender, char &Key)
{
  if ((SrchFld!=NULL) && (Key != ' ') &&  !SrchFld->IsValidChar(Key) )
  {
    MessageBeep(0);
    Key = '0';
  }
}
//---------------------------------------------------------------------------
void __fastcall TSearchDlg::SearchEdChange(TObject *Sender)
{
  SearchButton->Enabled =  !SearchEd->Text.IsEmpty();
}
//---------------------------------------------------------------------------
double TSearchDlg::GetCustNo()
{
  return MastData->CustCustNo->Value;
}
//---------------------------------------------------------------------------
void TSearchDlg::SetCustNo(double NewCustNo)
{
  TLocateOptions flags;
  MastData->Cust->Locate("CustNo", NewCustNo, flags);
}
//---------------------------------------------------------------------------
double TSearchDlg::GetPartNo()
{
  return MastData->PartsPartNo->Value;
}
//---------------------------------------------------------------------------
void TSearchDlg::SetPartNo(double NewPartNo)
{
  TLocateOptions flags;
  MastData->Parts->Locate("PartNo", NewPartNo, flags);
}
//---------------------------------------------------------------------------
int TSearchDlg::ShowModalCust()
{
  OrderCombo->Items->Clear();
  OrderCombo->Items->Add("Company");
  OrderCombo->Items->Add("CustNo");
  OrderCombo->ItemIndex = 0;
  DataSource->DataSet = MastData->Cust;
  OrderComboChange(0);
  Caption = "Select a Customer";
  return ShowModal();
}
//---------------------------------------------------------------------------
int TSearchDlg::ShowModalParts()
{
  OrderCombo->Items->Clear();
  OrderCombo->Items->Add("Description");
  OrderCombo->Items->Add("PartNo");
  OrderCombo->ItemIndex = 0;
  DataSource->DataSet = MastData->Parts;
  OrderComboChange(0);
  Caption = "Select a Part";
  return ShowModal();
}
//---------------------------------------------------------------------------

