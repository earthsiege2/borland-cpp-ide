//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef Adru1H
#define Adru1H
//----------------------------------------------------------------------------
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <Db.hpp>
//----------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
	TTabControl *TabControl1;
	TDataSource *DataSource1;
	TQuery *Query1;
	TDBEdit *dbeAddr1;
	TDBEdit *dbeAddr2;
	TDBEdit *dbeContactName;
	TDBEdit *dbeCity;
	TDBEdit *dbeState;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TDBEdit *dbeZip;
	TLabel *Label6;
	TDBEdit *dbeCustomerNumber;
	TDBEdit *dbeCompany;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TDBEdit *dbeCountry;
	TDBEdit *dbePhone;
	TDBEdit *dbeFax;
	TLabel *Label11;
	TLabel *Label12;
	TBitBtn *BitBtn1;
	TDataSource *DataSource2;
	TTable *Table1;
	TLabel *Label10;
	TDBEdit *dbeLastInvDate;
	TLabel *Label13;
	TDBEdit *dbeTaxRate;
	TGroupBox *GroupBox1;
	TFloatField *Table1OrderNo;
	TFloatField *Table1CustNo;
	TDateTimeField *Table1SaleDate;
	TDateTimeField *Table1ShipDate;
	TIntegerField *Table1EmpNo;
	TStringField *Table1ShipToContact;
	TStringField *Table1ShipToAddr1;
	TStringField *Table1ShipToAddr2;
	TStringField *Table1ShipToCity;
	TStringField *Table1ShipToState;
	TStringField *Table1ShipToZip;
	TStringField *Table1ShipToCountry;
	TStringField *Table1ShipToPhone;
	TStringField *Table1ShipVIA;
	TStringField *Table1PO;
	TStringField *Table1Terms;
	TStringField *Table1PaymentMethod;
	TCurrencyField *Table1ItemsTotal;
	TFloatField *Table1TaxRate;
	TCurrencyField *Table1Freight;
	TCurrencyField *Table1AmountPaid;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit3;
	TDBEdit *DBEdit4;
	TDBEdit *DBEdit5;
	TDBEdit *DBEdit6;
	TDBEdit *DBEdit7;
	TDBEdit *DBEdit8;
	TDBEdit *DBEdit9;
	TDBEdit *DBEdit10;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TDBEdit *DBEdit11;
	TDBEdit *DBEdit12;
	TLabel *Label24;
	TLabel *Label25;
	TDBEdit *DBEdit13;
	TDBEdit *DBEdit14;
	TDBEdit *DBEdit15;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TSpeedButton *FirstOrders;
	TSpeedButton *PriorOrders;
	TSpeedButton *NextOrders;
	TSpeedButton *LastOrders;
	TSpeedButton *EditOrders;
	TSpeedButton *PostOrders;
	TSpeedButton *CancelOrders;
	TSpeedButton *CancelCust;
	TSpeedButton *PostCust;
	TSpeedButton *EditCust;
	TSpeedButton *LastCust;
	TSpeedButton *NextCust;
	TSpeedButton *PriorCust;
	TSpeedButton *FirstCust;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall TabControl1Change(TObject *Sender);
	void __fastcall DataSource2StateChange(TObject *Sender);
	void __fastcall DataSource1StateChange(TObject *Sender);
	void __fastcall FirstOrdersClick(TObject *Sender);
	void __fastcall PriorOrdersClick(TObject *Sender);
	void __fastcall NextOrdersClick(TObject *Sender);
	void __fastcall LastOrdersClick(TObject *Sender);
	void __fastcall EditOrdersClick(TObject *Sender);
	void __fastcall PostOrdersClick(TObject *Sender);
	void __fastcall CancelOrdersClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CancelCustClick(TObject *Sender);
	void __fastcall PostCustClick(TObject *Sender);
	void __fastcall EditCustClick(TObject *Sender);
	void __fastcall LastCustClick(TObject *Sender);
	void __fastcall NextCustClick(TObject *Sender);
	void __fastcall PriorCustClick(TObject *Sender);
	void __fastcall FirstCustClick(TObject *Sender);
	
public:
	void __fastcall EnableDisableOrNav(void);
	void __fastcall EnableDisableCsNav(void);
    virtual __fastcall TFormMain(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TFormMain *FormMain;
//----------------------------------------------------------------------------
#endif	
