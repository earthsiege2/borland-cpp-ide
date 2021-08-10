//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MDClntDM.h"
#include "MDSrvr_TLB.h"
#include "recerror.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#define sErrorOpeningServer "Error opening table"
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::ApplyUpdates(void)
{
  if (Project->ChangeCount > 0)
    Project->ApplyUpdates(-1);
  if (EmpProj->ChangeCount > 0)
    EmpProj->ApplyUpdates(-1);
  if (Employee->ChangeCount > 0)
    Employee->ApplyUpdates(-1);
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::ProjectReconcileError(
      TClientDataSet *DataSet, EReconcileError *E, TUpdateKind UpdateKind,
      TReconcileAction &Action)
{
//  Action = HandleReconcileError(Owner, DataSet, UpdateKind, E);
  ShowMessage(E->Message);
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::DataModuleCreate(TObject *Sender)
{
  try
  {
    Project->Open();
    EmpProj->Open();
    Employee->Open();
  }
  catch (...)
  {
    throw Exception(sErrorOpeningServer);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::ProjectNewRecord(TDataSet *DataSet)
{
  AnsiString Value;

  if (InputQuery("Project ID", "Please enter project Identifier", Value))
  {
    if (Value.Length() != 5)
    {
      ShowMessage("Project ID must be 5 characters");
      DataSet->Cancel();
      Abort();
    }
    else
      DataSet->FieldByName("PROJ_ID")->AsString = Value.UpperCase();
  }
  else
    Abort();
}
//---------------------------------------------------------------------------


