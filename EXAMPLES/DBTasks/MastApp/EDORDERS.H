//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef edordersH
#define edordersH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TEdOrderForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Speedbar;
	TLabel *ModeIndicator;
	TDBText *DBText1;
	TDBNavigator *DBEditBtns;
	TDBNavigator *DBNavBtns;
	TSpeedButton *PrintBtn;
	TBevel *Bevel1;
	TPanel *HeaderPanel;
	TImage *Image1;
	TButton *PostBtn;
	TButton *CancelBtn;
	TButton *CloseBtn;
	TLabel *Label2;
	TLabel *Label28;
	TLabel *Label19;
	TLabel *Label18;
	TDBEdit *SaleDateEdit;
	TSpeedButton *PopupCalBtn;
	TLabel *Label4;
	TLabel *Label17;
	TLabel *PaymentMethod;
	TLabel *Label15;
	TLabel *Label14;
	TLabel *Label3;
	TLabel *Tax;
	TLabel *Label5;
	TLabel *Label20;
	TLabel *Label6;
	TDBLookupComboBox *CompanyCombo;
	TDBEdit *CustNoEdit;
	TDBEdit *ShipToCompanyEdit;
	TDBEdit *CustAdd1Edit;
	TDBEdit *CustAdd2Edit;
	TDBEdit *CustCityEdit;
	TDBEdit *CustStateEdit;
	TDBEdit *CustZipEdit;
	TDBEdit *ShipToAdd1Edit;
	TDBEdit *ShipToAdd2Edit;
	TDBEdit *ShipToCityEdit;
	TDBEdit *ShipToSateEdit;
	TDBEdit *ShipToZipEdit;
	TDBLookupComboBox *SoldByCombo;
	TDBComboBox *TermsCombo;
	TDBComboBox *PaymentCombo;
	TDBComboBox *ShipViaCombo;
	TDBEdit *POEdit;
	TDBGrid *ItemsGrid;
	TDBEdit *TotalEdit;
	TDBEdit *TaxRateEdit;
	TDBEdit *TaxTotalEdit;
	TDBEdit *FreightEdit;
	TDBEdit *AmountPaidEdit;
	TDBEdit *AmountDueEdit;
	TDataSource *ActiveSource;
	void __fastcall ItemsGridEnter(TObject *Sender);
	void __fastcall ActiveSourceStateChange(TObject *Sender);
	void __fastcall ItemsGridExit(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall PostBtnClick(TObject *Sender);
	void __fastcall PickPartNo(TObject *Sender);
	void __fastcall PickDate(TObject *Sender);
	void __fastcall PrintBtnClick(TObject *Sender);
    void __fastcall OrdersSourceStateChange(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall SoldByComboKeyPress(TObject *Sender, char &Key);
	
private:	// User declarations
public:		// User declarations
	virtual __fastcall TEdOrderForm(TComponent* Owner);
    void Enter();
    void Edit(double OrderNo);
};
//---------------------------------------------------------------------------
extern TEdOrderForm *EdOrderForm;
//---------------------------------------------------------------------------
#endif
