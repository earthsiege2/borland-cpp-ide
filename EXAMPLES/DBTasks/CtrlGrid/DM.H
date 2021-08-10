//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DMH
#define DMH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TDM1 : public TDataModule
{
__published:
    TTable *tblMaster;
    TStringField *tblMasterSYMBOL;
    TStringField *tblMasterCO_NAME;
    TStringField *tblMasterEXCHANGE;
    TStringField *tblMasterIndustryLongName;
    TFloatField *tblMasterCUR_PRICE;
    TFloatField *tblMasterYRL_HIGH;
    TFloatField *tblMasterYRL_LOW;
    TFloatField *tblMasterP_E_RATIO;
    TFloatField *tblMasterPROJ_GRTH;
    TSmallintField *tblMasterINDUSTRY;
    TSmallintField *tblMasterPRICE_CHG;
    TStringField *tblMasterRATING;
    TFloatField *tblMasterRANK;
    TSmallintField *tblMasterOUTLOOK;
    TStringField *tblMasterRCMNDATION;
    TStringField *tblMasterRISK;
    TDataSource *dsMaster;
    TTable *tblIndustry;
    TSmallintField *tblIndustryIND_CODE;
    TStringField *tblIndustryIND_NAME;
    TStringField *tblIndustryLONG_NAME;
    TDataSource *dsIndustry;
    TTable *tblHoldings;
    TFloatField *tblHoldingsACCT_NBR;
    TFloatField *tblHoldingsSHARES;
    TFloatField *tblHoldingsPUR_PRICE;
    TDateField *tblHoldingsPUR_DATE;
    TStringField *tblHoldingsSYMBOL;
    TCurrencyField *tblHoldingsPUR_COST;
    TDataSource *dsHoldings;
    void __fastcall tblHoldingsAfterPost(TDataSet *DataSet);
    void __fastcall tblHoldingsCalcFields(TDataSet *DataSet);
    void __fastcall tblHoldingsAfterOpen(TDataSet *DataSet);
	 void __fastcall CalculateTotals(TObject * Sender, TField * Field);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TDM1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDM1 *DM1;
//---------------------------------------------------------------------------
#endif
