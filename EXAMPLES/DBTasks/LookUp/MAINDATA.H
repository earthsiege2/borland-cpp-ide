//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef maindataH
#define maindataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TDMMain : public TDataModule
{
__published:    // IDE-managed Components 
    TDataSource *OrdersSoruce;
    TTable *tbCustomer;
    TFloatField *tbCustomerCustNo;
    TStringField *tbCustomerCompany;
    TStringField *tbCustomerAddr1;
    TStringField *tbCustomerAddr2;
    TStringField *tbCustomerCity;
    TStringField *tbCustomerState;
    TStringField *tbCustomerZip;
    TStringField *tbCustomerCountry;
    TStringField *tbCustomerPhone;
    TStringField *tbCustomerFAX;
    TFloatField *tbCustomerTaxRate;
    TStringField *tbCustomerContact;
    TDateTimeField *tbCustomerLastInvoiceDate;
    TTable *tbEmployee;
    TDataSource *CustomerSource;
    TDataSource *EmployeeSource;
    TTable *tbOrders;
    TFloatField *tbOrdersOrderNo;
    TFloatField *tbOrdersCustNo;
    TDateTimeField *tbOrdersSaleDate;
    TDateTimeField *tbOrdersShipDate;
    TIntegerField *tbOrdersEmpNo;
    TStringField *tbOrdersShipToContact;
    TStringField *tbOrdersShipToAddr1;
    TStringField *tbOrdersShipToAddr2;
    TStringField *tbOrdersShipToCity;
    TStringField *tbOrdersShipToState;
    TStringField *tbOrdersShipToZip;
    TStringField *tbOrdersShipToCountry;
    TStringField *tbOrdersShipToPhone;
    TStringField *tbOrdersShipVIA;
    TStringField *tbOrdersPO;
    TStringField *tbOrdersTerms;
    TStringField *tbOrdersPaymentMethod;
    TCurrencyField *tbOrdersItemsTotal;
    TFloatField *tbOrdersTaxRate;
    TCurrencyField *tbOrdersFreight;
    TCurrencyField *tbOrdersAmountPaid;
    TStringField *tbOrdersCustomerName;
    TStringField *tbOrdersEmployeeLastName;
    TStringField *tbOrdersEmployeeFirstName;
    TStringField *tbOrdersEmployeeFullName;
    void __fastcall tbOrdersCalcFields(TDataSet *DataSet);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TDMMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDMMain *DMMain;
//---------------------------------------------------------------------------
#endif
