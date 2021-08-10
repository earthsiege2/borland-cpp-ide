//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "cachedup.h"
#include "datamod.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TCacheDemoForm *CacheDemoForm;
//---------------------------------------------------------------------------
__fastcall TCacheDemoForm::TCacheDemoForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCacheDemoForm::SetDataSet(TDataSet* DataSet)
{
   FDataSet = dynamic_cast<TDBDataSet *>(DataSet);
   FDataSet->CachedUpdates = CachedUpdates->Checked;
   SetControlStates(FDataSet->CachedUpdates);
   FDataSet->Open();
}
//---------------------------------------------------------------------------
void __fastcall TCacheDemoForm::SetControlStates(BOOL Enabled)
{
   ApplyUpdatesBtn->Enabled = Enabled;
   CancelUpdatesBtn->Enabled = Enabled;
   RevertRecordBtn->Enabled = Enabled;
   UnModifiedCB->Enabled = Enabled;
   ModifiedCB->Enabled = Enabled;
   InsertedCB->Enabled = Enabled;
   DeletedCB->Enabled = Enabled;
   UseUpdateSQL->Enabled = Enabled;
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::ReExecuteButtonClick(TObject *Sender)
{
   FDataSet->Close();
   FDataSet->Open();
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::ToggleUpdateMode(TObject *Sender)
{
   // Toggle the state of the CachedUpdates property
   FDataSet->CachedUpdates =! FDataSet->CachedUpdates;
   // Enable/Disable Controls
   SetControlStates(FDataSet->CachedUpdates);
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::UseUpdateSQLClick(TObject *Sender)
{
   FDataSet->Close();
   if (UseUpdateSQL->Checked)
      FDataSet->UpdateObject = CacheData->UpdateSQL;
   else
      FDataSet->UpdateObject = NULL;
   FDataSet->Open();
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::ApplyUpdatesBtnClick(TObject *Sender)
{
   FDataSet->Database->ApplyUpdates(OPENARRAY(TDBDataSet*, (FDataSet)));
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::CancelUpdatesBtnClick(TObject *Sender)
{
   FDataSet->CancelUpdates();
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::RevertRecordBtnClick(TObject *Sender)
{
   FDataSet->RevertRecord();  
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::UpdateRecordsToShow(TObject *Sender)
{
   TUpdateRecordTypes UpdRecTypes;

   UpdRecTypes.Clear();
   if (UnModifiedCB->Checked)
      UpdRecTypes << rtUnmodified;
   if (ModifiedCB->Checked)
      UpdRecTypes << rtModified;
   if (InsertedCB->Checked)
      UpdRecTypes << rtInserted;
   if (DeletedCB->Checked)
      UpdRecTypes << rtDeleted;
   FDataSet->UpdateRecordTypes = UpdRecTypes;
}
//---------------------------------------------------------------------
void __fastcall TCacheDemoForm::miAboutClick(TObject *Sender)
{
  ShowAboutDialog();  
}
//---------------------------------------------------------------------
