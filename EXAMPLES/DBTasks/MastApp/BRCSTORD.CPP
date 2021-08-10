//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "brcstord.h"
#include "Datamod.h"
#include "qrycust.h"
#include "edcust.h"
#include "edorders.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TBrCustOrdForm *BrCustOrdForm;
//---------------------------------------------------------------------------
__fastcall TBrCustOrdForm::TBrCustOrdForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBrCustOrdForm::CustGridEnter(TObject *Sender)
{
  ActiveSource = MastData->CustMasterSrc;
  CustGrid->Options = CustGrid->Options << dgAlwaysShowSelection;
  OrdersGrid->Options = OrdersGrid->Options >> dgAlwaysShowSelection;
}
//---------------------------------------------------------------------------
void __fastcall TBrCustOrdForm::SetQuery(TObject *Sender)
{
  if (QueryCustDlg->ShowModal() == mrOk)
    ActivateQuery(this);
}
//---------------------------------------------------------------------------
void __fastcall TBrCustOrdForm::ActivateQuery(TObject *Sender)
{
  if (!ActivateBtn->Down)
    MastData->CustMasterSrc->DataSet = MastData->Cust;
  else
  //  with MastData.CustQuery do
    try
    {
      MastData->CustQuery->Close();
      MastData->CustQuery->Params->Items[0]->AsDateTime = QueryCustDlg->FromDate;
      MastData->CustQuery->Params->Items[1]->AsDateTime = QueryCustDlg->ToDate;
      MastData->CustQuery->Open();
      // Any records in the result set?
      if (MastData->CustQuery->Bof && MastData->CustQuery->Eof)
        return;
      MastData->CustMasterSrc->DataSet = MastData->CustQuery;
    }
    catch(...)
    {
      MastData->CustMasterSrc->DataSet = MastData->Cust;
      ActivateBtn->Down = false;
      ShowMessage("No matching records in the specified date range.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TBrCustOrdForm::EditBtnClick(TObject *Sender)
{
  TFloatField *F;
  F = static_cast<TFloatField*>(ActiveSource->DataSet->Fields->Fields[0]);
  if (ActiveSource == MastData->CustMasterSrc)
    EdCustForm->Edit(F->Value);
  else  {
    EdOrderForm->Edit(F->Value);
    ActiveSource->DataSet->Refresh();
  }
}
//---------------------------------------------------------------------------
void __fastcall TBrCustOrdForm::CloseBtnClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TBrCustOrdForm::OrdersGridEnter(TObject *Sender)
{
  ActiveSource = MastData->OrdByCustSrc;
  OrdersGrid->Options = OrdersGrid->Options << dgAlwaysShowSelection;
  CustGrid->Options = CustGrid->Options >> dgAlwaysShowSelection;
}
//---------------------------------------------------------------------------
void TBrCustOrdForm::SetActiveSource(TDataSource *DataSource)
{
  FActiveSource = DataSource;
  Navigator->DataSource = FActiveSource;
}
//---------------------------------------------------------------------------
void TBrCustOrdForm::SetCustNo(double NewCustNo)
{
  TLocateOptions flags;
  MastData->CustMasterSrc->DataSet = MastData->Cust;
  MastData->Cust->Locate("CustNo", NewCustNo, flags);
}
//---------------------------------------------------------------------------
void TBrCustOrdForm::SetOrderNo(double NewOrderNo)
{
  TLocateOptions flags;
  MastData->OrdByCust->Locate("OrderNo", NewOrderNo, flags);
}
//---------------------------------------------------------------------------
double TBrCustOrdForm::GetCustNo()
{
  return MastData->CustMasterSrc->DataSet->Fields->Fields[0]->AsFloat;
}
//---------------------------------------------------------------------------
double TBrCustOrdForm::GetOrderNo()
{
  return MastData->OrdByCustOrderNo->Value;
}
//---------------------------------------------------------------------------


void __fastcall TBrCustOrdForm::FormShow(TObject *Sender)
{
  MastData->Cust->Open();
  MastData->Cust->First();
}
//---------------------------------------------------------------------------
