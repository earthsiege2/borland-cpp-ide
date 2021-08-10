//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "brparts.h"
#include "Datamod.h"
#include "edparts.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TBrPartsForm *BrPartsForm;
//---------------------------------------------------------------------------
__fastcall TBrPartsForm::TBrPartsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
double TBrPartsForm::GetPartNo()
{
  return MastData->PartsSource->DataSet->Fields->Fields[0]->AsFloat;
}
//---------------------------------------------------------------------------
void TBrPartsForm::SetPartNo(double NewPartNo)
{
  TLocateOptions flags;
  MastData->PartsSource->DataSet = MastData->Parts;
  MastData->Parts->Locate("PartNo", NewPartNo, flags);
}
//---------------------------------------------------------------------------
void __fastcall TBrPartsForm::EditBtnClick(TObject *Sender)
{
  if (ActivateBtn->Down)
  {
    EdPartsForm->Edit(MastData->PartsQueryPartNo->Value);
    MastData->PartsQuery->Close();
    MastData->PartsQuery->Open();
  }
  else
    EdPartsForm->Edit(MastData->PartsPartNo->Value);

}
//---------------------------------------------------------------------------
void __fastcall TBrPartsForm::CloseBtnClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TBrPartsForm::ActivateQuery(TObject *Sender)
{
  if (!ActivateBtn->Down)
    MastData->PartsSource->DataSet = MastData->Parts;
  else
    try
    {
      MastData->PartsQuery->Close();
      MastData->PartsQuery->Open();
      MastData->PartsSource->DataSet = MastData->PartsQuery;
    }
    catch(...)
    {
      MastData->PartsSource->DataSet = MastData->Parts;
    }
  PartsGrid->Update();
}
//---------------------------------------------------------------------------
void __fastcall TBrPartsForm::FormShow(TObject *Sender)
{
  MastData->Parts->Open();
}
//---------------------------------------------------------------------------
