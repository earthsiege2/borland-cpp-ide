//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClientDataModuleU.h"
#include "Any2Variant.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientDataModule *ClientDataModule;
//---------------------------------------------------------------------------
__fastcall TClientDataModule::TClientDataModule(TComponent* Owner)
  : TDataModule(Owner)
{
}

bool __fastcall TClientDataModule::GetConnected()
{
  return (FAppServer != NULL);

}
//---------------------------------------------------------------------------


CBuilder::Customers_ptr __fastcall TClientDataModule::GetAppServer(void)
{
  if (FAppServer == NULL)
  {
     FAppServer = CBuilder::Customers::_bind();
  }
  return FAppServer;
}

void __fastcall TClientDataModule::SetAppServer(CBuilder::Customers_ptr _ptr)
{
  FAppServer = _ptr;
}

void __fastcall TClientDataModule::ApplyCustomerChanges()
{
  try
  {
    long ErrorCount;

    CORBA::Any_var anyDelta = SAFEARRAYToAny(CustomerDataSet->Delta);
    CORBA::Any_var anyErrors = AppServer->ApplyCustomerUpdates(
      anyDelta, ErrorCount);
    OleVariant varErrors = AnyToSAFEARRAY(anyErrors);
    CustomerDataSet->Reconcile(varErrors);
  }
  catch (const CBuilder::Customers::CustomerException &e)
  {
     throw Sysutils::Exception(AnsiString(e.s));
  }
  catch (const CORBA_Exception & e)
  {
     throw Sysutils::Exception(e._name());
  }
}

void __fastcall TClientDataModule::DiscardCustomerChanges()
{
  CustomerDataSet->Close();
  RefreshCustomer();
}

void __fastcall TClientDataModule::RefreshCustomer()
{
  try
  {
    CORBA::Any_var anyData = AppServer->GetCustomers(! CustomerDataSet->Active);
    OleVariant varData = AnyToSAFEARRAY(anyData);
    CustomerDataSet->Data = varData;
  }
  catch (const CBuilder::Customers::CustomerException &e)
  {
     throw Sysutils::Exception(AnsiString(e.s));
  }
  catch (const CORBA_Exception & e)
  {
     throw Sysutils::Exception(e._name());
  }

}

