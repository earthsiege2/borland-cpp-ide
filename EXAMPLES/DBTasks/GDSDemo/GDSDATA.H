//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef GdsDataH
#define GdsDataH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include "Gdsstd.h"
#include <Db.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TStdDataForm : public TGDSStdForm
{
__published:
    TPanel *StdCtrlPanel;
    TRadioGroup *FilterOnRadioGroup;
    TGroupBox *GroupBox1;
    TLabel *FilterOnLabel;
    TEdit *FilterCriteria;
    TCheckBox *FilterCheckBox;
    TButton *NextBtn;
    TButton *PriorBtn;
    TTable *Cust;
    TTable *Orders;
    TFloatField *OrdersOrderNo;
    TFloatField *OrdersCustNo;
    TStringField *OrdersCustName;
    TDateTimeField *OrdersSaleDate;
    TCurrencyField *OrdersAmountDue;
    TDateTimeField *OrdersShipDate;
    TIntegerField *OrdersEmpNo;
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
    TStringField *OrdersTerms;
    TStringField *OrdersPaymentMethod;
    TCurrencyField *OrdersItemsTotal;
    TFloatField *OrdersTaxRate;
    TCurrencyField *OrdersFreight;
    TCurrencyField *OrdersAmountPaid;
    TCurrencyField *OrdersTaxAmount;
    TDataSource *OrdersSource;
    void __fastcall FilterOnRadioGroupClick(TObject *Sender);
    void __fastcall FilterCriteriaExit(TObject *Sender);
    void __fastcall FilterCriteriaKeyPress(TObject *Sender, Char &Key);   
    void __fastcall OrdersFilterOnDate(TDataSet * DataSet, bool & Accept);
    void __fastcall OrdersFilterOnAmount(TDataSet * DataSet, bool & Accept);
	 void __fastcall OrdersCalcFields(TDataSet * DataSet);
    void __fastcall FilterCheckBoxClick(TObject *Sender);
    void __fastcall NextBtnClick(TObject *Sender);
    void __fastcall PriorBtnClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:        // private user declarations
protected:		// protected user declarations
    double FLastAmount;
    TDateTime FLastDate;
    double __fastcall CalcAmountDue(void);
    void __fastcall ConvertFilterCriteria(void);
public:         // public user declarations
    virtual __fastcall TStdDataForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TStdDataForm *DSStdDataForm;
//---------------------------------------------------------------------------
#endif
