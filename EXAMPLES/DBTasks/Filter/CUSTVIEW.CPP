//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CustView.h"
#include "DM.h"
#include "Filter1.h"
#include "About.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TfmCustView::TfmCustView(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

TfmCustView* fmCustView;

// Change the DataSet for the Customer from Query to Table,
// or Table to Query. If a filter is current, set that filter
// to the just-changed DataSet.
//
void __fastcall TfmCustView::rgDataSetClick(TObject *Sender)
{
  TDataSource *src(DM1->CustomerSource);
  AnsiString st;

  // Is the other DataSet Filtered? If so, get its filter.
  if (src->DataSet->Filtered)
    st = src->DataSet->Filter;

  if (rgDataSet->ItemIndex) {
      if (src->DataSet != DM1->Customer)
        src->DataSet = DM1->Customer;
  }
  else {
      if (src->DataSet != DM1->SQLCustomer)
        src->DataSet = DM1->SQLCustomer;
  }

  // Set the Filter of the current DataSet.
  if (st != "") {
    src->DataSet->Filter = st;
    src->DataSet->Filtered = true;
  }
}

void __fastcall TfmCustView::SpeedButton1Click(TObject *Sender)
{
  fmFilterFrm->Show();
}

// DM1->SQLOrders->Filtered will be true if the box is checked.
//
void __fastcall TfmCustView::cbFilterOrdersClick(TObject *Sender)
{
  DM1->SQLOrders->Filtered = cbFilterOrders->Checked;

  // If the number changed while the box is unchecked, DM1->OrdersFilterAmount
  // won't know about it.  The Edit1Change procedure will set the value and
  // apply the filter.
  if (cbFilterOrders->Checked)
    Edit1Change(NULL); // ...to make sure the value is set.
}

void __fastcall TfmCustView::About1Click(TObject *Sender)
{
  TfmAboutBox* fmAboutBox(new TfmAboutBox(this));
  fmAboutBox->ShowModal();
  delete fmAboutBox;
}

void __fastcall TfmCustView::Edit1Change(TObject *Sender)
{
  // We must insure that Edit1->Text is not blank, or an exception will
  // be thrown when the user clears the contents of the Edit.

  if (cbFilterOrders->Checked && Edit1->Text != "") {
    try {
      // Attempt to set the variable on DM1 that holds the filter amount.
      DM1->OrdersFilterAmount = StrToFloat(fmCustView->Edit1->Text);

      // Refreshing SQLOrders will cause DM1->SQLOrdersFilterRecord to be
      // called once for each orders record for the current Customer. 
      DM1->SQLOrders->Refresh();
    }
    catch (EConvertError* exc) {
        // This happens before DM1->SQLOrders->Refresh() if the user typed in a
        // non-numeric value, thus preventing it from trying to use an invalid
        // value to filter itself, which would raise an exception once for
        // each record displayed.
        throw Exception("Threshold Amount must be a number.");
    }
  }
}

// Set the navigator to the Customer Datasource. 
//
void __fastcall TfmCustView::DBGrid1Enter(TObject *Sender)
{
  DBNavigator1->DataSource = DBGrid1->DataSource;
}

//  Set the navigator to the Orders Datasource.
//
void __fastcall TfmCustView::DBGrid2Enter(TObject *Sender)
{
  DBNavigator1->DataSource = DBGrid2->DataSource;
}
