//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// This program demonstrates using TClientDataSet in a distributed data
// application.  The data comes from a separate OLE Automation server,
// so before running this project you must compile and run the EmpEdit
// Srvr project.
//
#include <vcl.h>
#pragma hdrstop

#include "EmpForm.h"
#include "RECERROR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEmployeeForm *EmployeeForm;
//---------------------------------------------------------------------------
__fastcall TEmployeeForm::TEmployeeForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEmployeeForm::QueryButtonClick(TObject *Sender)
{
  // Get data from the server.  The number of records returned is dependent on
  // the PacketRecords property of TClientDataSet.  If PackeRecords is set
  // to -1, then all records are returned.  Otherwise, as the user scrolls
  // through the data, additional records are returned in separate data packets.
  //

  Employees->Close();
  Employees->Open();        
}
//---------------------------------------------------------------------------
void __fastcall TEmployeeForm::UpdateButtonClick(TObject *Sender)
{
  // Apply any edits.  The parameter indicates the number of errors which
  // are allowed before the updating is aborted.  A value of -1 indicates that
  // all successful updates be applied regardless of the number of errors.
  //

  Employees->ApplyUpdates(-1);        
}
//---------------------------------------------------------------------------
void __fastcall TEmployeeForm::UndoButtonClick(TObject *Sender)
{
  // Here we demonstrate a new feature in TClientDataSet, the ability to undo
  // changes in reverse order.  The parameter indicates if the cursor should
  // be repositioned to the record associated with the change.
  //

  Employees->UndoLastChange(true);
}
//---------------------------------------------------------------------------
void __fastcall TEmployeeForm::EmpDataDataChange(TObject *Sender,
      TField *Field)
{
  // This code is used to update the status bar to show the number of records
  // that have been retrieved and our relative position with the dataset.
  //

  if( Employees->Active )
    StatusBar1->Panels->Items[1]->Text = Format(" %d of %d ", ARRAYOFCONST((Employees->RecNo, Employees->RecordCount)) );
}
//---------------------------------------------------------------------------

void __fastcall TEmployeeForm::EmployeesReconcileError(
      TClientDataSet *DataSet, EReconcileError *E, TUpdateKind UpdateKind,
      TReconcileAction &Action)
{
  // This is the event handler which is called when there are errors during the
  // update process.  To demonstrate, you can create an error by running two
  // copies of this application and modifying the same record in each one.
  // Here we use the standard reconcile error dialog from the object repository.
  //

  Action = HandleReconcileError(Owner, DataSet, UpdateKind, E);
}
//---------------------------------------------------------------------------
 