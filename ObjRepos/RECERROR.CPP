//---------------------------------------------------------------------------
//
//  C++Builder Visual Component Library
//  ClientDataSet Standard Reconcile Error Dialog
//
//  Copyright (c) 1999 Borland International
//
//---------------------------------------------------------------------------
// To use this dialog you should add a call to HandleReconcileError in
// the OnReconcileError event handler of TClientDataSet.  Cut and paste the
// following line into the event handler:
//
// Action = HandleReconcileError(Owner, DataSet, UpdateKind, E);
//

#include <stdio.h>
#include <vcl.h>
#pragma hdrstop

#include "recerror.h"

//---------------------------------------------------------------------------

#pragma resource "*.dfm"

char *ActionStr[] = {"Skip", "Abort", "Merge",
		     "Correct", "Cancel", "Refresh"};
char *UpdateKindStr[] = {"Modified", "Inserted", "Deleted"};
char *SCaption = "Update Error - ";
char *SUnchanged = "<Unchanged>";
char *SBinary = "(Binary)";
char *SFieldName = "Field Name";
char *SOriginal = "Original Value";
char *SConflict = "Conflicting Value";
char *SValue = " Value";
char *SNoData = "<No Records>";
char *SNew = "New";

//---------------------------------------------------------------------------
TReconcileErrorForm *ReconcileErrorForm;
TFieldData *PFieldData;

//---------------------------------------------------------------------------
// Public and Private Methods
//---------------------------------------------------------------------------

TReconcileAction HandleReconcileError(TComponent* Owner, TDataSet *DataSet,
  TUpdateKind UpdateKind, EReconcileError *ReconcileError) {

  TReconcileAction      retVal;
  TReconcileErrorForm  *UpdateForm;

  UpdateForm = new TReconcileErrorForm (Owner, DataSet, UpdateKind, ReconcileError);
  try {
    if (UpdateForm->ShowModal() == mrOk) {
      retVal = (TReconcileAction) (UpdateForm->ActionGroup->Items->Objects[UpdateForm->ActionGroup->ItemIndex]);
      if (retVal == raCorrect)
	UpdateForm->SetFieldValues(DataSet);
    } else
      retVal = raAbort;
  } __finally {
    delete UpdateForm;
  }
  return retVal;
}

//---------------------------------------------------------------------------

// Routine to convert a variant value into a string.
// Handles binary field types and "empty" (Unchanged) field values specially

AnsiString VarToAnsiStr (Variant &V, TFieldType DataType) {
  try {
    if (VarIsEmpty(V))
      return SUnchanged;
    else {
      switch (DataType) {
	case ftBytes:
	case ftVarBytes:
	case ftBlob:
	// ftGraphic .. ftCursor
	case ftGraphic:
	case ftFmtMemo:
	case ftParadoxOle:
	case ftDBaseOle:
	case ftTypedBinary:
	case ftCursor:
	  return SBinary;
	default:
	  return VarToStr(V);
      }
    }
  } catch (Exception &e) {
    return e.Message;
  }
}

//---------------------------------------------------------------------------

__fastcall TReconcileErrorForm::TReconcileErrorForm(TComponent* Owner) :
  TForm(Owner) {
  FDataSet = NULL;
  FDataFields = NULL;
}

//---------------------------------------------------------------------------

__fastcall TReconcileErrorForm::TReconcileErrorForm(TComponent* Owner,
  TDataSet *DataSet, TUpdateKind UpdateKind, EReconcileError *Error) : TForm(Owner) {
  FDataFields = NULL;
  FDataSet = DataSet;
  FUpdateKind = UpdateKind;
  FError = Error;
}

//---------------------------------------------------------------------------

//__fastcall ~TReconcileErrorForm(TComponent* Owner) {
//}

//---------------------------------------------------------------------------

// Create a list of the data fields in the dataset, and store string values
// associated with NewValue, OldValue, and Curvalue in string variables
// to make display switching faster

void __fastcall TReconcileErrorForm::InitDataFields() {

  int         i;
  bool        HasCurValues;
  TFieldData *FD;
  TField     *ds;

  HasCurValues = false;
  for(i = 0; i < FDataSet->FieldCount; i++) {
    ds = FDataSet->Fields->Fields[i];
    if (ds->FieldKind != fkData)
      continue;
    FD = new TFieldData;
    try {
      FD->Field = ds;
      FD->Edited = false;
      if (FUpdateKind != ukDelete)
	FD->NewValue = VarToAnsiStr(ds->NewValue, ds->DataType);
      if (!VarIsEmpty(ds->CurValue))
        HasCurValues = true;
      FD->CurValue = VarToAnsiStr(ds->CurValue, ds->DataType);
      if (FUpdateKind != ukInsert)
	FD->OldValue = VarToAnsiStr(ds->OldValue, ds->DataType);
      FDataFields->Add(FD);
    } catch (Exception &e) {
      delete FD;
      throw;
    }
  }
  InitUpdateData (HasCurValues);
}

//---------------------------------------------------------------------------

// Initalize the column indexes and grid titles

void __fastcall TReconcileErrorForm::InitUpdateData(bool HasCurValues) {
  int FColCount;

  FColCount = 1;
  UpdateData->ColCount = 4;
  UpdateData->Cells[0][0] = SFieldName;
  if (FUpdateKind != ukDelete) {
    FNewColIdx = FColCount;
    FColCount++;
    UpdateData->Cells[FNewColIdx][0] = UpdateKindStr[FUpdateKind] + String(SValue);
  } else {
    FOldColIdx = FColCount;
    FColCount++;
    UpdateData->Cells[FOldColIdx][0] = SOriginal;
  }
  if (HasCurValues) {
    FCurColIdx = FColCount;
    FColCount++;
    UpdateData->Cells[FCurColIdx][0] = SConflict;
  }
  if (FUpdateKind == ukModify) {
    FOldColIdx = FColCount;
    FColCount++;
    UpdateData->Cells[FOldColIdx][0] = SOriginal;
  }
  UpdateData->ColCount = FColCount;
}

//---------------------------------------------------------------------------

// Update the reconcile action radio group based on the valid reconcile actions

void __fastcall TReconcileErrorForm::AddAction(TReconcileAction Action) {
  ActionGroup->Items->AddObject(ActionStr[Action], (TObject *) Action);
}

void __fastcall TReconcileErrorForm::InitReconcileActions() {
  AddAction(raSkip);
  AddAction(raCancel);
  AddAction(raCorrect);
  if (FCurColIdx > 0) {
    AddAction(raRefresh);
    AddAction(raMerge);
  }
  ActionGroup->ItemIndex = 0;
}

//---------------------------------------------------------------------------

// Update the grid based on the current display options

void __fastcall TReconcileErrorForm::DisplayFieldValues(TObject *Sender) {

  int               i, CurRow;
  TFieldData       *fd;
  TReconcileAction  Action;

  if (!Visible)
    return;
  Action = (TReconcileAction) ActionGroup->Items->Objects[ActionGroup->ItemIndex];
  UpdateData->Col = 1;
  UpdateData->Row = 1;
  CurRow = 1;
  UpdateData->RowCount = 2;
  UpdateData->Cells[0][CurRow] = SNoData;
  for (i = 1; i < UpdateData->ColCount; i++)
    UpdateData->Cells[i][CurRow] = "";
  for (i = 0; i < FDataFields->Count; i++) {
    fd = (TFieldData *) FDataFields->Items[i];
    if (ConflictsOnly->Checked && (fd->CurValue == SUnchanged))
      continue;
    if (ChangedOnly->Checked && (fd->NewValue == SUnchanged))
      continue;
    UpdateData->RowCount = CurRow + 1;
    UpdateData->Cells[0][CurRow] = fd->Field->DisplayName;
    if (FNewColIdx > 0) {
      switch (Action) {
	case raCancel, raRefresh:
	  UpdateData->Cells[FNewColIdx][CurRow] = SUnchanged;
	  break;
	case raCorrect:
	  if (fd->Edited)
	    UpdateData->Cells[FNewColIdx][CurRow] = fd->EditValue;
	  else
	    UpdateData->Cells[FNewColIdx][CurRow] = fd->NewValue;
	  break;
	default:
	  UpdateData->Cells[FNewColIdx][CurRow] = fd->NewValue;
      }
      UpdateData->Objects[FNewColIdx][CurRow] = (TObject *) FDataFields->Items[i];
    }
    if (FCurColIdx > 0)
      UpdateData->Cells[FCurColIdx][CurRow] = fd->CurValue;
    if (FOldColIdx > 0)
      if (((Action == raMerge) || (Action == raRefresh)) && (fd->CurValue != SUnchanged))
	UpdateData->Cells[FOldColIdx][CurRow] = fd->CurValue;
      else
	UpdateData->Cells[FOldColIdx][CurRow] = fd->OldValue;
    CurRow++;
  }
  AdjustColumnWidths();
}

//---------------------------------------------------------------------------

// For fields that the user has edited, copy the changes back into the
// NewValue property of the associated field

void __fastcall TReconcileErrorForm::SetFieldValues(TDataSet *DataSet) {

  int i;
  TFieldData *fd;

  for (i = 0; i < FDataFields->Count; i++) {
    fd = (TFieldData *) FDataFields->Items[i];
    if (fd->Edited)
      fd->Field->NewValue = fd->EditValue;
  }
}

//---------------------------------------------------------------------------

void __fastcall TReconcileErrorForm::AdjustColumnWidths() {

  int NewWidth, i;
  NewWidth = (UpdateData->ClientWidth - UpdateData->ColWidths[0]) /
    (UpdateData->ColCount - 1);
  for (i = 1; i < UpdateData->ColCount; i++)
    UpdateData->ColWidths[i] = NewWidth - 1;
}

//---------------------------------------------------------------------------
// Event Handlers
//---------------------------------------------------------------------------

// Set the Edited flag in the DataField list and save the value

void __fastcall TReconcileErrorForm::UpdateDataSetEditText (TObject *Sender,
  int ACol, int ARow, const AnsiString Value) {
  ((TFieldData *) UpdateData->Objects[ACol][ARow])->EditValue = Value;
  ((TFieldData *) UpdateData->Objects[ACol][ARow])->Edited = true;
}

//---------------------------------------------------------------------------

// Enable the editing in the grid if we are on the NewValue column and the
// current reconcile action is raCorrect


void __fastcall TReconcileErrorForm::UpdateDataSelectCell(TObject *Sender, int Col, int Row,
  bool &CanSelect) {

  TReconcileAction  Action;

  Action = (TReconcileAction) ActionGroup->Items->Objects[ActionGroup->ItemIndex];
  if ((Col == FNewColIdx) && (Action == raCorrect))
    UpdateData->Options = UpdateData->Options << goEditing;
  else
    UpdateData->Options = UpdateData->Options >> goEditing;
}


/*
void __fastcall TReconcileErrorForm::FormShow(TObject *Sender) {
  // display value fields procedure
}
*/

//---------------------------------------------------------------------------

void __fastcall TReconcileErrorForm::FormDestroy(TObject *Sender) {

  int i;
  if (FDataFields != NULL) {
    for (i = 0; i < FDataFields->Count; i++)
      delete ((TFieldData *) FDataFields->Items[i]);
    delete FDataFields;
  } // if
}

//---------------------------------------------------------------------------

void __fastcall TReconcileErrorForm::FormCreate(TObject *Sender) {

  if (FDataSet == NULL)
   return;
  FDataFields = new TList;
  InitDataFields();
  Caption = SCaption + FDataSet->Name;
  UpdateType->Caption = UpdateKindStr[FUpdateKind];
  ErrorMsg->Text = FError->Message;
  if (FError->Context != "")
    ErrorMsg->Lines->Add(FError->Context);
  ConflictsOnly->Enabled = (FCurColIdx > 0);
  ConflictsOnly->Checked = ConflictsOnly->Enabled;
  ChangedOnly->Enabled = (FNewColIdx > 0);
  InitReconcileActions();
  UpdateData->DefaultRowHeight = UpdateData->Canvas->TextHeight("SQgjp") + 7;   // do not localize
}

//---------------------------------------------------------------------------

