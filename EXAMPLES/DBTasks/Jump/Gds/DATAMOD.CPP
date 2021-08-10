//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DataMod.h"
#include "TermMod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TData *Data;
//---------------------------------------------------------------------------
__fastcall TData::TData(TComponent* Owner)
  : TCustomerData(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TData::CustomersFilterRecord(TDataSet *DataSet,
      bool &Accept)
{
  Accept = (CustomersState->Value == Cust->FilterText->Text);  
}
//---------------------------------------------------------------------
void __fastcall TData::OrdersFilterRecord(TDataSet *DataSet,
      bool &Accept)
{
  Accept = (OrdersTerms->Value == Term->FilterText->Text);  
}
//---------------------------------------------------------------------