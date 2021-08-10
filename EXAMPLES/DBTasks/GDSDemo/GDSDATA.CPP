//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GdsData.h"
//---------------------------------------------------------------------------
#pragma link "gdsstd"
#pragma resource "*.dfm"
TStdDataForm *StdDataForm;
//---------------------------------------------------------------------------
__fastcall TStdDataForm::TStdDataForm(TComponent* Owner)
  : TGDSStdForm(Owner)
{
  Cust->Open();
  Orders->Open();
}
//---------------------------------------------------------------------------
void __fastcall TStdDataForm::FormCreate(TObject *Sender)
{
  FLastDate = EncodeDate(1995, 1, 1);
  FLastAmount = 1000;
  FilterOnRadioGroup->ItemIndex = 0;
}

/* Calculate the value of AmountDue. Used in the OnCalcFields
  and OnFilterRecord event handlers. */

double __fastcall TStdDataForm::CalcAmountDue(void)
{
  return OrdersItemsTotal->Value * (1.0 + OrdersTaxRate->Value / 100) +
    OrdersFreight->Value - OrdersAmountPaid->Value;
}

//---------------------------------------------------------------------
void __fastcall TStdDataForm::FilterOnRadioGroupClick(TObject *Sender)
{
   FilterOnLabel->Caption =
     FilterOnRadioGroup->Items->Strings[FilterOnRadioGroup->ItemIndex];
   switch (FilterOnRadioGroup->ItemIndex)
     {
     case 0:
          Orders->OnFilterRecord = OrdersFilterOnDate;
          FilterCriteria->Text = AnsiString(FLastDate);
        break;
     case 1:
          Orders->OnFilterRecord = OrdersFilterOnAmount;
          FilterCriteria->Text = AnsiString(FLastAmount);
        break;
     }
   ActiveControl = FilterCriteria;

  if (Orders->Filtered)
    Orders->Refresh();
}

/* Convert the FilterCriteria text into a Date or Float.  This value
  will be used in the OnFilterRecord callback instead of using the
  FilterCriteria directly, so that the string does not need to be
  converted each time the event is triggered. */

void __fastcall TStdDataForm::ConvertFilterCriteria(void)
{
  if (FilterCriteria->Text != "")
  	 {
    switch (FilterOnRadioGroup->ItemIndex)
      {
      case 0:
      		FLastDate = StrToDate(FilterCriteria->Text);
      		break;
      case 1:
      		FLastAmount = StrToFloat(FilterCriteria->Text);
      		break;
      }
    }
  if (Orders->Filtered) Orders->Refresh();
}

//---------------------------------------------------------------------
void __fastcall TStdDataForm::FilterCriteriaExit(TObject *Sender)
{
  ConvertFilterCriteria();
}
//---------------------------------------------------------------------
void __fastcall TStdDataForm::FilterCriteriaKeyPress(TObject *Sender,
      Char &Key)
{
  if (Key == 0x13)
  {
    ConvertFilterCriteria();
    Key = 0x00;
  }
}

/* Calculate this order's total on the fly. Include in the dataset
  if its amount is greater than or equal to the specified filter
  criteria. Note that calculated and lookup fields are undefined
  in an OnFilterRecord event handler. */                   
void __fastcall TStdDataForm::OrdersFilterOnAmount(TDataSet * DataSet, bool & Accept)
{
  Accept = (CalcAmountDue() >= FLastAmount);
}

/* Include this order in the dataset if its date is greater
  than or equal to the specified filter criteria. */
void __fastcall TStdDataForm::OrdersFilterOnDate(TDataSet * DataSet, bool & Accept)
{
  Accept = (OrdersSaleDate->Value >= FLastDate);
}

void __fastcall TStdDataForm::OrdersCalcFields(TDataSet * DataSet)
{
  OrdersTaxAmount->Value = OrdersItemsTotal->Value * (OrdersTaxRate->Value / 100);
  OrdersAmountDue->Value = CalcAmountDue();
}

//---------------------------------------------------------------------
void __fastcall TStdDataForm::FilterCheckBoxClick(TObject *Sender)
{
  ConvertFilterCriteria();
  Orders->Filtered = FilterCheckBox->Checked;
  NextBtn->Enabled = ! FilterCheckBox->Checked;
  PriorBtn->Enabled = ! FilterCheckBox->Checked;
}
//---------------------------------------------------------------------
void __fastcall TStdDataForm::NextBtnClick(TObject *Sender)
{
  ConvertFilterCriteria();
  Orders->FindNext();
}
//---------------------------------------------------------------------
void __fastcall TStdDataForm::PriorBtnClick(TObject *Sender)
{
  ConvertFilterCriteria();
  Orders->FindPrior();
}
//---------------------------------------------------------------------

