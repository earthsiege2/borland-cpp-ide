//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef CustomersImplUH
#define CustomersImplUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Customers_s.hh"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
//---------------------------------------------------------------------------
class TCustomersImpl : public TDataModule /* _sk_CBuilder::_sk_Customers : CORBAIdlInterface */
{
__published:	// IDE-managed Components
  TQuery *CustomerQuery;
private:	// User declarations
  VISMutex _mtx;
public:		// User declarations
	__fastcall TCustomersImpl(TComponent* Owner); 
  CORBA::Any* __fastcall ApplyCustomerUpdates(const CORBA::Any& Delta,
      CORBA::Long& ErrorCount);
  CORBA::Any* __fastcall GetCustomers(CORBA::Boolean metadata);
};
//---------------------------------------------------------------------------
extern PACKAGE TCustomersImpl *CustomersImpl;
//---------------------------------------------------------------------------
#endif

