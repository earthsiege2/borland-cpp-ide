//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Implement a CORBA object that can provide and resolve a MIDAS data packet.
// The VCL TProvider component  

#include <vcl.h>
#pragma hdrstop

#include <corba.h>
#include "Any2Variant.h"
#include "CustomersImplU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
USE_STD_NS
TCustomersImpl *CustomersImpl;
//---------------------------------------------------------------------------
__fastcall TCustomersImpl::TCustomersImpl(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------



CORBA::Any* __fastcall TCustomersImpl::ApplyCustomerUpdates(const CORBA::Any& Delta,
  CORBA::Long& ErrorCount)
{
  VISMutex_var lock(_mtx); // Prevent concurrent access
  cout << "ApplyCustomerUpdates request" << endl;
  try
  {
    TProvider * p = new TProvider(this);
    p->DataSet = CustomerQuery;
    OleVariant varDelta = AnyToSAFEARRAY(Delta);
    int Count;
    OleVariant varErrors = p->ApplyUpdates(varDelta, -1, Count);
    CORBA::Any_var anyErrors = SAFEARRAYToAny(varErrors);
    SAFEARRAYToAny(varErrors);
    ErrorCount = Count;
    delete p;
    return CORBA::Any::_duplicate(anyErrors);
  }
  catch (::Exception & e)
  {
    // Translate VCL exceptions into a corba exception
    throw CBuilder::Customers::CustomerException(e.Message.c_str());
  }
}

CORBA::Any* __fastcall TCustomersImpl::GetCustomers(CORBA::Boolean metadata)
{
  VISMutex_var lock(_mtx); // Prevent concurrent access
  cout << "GetCustomers request" << endl;
  try
  {
    CustomerQuery->Close();
    CustomerQuery->Open();
    TProvider * p = new TProvider(this);
    p->DataSet = CustomerQuery;
    CORBA::Any_var any = SAFEARRAYToAny(p->Data);
    delete p;
    return CORBA::Any::_duplicate(any);
  }
  catch (::Exception & e)
  {
    // Translate VCL exceptions into a corba exception
    throw CBuilder::Customers::CustomerException(e.Message.c_str());
  }
}


