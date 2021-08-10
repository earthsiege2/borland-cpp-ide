//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFmMain : public TForm
{
__published:	// IDE-managed Components 
        TMainMenu *MainMenu1;
        TMenuItem *About1;
        TDBNavigator *DBNavigator1;
        TLabel *Label1;
        TDBGrid *GridCustomers;
        TDBGrid *GridOrders;
        TLabel *Label3;
        TLabel *Label4;
        TDBGrid *GridItems;
    void __fastcall GridOrdersEnter(TObject *Sender);
    void __fastcall GridCustomersEnter(TObject *Sender);
    void __fastcall GridItemsEnter(TObject *Sender);
    void __fastcall GridCustomersExit(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        virtual __fastcall TFmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFmMain *FmMain;
//---------------------------------------------------------------------------
#endif
