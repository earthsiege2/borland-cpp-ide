//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#include <DB.hpp>
#include <Classes.hpp>
#include <DBTables.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
#ifndef DatamodHPP
#define DatamodHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#ifndef WindowsHPP
#include <windows.hpp>
#endif

#ifndef MessagesHPP
#include <messages.hpp>
#endif

#ifndef SysUtilsHPP
#include <sysutils.hpp>
#endif

#ifndef ClassesHPP
#include <classes.hpp>
#endif

#ifndef GraphicsHPP
#include <graphics.hpp>
#endif

#ifndef ControlsHPP
#include <controls.hpp>
#endif

#ifndef FormsHPP
#include <forms.hpp>
#endif

#ifndef DialogsHPP
#include <dialogs.hpp>
#endif

#ifndef DBHPP
#include <db.hpp>
#endif

#ifndef DBTablesHPP
#include <dbtables.hpp>
#endif
//---------------------------------------------------------------------------
class TMastData : public TDataModule
{
__published:
    TDatabase *Database;
    TTable *NextCust;
    TFloatField *NextCustNewCust;
    TTable *Parts;
    TFloatField *PartsPartNo;
    TStringField *PartsDescription;
    TFloatField *PartsVendorNo;
    TFloatField *PartsOnHand;
    TFloatField *PartsOnOrder;
    TBooleanField *PartsBackOrd;
    TCurrencyField *PartsCost;
    TCurrencyField *PartsListPrice;
    TDataSource *PartsSource;
    TQuery *PartsQuery;
    TFloatField *PartsQueryPartNo;
    TStringField *PartsQueryDescription;
    TFloatField *PartsQueryVendorNo;
    TFloatField *PartsQueryOnHand;
    TFloatField *PartsQueryOnOrder;
    TBooleanField *PartsQueryBackOrd;
    TCurrencyField *PartsQueryCost;
    TCurrencyField *PartsQueryListPrice;
    TDataSource *VendorSource;
    TTable *Vendors;
    TTable *Orders;
    TFloatField *OrdersOrderNo;
    TFloatField *OrdersCustNo;
    TDateTimeField *OrdersSaleDate;
    TDateTimeField *OrdersShipDate;
    TStringField *OrdersShipToContact;
    TStringField *OrdersShipToAddr1;
    TStringField *OrdersShipToAddr2;
    TStringField *OrdersShipToCity;
    TStringField *OrdersShipToState;
    TStringField *OrdersShipToZip;
    TStringField *OrdersShipToCountry;
    TStringField *OrdersShipToPhone;
    TStringField *OrdersShipVIA;
    TStringField *OrdersPO;
    TIntegerField *OrdersEmpNo;
    TStringField *OrdersTerms;
    TStringField *OrdersPaymentMethod;
    TCurrencyField *OrdersItemsTotal;
    TFloatField *OrdersTaxRate;
    TCurrencyField *OrdersTaxTotal;
    TCurrencyField *OrdersFreight;
    TCurrencyField *OrdersAmountPaid;
    TCurrencyField *OrdersAmountDue;
    TDataSource *OrdersSource;
    TTable *CustByOrd;
    TFloatField *CustByOrdCustNo;
    TStringField *CustByOrdCompany;
    TStringField *CustByOrdAddr1;
    TStringField *CustByOrdAddr2;
    TStringField *CustByOrdCity;
    TStringField *CustByOrdState;
    TStringField *CustByOrdZip;
    TStringField *CustByOrdCountry;
    TStringField *CustByOrdPhone;
    TStringField *CustByOrdFAX;
    TFloatField *CustByOrdTaxRate;
    TStringField *CustByOrdContact;
    TDateTimeField *CustByOrdLastInvoiceDate;
    TDataSource *CustByOrdSrc;
    TTable *Items;
    TFloatField *ItemsItemNo;
    TFloatField *ItemsOrderNo;
    TFloatField *ItemsPartNo;
    TStringField *ItemsDescription;
    TCurrencyField *ItemsSellPrice;
    TIntegerField *ItemsQty;
    TFloatField *ItemsDiscount;
    TCurrencyField *ItemsExtPrice;
    TDataSource *ItemsSource;
    TTable *NextOrd;
    TFloatField *NextOrdNewKey;
    TTable *Emps;
    TIntegerField *EmpsEmpNo;
    TStringField *EmpsFullName;
    TStringField *EmpsLastName;
    TStringField *EmpsFirstName;
    TStringField *EmpsPhoneExt;
    TDateTimeField *EmpsHireDate;
    TFloatField *EmpsSalary;
    TDataSource *EmpsSource;
    TQuery *LastItemQuery;
    TTable *Cust;
    TFloatField *CustCustNo;
    TStringField *CustCompany;
    TStringField *CustPhone;
    TDateTimeField *CustLastInvoiceDate;
    TStringField *CustAddr1;
    TStringField *CustAddr2;
    TStringField *CustCity;
    TStringField *CustState;
    TStringField *CustZip;
    TStringField *CustCountry;
    TStringField *CustFAX;
    TFloatField *CustTaxRate;
    TStringField *CustContact;
    TDataSource *CustSource;
    TQuery *CustQuery;
    TFloatField *CustQueryCustNo;
    TStringField *CustQueryCompany;
    TStringField *CustQueryPhone;
    TDateTimeField *CustQueryLastInvoiceDate;
    TDataSource *OrdByCustSrc;
    TTable *OrdByCust;
    TFloatField *OrdByCustOrderNo;
    TFloatField *OrdByCustCustNo;
    TDateTimeField *OrdByCustSaleDate;
    TDateTimeField *OrdByCustShipDate;
    TCurrencyField *OrdByCustItemsTotal;
    TFloatField *OrdByCustTaxRate;
    TCurrencyField *OrdByCustFreight;
    TCurrencyField *OrdByCustAmountPaid;
    TCurrencyField *OrdByCustAmountDue;
    TDataSource *CustMasterSrc;
    TTable *CustByComp;
    TDataSource *CustByCompSrc;
	TQuery *CustByLastInvQuery;
	TFloatField *CustByLastInvQueryCustNo;
	TStringField *CustByLastInvQueryCompany;
	TStringField *CustByLastInvQueryAddr1;
	TStringField *CustByLastInvQueryAddr2;
	TStringField *CustByLastInvQueryCity;
	TStringField *CustByLastInvQueryState;
	TStringField *CustByLastInvQueryZip;
	TStringField *CustByLastInvQueryCountry;
	TStringField *CustByLastInvQueryPhone;
	TStringField *CustByLastInvQueryFAX;
	TFloatField *CustByLastInvQueryTaxRate;
	TStringField *CustByLastInvQueryContact;
	TDateTimeField *CustByLastInvQueryLastInvoiceDate;
	TQuery *OrdersByDateQuery;
	TFloatField *OrdersByDateQueryOrderNo;
	TFloatField *OrdersByDateQueryCustNo;
	TDateTimeField *OrdersByDateQuerySaleDate;
	TDateTimeField *OrdersByDateQueryShipDate;
	TIntegerField *OrdersByDateQueryEmpNo;
	TStringField *OrdersByDateQueryShipToContact;
	TStringField *OrdersByDateQueryShipToAddr1;
	TStringField *OrdersByDateQueryShipToAddr2;
	TStringField *OrdersByDateQueryShipToCity;
	TStringField *OrdersByDateQueryShipToState;
	TStringField *OrdersByDateQueryShipToZip;
	TStringField *OrdersByDateQueryShipToCountry;
	TStringField *OrdersByDateQueryShipToPhone;
	TStringField *OrdersByDateQueryShipVIA;
	TStringField *OrdersByDateQueryPO;
	TStringField *OrdersByDateQueryTerms;
	TStringField *OrdersByDateQueryPaymentMethod;
	TCurrencyField *OrdersByDateQueryItemsTotal;
	TFloatField *OrdersByDateQueryTaxRate;
	TCurrencyField *OrdersByDateQueryFreight;
	TCurrencyField *OrdersByDateQueryAmountPaid;
	TStringField *OrdersByDateQueryCompany;
	void __fastcall PartsBeforeOpen(TDataSet *DataSet);
	void __fastcall PartsCalcFields(TDataSet *DataSet);
	void __fastcall PartsQueryCalcFields(TDataSet *DataSet);
	void __fastcall OrdersAfterCancel(TDataSet *DataSet);
	void __fastcall OrdersAfterPost(TDataSet *DataSet);
	void __fastcall OrdersBeforeCancel(TDataSet *DataSet);
	void __fastcall OrdersBeforeClose(TDataSet *DataSet);
	void __fastcall OrdersBeforeDelete(TDataSet *DataSet);
	void __fastcall OrdersBeforeInsert(TDataSet *DataSet);
	void __fastcall OrdersBeforeOpen(TDataSet *DataSet);
	void __fastcall OrdersCalcFields(TDataSet *DataSet);
	void __fastcall OrdersNewRecord(TDataSet *DataSet);
	void __fastcall ItemsAfterDelete(TDataSet *DataSet);
	void __fastcall ItemsAfterPost(TDataSet *DataSet);
	void __fastcall EnsureOrdersEdit(TDataSet *DataSet);
	void __fastcall ItemsBeforeEdit(TDataSet *DataSet);
	void __fastcall ItemsBeforeOpen(TDataSet *DataSet);
	void __fastcall ItemsBeforePost(TDataSet *DataSet);
	void __fastcall ItemsCalcFields(TDataSet *DataSet);
	void __fastcall ItemsNewRecord(TDataSet *DataSet);
	void __fastcall EmpsCalcFields(TDataSet *DataSet);
	void __fastcall OrdersCustNoChange(TField *Sender);
	void __fastcall CustBeforeOpen(TDataSet *DataSet);
	void __fastcall OrdByCustCalcFields(TDataSet *DataSet);
	void __fastcall CustBeforePost(TDataSet *DataSet);
	void __fastcall OrdersAfterDelete(TDataSet *DataSet);
	void __fastcall OrdersBeforeEdit(TDataSet *DataSet);
	void __fastcall EditUpdateError(TDataSet *DataSet, EDatabaseError *E,
	TUpdateKind UpdateKind, TUpdateAction &UpdateAction);
private:        // private user declarations
    double PrevPartNo;    //remembers Item's previous part#
    long PrevQty;         //remembers Item's previous qty
    bool DeletingItems;   //suppress totals calc. if deleting items
    int FItemNo;
    AnsiString DataDirectory();
    void SetDatabaseAlias(AnsiString AliasName);
    void UpdateParts(double, long);
    void UpdateTotals();
    void DeleteItems();
public:         // public user declarations
    void UseLocalData();
    void UseRemoteData();
    bool DataSetApplyUpdates(TDBDataSet *DataSet, bool Apply);
    virtual __fastcall TMastData(TComponent* Owner);
};

bool Confirm(const char *Msg);

//---------------------------------------------------------------------------
extern TMastData *MastData;
//---------------------------------------------------------------------------
#endif
