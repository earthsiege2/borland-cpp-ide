//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef CustH
#define CustH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfmCustomers : public TForm
{
__published:
    TDBGrid* DBGrid1;
    TPanel* Panel2;
    TDBNavigator* DBNavigator1;
    TBitBtn* BitBtn1;
    TStatusBar* StatusBar1;
    TMainMenu* MainMenu1;
    TMenuItem* AboutItem;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall AboutItemClick(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TfmCustomers(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmCustomers *fmCustomers;
//---------------------------------------------------------------------------
#endif
 
