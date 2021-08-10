//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "edorders.h"
#include "Datamod.h"
#include "srchdlg.h"
#include "pickdate.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TEdOrderForm *EdOrderForm;
const char * DataSetStates[]={"Not active", "Browsing", "Editing", "Inserting", "", "", "", "", ""};
const int HelpTopicEdit = 2;
const int HelpTopicBrowse = 3;
//---------------------------------------------------------------------------
__fastcall TEdOrderForm::TEdOrderForm(TComponent* Owner)
	: TForm(Owner)
{
}

void TEdOrderForm::Enter()
{
  MastData->OrdersSource->OnStateChange = OrdersSourceStateChange;
  try
  {
    MastData->Orders->Open();
    MastData->Orders->Insert();
    ShowModal();
  }
  catch(...)  {
    MastData->OrdersSource->OnStateChange = NULL;
    return;
  }
  MastData->OrdersSource->OnStateChange = NULL;
}

void TEdOrderForm::Edit(double OrderNo)
{
  MastData->OrdersSource->OnStateChange = OrdersSourceStateChange;
  try
  {
    TLocateOptions  flags;
    MastData->Orders->Open();
    MastData->Orders->Locate("OrderNo", OrderNo, flags);
    ShowModal();
  }
  catch (...)
  {
      MastData->OrdersSource->OnStateChange = NULL;
      return;
  }
  MastData->OrdersSource->OnStateChange = NULL;
}


//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::ItemsGridEnter(TObject *Sender)
{
  ActiveSource->DataSet = MastData->Items;
}
//---------------------------------------------------------------------------
// Update the mode indicator when the state of the "Active" datasource
// (Orders or Items) changes.
void __fastcall TEdOrderForm::ActiveSourceStateChange(TObject *Sender)
{
 // with ActiveSource do
    if (ActiveSource->DataSet != NULL)
    {
      char MIcaption[80];
      sprintf(MIcaption,"%s: %s",ActiveSource->DataSet->Name.c_str(),DataSetStates[ActiveSource->State]);
      ModeIndicator->Caption=AnsiString(MIcaption);
    }
    if (ActiveSource->State==dsEdit || ActiveSource->State==dsInsert || ActiveSource->State==dsSetKey)
    {
      HelpContext = HelpTopicEdit;
      ModeIndicator->Font->Color = clRed;
    }
    else
    {
      HelpContext = HelpTopicBrowse;
      ModeIndicator->Font->Color = clBlue;
    }
}
//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::ItemsGridExit(TObject *Sender)
{
  ActiveSource->DataSet = MastData->Orders;
}
//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::CancelBtnClick(TObject *Sender)
{
  MastData->OrdersAfterCancel(MastData->Orders);
}
//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::PostBtnClick(TObject *Sender)
{
  MastData->Orders->Post();
}
//---------------------------------------------------------------------------
// Clicking on the PartNo button in the grid brings up PickPartNo dialog
void __fastcall TEdOrderForm::PickPartNo(TObject *Sender)
{
  if (ItemsGrid->SelectedField == MastData->ItemsPartNo) //PartNo column only
  {
    if (MastData->ItemsPartNo->Value)
      SearchDlg->PartNo = MastData->ItemsPartNo->Value;	 //start with current PartNo
    if (SearchDlg->ShowModalParts() == mrOk)
    {
      MastData->Items->Edit();
      MastData->ItemsPartNo->Value = SearchDlg->PartNo;
    }
  }
}
//---------------------------------------------------------------------------
// Browse a calendar to pick an invoice date
void __fastcall TEdOrderForm::PickDate(TObject *Sender)
{
  BrDateForm->Date = MastData->OrdersSaleDate->Value; 	//start with current date
  if (BrDateForm->ShowModal() == mrOk)
  {
    MastData->Orders->Edit();
    MastData->OrdersSaleDate->Value = BrDateForm->Date;
    SaleDateEdit->SelectAll();
  }
}
//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::PrintBtnClick(TObject *Sender)
{
  if(Confirm("Print image of this form window?"))
    Print();
}
//---------------------------------------------------------------------------
// Enable or disable buttons as needed when the state of the orders table changes
void __fastcall TEdOrderForm::OrdersSourceStateChange(TObject * Sender)
{
  PostBtn->Enabled   = ((MastData->Orders->State==dsEdit) ||
                        (MastData->Orders->State==dsInsert) ||
								(MastData->Orders->State==dsSetKey));
  CancelBtn->Enabled = PostBtn->Enabled;
  CloseBtn->Enabled  = (MastData->Orders->State==dsBrowse);
}
//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  CanClose = MastData->DataSetApplyUpdates(MastData->Orders, ModalResult == mrOk);
}
//---------------------------------------------------------------------------
void __fastcall TEdOrderForm::SoldByComboKeyPress(TObject *Sender, char &Key)
{
  if (!((int)Key==13 || (int)Key==27))
    Key = '0';
}
//---------------------------------------------------------------------------

