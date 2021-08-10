//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DMH
#define DMH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Classes.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TDM2 : public TDataModule
{
__published:
    TTable* Customer;
    TTable* CustLookup;
    TDataSource* CustomerSource;
    TDataSource* CustLookupSource;
    TFloatField* CustLookupCustNo;
    TStringField* CustLookupCompany;
    TStringField* CustLookupAddr1;
    TStringField* CustLookupAddr2;
    TStringField* CustLookupCity;
    TStringField* CustLookupState;
    TStringField* CustLookupZip;
    TStringField* CustLookupCountry;
    TStringField* CustLookupPhone;
    TStringField* CustLookupFAX;
    TFloatField* CustLookupTaxRate;
    TStringField* CustLookupContact;
    TDateTimeField* CustLookupLastInvoiceDate;
    TFloatField* CustomerCustNo;
    TStringField* CustomerCompany;
    TStringField* CustomerAddr1;
    TStringField* CustomerCity;
    TStringField* CustomerState;
    TStringField* CustomerZip;
    TStringField* CustomerCountry;   
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TDM2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDM2 *DM2;
//---------------------------------------------------------------------------
#endif
