//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FindCust.h"
#include "DM.h"
#include <stdlib.h>

//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TfmFindCust* fmFindCust;

//---------------------------------------------------------------------------
__fastcall TfmFindCust::TfmFindCust(TComponent* Owner)
  : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TfmFindCust::ComboBox1Change(TObject *Sender)
{
  // Make the field we're locating in the leftmost field.
  DM2->CustLookup->FieldByName(ComboBox1->Text)->Index = 0;

  // In order to use FindNearest, we have to be indexed based on the field
  // we're doing the find in.  If we're using Locate, it doesn't matter what
  // the current index is, so we will set it to company, which is the default
  // in the Customer form.
  if (ComboBox1->Text == "CustNo")
    DM2->CustLookup->IndexName = "";
  else
    DM2->CustLookup->IndexName = "ByCompany";

  // Let the user choose whether or not to use a filter if they're going to be
  // searching based on a field that has no index.
  cbUseFilter->Enabled = ComboBox1->Text != "CustNo" && ComboBox1->Text != "Company";
  if (cbUseFilter->Enabled)
    cbUseFilter->SetFocus();
  else
    Edit1->SetFocus();
  Edit1->Text = "";
}
//---------------------------------------------------------------------
void __fastcall TfmFindCust::Edit1Change(TObject *Sender)
{
  // Now, we begin to find the field, as the user types, i.e.,
  // incrementally.  FindNearest is used in the two indexed fields,
  // Company and CustNo; Locate is used for all the non-indexed
  // fields.
  if (ComboBox1->Text == "Company") {
    TVarRec q(Edit1->Text);
    DM2->CustLookup->FindNearest(&q, 0);
  }
  else if (ComboBox1->Text == "CustNo") {
    try {
      TVarRec q(_atold(Edit1->Text.c_str()));
      if (Edit1->Text != "")
        DM2->CustLookup->FindNearest(&q, 0);
    }
    catch (...) {
      throw Exception(Edit1->Text + " is not a valid customer number");
    }
  }
  else { // Some non-indexed field.

    Set<TLocateOption,0,1> flags;
    flags << loCaseInsensitive << loPartialKey;
    // Possibly apply the filter so we see only records matching this value.
    bool found;
    found = DM2->CustLookup->Locate(ComboBox1->Text,
                                    Edit1->Text,
                                    flags);

    if (found && cbUseFilter->Checked) {
      // Get an expression such as State = 'CA'.
      DM2->CustLookup->Filter = ComboBox1->Text + " = '" + Edit1->Text + "'";
      DM2->CustLookup->Filtered = true;
      if (DM2->CustLookup->RecordCount == 0) //Filter is possibly too restrictive
        DM2->CustLookup->Filter = ComboBox1->Text + " >= '" + Edit1->Text + "'";
    }
    else
      DM2->CustLookup->Filtered = false;
  }
  DM2->CustLookup->Refresh();
}
//---------------------------------------------------------------------------
