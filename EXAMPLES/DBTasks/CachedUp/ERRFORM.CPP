//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "errform.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TUpdateErrorForm *UpdateErrorForm;
//---------------------------------------------------------------------------
__fastcall TUpdateErrorForm::TUpdateErrorForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// This method handles the error by displaying a dialog with information about
//  the error and then allowing the user to decide what course of action to take

TUpdateAction __fastcall TUpdateErrorForm::HandleError(TDataSet *DataSet,
            EDatabaseError *E, TUpdateKind UpdateKind)
{
   AnsiString UpdateKindStr[] = {"Modified", "Inserted", "Deleted"};

   // Put the error context information into the labels on the form
   UpdateType->Caption = UpdateKindStr[UpdateKind];
   ErrorText->Caption = E->Message;
   // Fill the string grid with the update field values
   GetFieldValues(DataSet);
   ShowModal();
   switch (ModalResult)
   {
      case mrRetry:
      {
          // If user wants to retry, then put any changed values from the
          //  string grid back into the associated field's NewValue property
          SetFieldValues(DataSet);
          return uaRetry;
      }
      case mrIgnore:
         return uaSkip;
      default:
         return uaAbort;
   }
}
//---------------------------------------------------------------------------
void __fastcall TUpdateErrorForm::GetFieldValues(TDataSet *DataSet)
{
   int      I;
   TField   *F;

   // Create a list of the data fields in the dataset, and store them in
   //  a stringlist which we can use to determine which values the user
   //  has edited

   FDataFields->Clear();
   for (I = 0; I <= DataSet->FieldCount - 1; I++)
      if (DataSet->Fields->Fields[I]->FieldKind == fkData)
         FDataFields->AddObject("", DataSet->Fields->Fields[I]);

   // Now fill up the string grid with the Old and New values of each field.
   // OldValue and NewValue are public properties of TDataSet which are used
   // from within the OnUpdateError event handler to determine what data a
   // user has updated.  We use the VarToStr RTL function to ensure that null
   // fields are displayed as blank strings

   UpdateData->RowCount = FDataFields->Count + 1;
   for (I = 0; I <= FDataFields->Count - 1; I++)
   {
      F = (TField*)FDataFields->Objects[I];
      UpdateData->Cells[0][I + 1] = VarToStr(F->NewValue);
      UpdateData->Cells[1][I + 1] = VarToStr(F->OldValue);
   }
}
//---------------------------------------------------------------------------
void __fastcall TUpdateErrorForm::SetFieldValues(TDataSet *DataSet)
{
   int      I;
   TField   *F;

   for (I = 0; I <= DataSet->FieldCount - 1; I++)
   // We set the string in the data field list to '*' for any fields the
   //   user edited in the string grid.  Those are the only fields we need
   //   to write back into the associated TField's NewValue property
      if (CompareText(FDataFields->Strings[I], "*") == 0)
      {
         F = (TField*)FDataFields->Objects[I];
         F->NewValue = UpdateData->Cells[0][I + 1];
      }
}
// Event handlers
//---------------------------------------------------------------------
void __fastcall TUpdateErrorForm::FormCreate(TObject *Sender)
{
   FDataFields = new TStringList();
   // Fill in the titles of the string grid
   UpdateData->Cells[0][0] = "New Value";
   UpdateData->Cells[1][0] = "Old Value";

}
//---------------------------------------------------------------------
void __fastcall TUpdateErrorForm::FormDestroy(TObject *Sender)
{
   delete FDataFields;
}
//---------------------------------------------------------------------
void __fastcall TUpdateErrorForm::UpdateDataSetEditText(TObject *Sender,
      int ACol, int ARow, const AnsiString Value)
{
   // Set a flag in the list of datafields indicating that this value
   // was changed.
   FDataFields->Strings[ARow - 1] = "*";

}
//---------------------------------------------------------------------

