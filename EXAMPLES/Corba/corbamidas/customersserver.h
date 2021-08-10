//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef CustomersServerH
#define CustomersServerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Customer_s.hh"
#include <BdeProv.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
//---------------------------------------------------------------------------
class TCustomersImpl : public TDataModule /* _sk_Customers : CORBAIdlInterface */
{
__published:	// IDE-managed Components
  TQuery *CustomerQuery;
  TFloatField *CustomerQueryCustNo;
  TStringField *CustomerQueryCompany;
  TStringField *CustomerQueryAddr1;
  TStringField *CustomerQueryAddr2;
  TStringField *CustomerQueryCity;
  TStringField *CustomerQueryState;
  TStringField *CustomerQueryZip;
  TStringField *CustomerQueryCountry;
  TStringField *CustomerQueryPhone;
  TStringField *CustomerQueryFAX;
  TFloatField *CustomerQueryTaxRate;
  TStringField *CustomerQueryContact;
  TDateTimeField *CustomerQueryLastInvoiceDate;
  TSession *Session1;
private:	// User declarations
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

