//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "datamod.h"
#include "errform.h"
#include "cachedup.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TCacheData *CacheData;
//---------------------------------------------------------------------------
__fastcall TCacheData::TCacheData(TComponent* Owner)
  : TDataModule(Owner)
{
  CacheDemoForm->SetDataSet(CacheData->CacheDS->DataSet);
}
//---------------------------------------------------------------------
// This event is triggered when an error occurs during the update process
//  (such as a key violation).  Here we use another form to show the user
//  the error and allow them to decide what to do about it.  See ErrForm.cpp
//  for more information
void __fastcall TCacheData::UpdateErrorHandler(TDataSet *DataSet,
      EDatabaseError *E, TUpdateKind UpdateKind,
      TUpdateAction &UpdateAction)
{
   UpdateAction = UpdateErrorForm->HandleError(DataSet, E, UpdateKind);
}
//---------------------------------------------------------------------
// This event displays the current update status in a calculated field
void __fastcall TCacheData::CacheQueryCalcFields(TDataSet *DataSet)
{
   AnsiString UpdateStatusStr[] = {"Unmodified", "Modified", "Inserted", "Deleted"};

  if (CacheQuery->CachedUpdates)
    CacheQueryUpdateStatus->Value = UpdateStatusStr[CacheQuery->UpdateStatus()];
}
//---------------------------------------------------------------------
