//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Filter1.h"
#include "DM.h"
#include "CustView.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TfmFilterFrm::TfmFilterFrm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
TfmFilterFrm *fmFilterFrm;

// Adds current listbox field name to memo.
//
void __fastcall TfmFilterFrm::AddFieldName(TObject *Sender)
{
   if (Memo1->Text != ""){
     Memo1->Text =  Memo1->Text + " " +
                    ListBox1->Items->Strings[ListBox1->ItemIndex];
   }
   else
     Memo1->Text = ListBox1->Items->Strings[ListBox1->ItemIndex];
}

// Adds current Filter operator to memo.
//
void __fastcall TfmFilterFrm::ListBox2DblClick(TObject *Sender)
{
   if (Memo1->Text != ""){
     Memo1->Text = Memo1->Text + " " +
                   ListBox2->Items->Strings[ListBox2->ItemIndex];
   }
   else
     Memo1->Text = ListBox2->Items->Strings[ListBox2->ItemIndex];
}

void __fastcall TfmFilterFrm::ApplyFilter(TObject *Sender)
{
  TDataSet* data(DM1->CustomerSource->DataSet);
  if (ComboBox1->Text != "") {
    data->Filter = ComboBox1->Text;
    data->Filtered = true;
    fmCustView->Caption = "Customers - Filtered";
  }
  else {
    data->Filter = "";
    data->Filtered = false;
    fmCustView->Caption = "Customers - Unfiltered";
  }
}

// Populates ListBox and ComboBox for the form.
//
void __fastcall TfmFilterFrm::FormCreate(TObject *Sender)
{
// Populate the ListBox1 with available fields from the Customer DataSet.
  for (int i = 0; i < DM1->CustomerSource->DataSet->FieldCount; i++)
    ListBox1->Items->Add(DM1->Customer->Fields->Fields[i]->FieldName);
  Memo1->Lines->Clear();

// These strings could not be added to the ComboBox at design time because to
// do so would have hard wired us for a single country's date format.  The
// following lines will honor Windows 95 and NT's regional settings.
  ComboBox1->Items->Add("LastInvoiceDate >= '" +
                         DateToStr(EncodeDate(1994, 9, 30)) + "'");
  ComboBox1->Items->Add("Country = 'US' and LastInvoiceDate > '" +
                         DateToStr(EncodeDate(1994, 6, 30)) + "'");
}

// Since the Filter property is a TStrings and the Memo field
// is a TMemo, convert the Memo's wrapped text to a string,
// which is then used when the user presses Apply.
//
void __fastcall TfmFilterFrm::Memo1Change(TObject *Sender)
{
  ComboBox1->Text = Memo1->Lines->Strings[0];
  for (int i = 1; i < Memo1->Lines->Count; ++i){
    ComboBox1->Text = ComboBox1->Text + " " + Memo1->Lines->Strings[i];
  }
}

// Set the Customer's DataSet Case Sensitive Filter Option.
//
void __fastcall TfmFilterFrm::cbCaseSensitiveClick(TObject *Sender)
{
  TDataSet* data(DM1->CustomerSource->DataSet);
  if (cbCaseSensitive->Checked)
    data->FilterOptions >> foCaseInsensitive;
  else
    data->FilterOptions << foCaseInsensitive;
}

// Set the Customer Partial Compare Filter Option.
//
void __fastcall TfmFilterFrm::cbPartialCompareClick(TObject *Sender)
{
  TDataSet* data(DM1->CustomerSource->DataSet);
  if (cbPartialCompare->Checked)
    data->FilterOptions << foNoPartialCompare;
  else
    data->FilterOptions >> foNoPartialCompare;
}

// Add User-Entered filters into list box at runtime.
//
void __fastcall TfmFilterFrm::SBtnClearClick(TObject *Sender)
{
  Memo1->Lines->Clear();
  AnsiString st(ComboBox1->Text);
  ComboBox1->Text = "";
  if (ComboBox1->Items->IndexOf(st) == -1)
    ComboBox1->Items->Add(st);
}

// Reset the Memo field when the Filter ComboBox changes.
//
void __fastcall TfmFilterFrm::ComboBox1Change(TObject *Sender)
{
  Memo1->Lines->Clear();
  Memo1->Lines->Add(ComboBox1->Text);
}

// Close the Filter Form.
//
void __fastcall TfmFilterFrm::SBtnCloseClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
