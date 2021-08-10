//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ClientFormU.h"
#include "ClientDataModuleU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientForm *ClientForm;
//---------------------------------------------------------------------------
__fastcall TClientForm::TClientForm(TComponent* Owner)
  : TForm(Owner)
{
  try
  {
    ClientDataModule->RefreshCustomer();
  }
  catch (Exception &e)
  {
    Application->ShowException(&e);
  }
}
//---------------------------------------------------------------------------
void __fastcall TClientForm::ExitActionExecute(TObject *Sender)
{
  Application->Terminate();
}

void __fastcall TClientForm::ActionApplyUpdate(TObject *Sender)
{
  ActionApply->Enabled =
    ClientDataModule->Connected &&
    (ClientDataModule->CustomerDataSet->ChangeCount != 0);
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::ActionApplyExecute(TObject *Sender)
{
  ClientDataModule->ApplyCustomerChanges();

}
//---------------------------------------------------------------------------

void __fastcall TClientForm::ActionRefreshExecute(TObject *Sender)
{
  ClientDataModule->DiscardCustomerChanges();
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::ActionRefreshUpdate(TObject *Sender)
{
  ActionRefresh->Enabled = True;
}
//---------------------------------------------------------------------------



