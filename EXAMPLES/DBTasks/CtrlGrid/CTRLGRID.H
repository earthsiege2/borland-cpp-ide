//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef CtrlFormH
#define CtrlFormH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <DBCGrids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFmCtrlGrid : public TForm
{
__published:
    TBevel *Bevel1;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *lPurchase;
    TLabel *lTotalCost;
    TLabel *lTotalShares;
    TLabel *lDifference;
    TDBCtrlGrid *DBCtrlGrid1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TDBEdit *DBEdit1;
    TDBEdit *DBEdit2;
    TDBEdit *DBEdit3;
    TDBEdit *DBEdit4;
    TDBGrid *DBGrid1;
    TButton *Button1;
    TDBNavigator *DBNavigator1;
    TMainMenu *MainMenu1;
    TMenuItem *About1;
    void __fastcall DBCtrlGrid1Enter(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall DBGrid1Enter(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFmCtrlGrid(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFmCtrlGrid *FmCtrlGrid;
//---------------------------------------------------------------------------
#endif
