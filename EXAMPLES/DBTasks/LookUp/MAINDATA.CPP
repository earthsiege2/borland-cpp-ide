//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "maindata.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TDMMain *DMMain;
//---------------------------------------------------------------------------
__fastcall TDMMain::TDMMain(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMMain::tbOrdersCalcFields(TDataSet *DataSet)
{
   if (tbOrdersEmployeeFirstName->IsNull)
      tbOrdersEmployeeFullName->Value = tbOrdersEmployeeLastName->Value;
   else
      tbOrdersEmployeeFullName->Value = tbOrdersEmployeeFirstName->Value + ' ' +
      tbOrdersEmployeeLastName->Value;

}
//---------------------------------------------------------------------