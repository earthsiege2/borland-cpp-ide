//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "edparts.h"
#include "Datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TEdPartsForm *EdPartsForm;
//---------------------------------------------------------------------------
__fastcall TEdPartsForm::TEdPartsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TEdPartsForm::Edit(Double PartNo)
{
  TLocateOptions flags;
  MastData->Parts->Open();
  MastData->Parts->Locate("PartNo", PartNo, flags);
  ShowModal();
}

void __fastcall TEdPartsForm::PrintBtnClick(TObject *Sender)
{
  if ( MessageBox(Handle,"  Print this form?","Confirmation",MB_YESNO) )
     Print();
}
//---------------------------------------------------------------------------

void __fastcall TEdPartsForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  CanClose = MastData->DataSetApplyUpdates(MastData->Parts, ModalResult==mrOk);
}
//---------------------------------------------------------------------------
