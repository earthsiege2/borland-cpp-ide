//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "edcust.h"
#include "Datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TEdCustForm *EdCustForm;
//---------------------------------------------------------------------------
__fastcall TEdCustForm::TEdCustForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEdCustForm::PrintBtnClick(TObject *Sender)
{
  if(MessageBox(Handle,"   Print this form?", "Confirmation",MB_YESNO)==IDYES)
    Print();
}
//---------------------------------------------------------------------------
void __fastcall TEdCustForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  CanClose = MastData->DataSetApplyUpdates(MastData->Cust, ModalResult==mrOk);
}
//---------------------------------------------------------------------------
void TEdCustForm::Edit(double CustNo)
{
  Set<TLocateOption,0,1>flags;
  MastData->Cust->Open();
  MastData->Cust->Locate("CustNo", CustNo, flags);
  ShowModal();
}
