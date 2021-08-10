//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef RecFormH
#define RecFormH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "GdsData.h"
#include <Db.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TRecViewForm : public TStdDataForm
{
__published:
    TPanel *GroupBox2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label5;
    TLabel *Label9;
    TBevel *Bevel1;
    TDBEdit *OrderNo;
    TDBEdit *CustName;
    TDBEdit *SaleDate;
    TDBEdit *AmountDue;
    TDBEdit *DBEdit3;
    TDBEdit *DBEdit4;
    TDBEdit *DBEdit1;
    TDBEdit *DBEdit5;
    TDBNavigator *DBNavigator1;
    TPanel *Panel1;
    TLabel *Label11;
    TLabel *Label12;
    TDBCheckBox *OnCredit;
    TDBEdit *DBEdit7;
    TDBEdit *DBEdit8;
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TRecViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TRecViewForm *RecViewForm;
//---------------------------------------------------------------------------
#endif
