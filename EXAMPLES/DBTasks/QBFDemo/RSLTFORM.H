//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef RsltformH
#define RsltformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TResultForm : public TForm
{
__published:    // IDE-managed Components 
    TPanel *Panel1;
    TSpeedButton *SpeedButton2;
    TDBNavigator *DBNavigator;
    TPanel *Panel4;
    TSpeedButton *SpeedButton1;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    TPanel *Panel3;
    TDataSource *DataSource1;
    TQuery *Query1;
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TResultForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TResultForm *ResultForm;
//---------------------------------------------------------------------------
#endif
