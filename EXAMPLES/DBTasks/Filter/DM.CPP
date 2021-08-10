//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DM.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDM1::TDM1(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

TDM1* DM1;

void __fastcall TDM1::DM1Create(TObject *Sender)
{
  try {
    Screen->Cursor = TCursor(crHourGlass);
    SQLCustomer->Open();
  }
  catch (...) {}  // dummy catch block to guarantee we get here.
  Screen->Cursor = TCursor(crDefault);
}

// This is only called if the Filtered property is True, set
//  dynamically by the CheckBox on the CustView form. 
//
void __fastcall TDM1::SQLOrdersFilterRecord(TDataSet *DataSet, bool &Accept)
{
  Accept = SQLOrdersAmountPaid->Value >= OrdersFilterAmount;
}

