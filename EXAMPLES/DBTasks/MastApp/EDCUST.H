//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef edcustH
#define edcustH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TEdCustForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel;
	TDBNavigator *DBNavigator;
	TSpeedButton *PrintBtn;
	TPanel *Panel1;
	TButton *OKButton;
	TButton *CancelButton;
	TPanel *Panel2;
	TBevel *Bevel2;
	TBevel *Bevel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label13;
	TDBEdit *DBEdName;
	TDBEdit *DBEdCustNo;
	TDBEdit *DBEdit3;
	TDBEdit *DBEdit9;
	TDBEdit *DBEdit4;
	TDBEdit *DBEdit14;
	TDBEdit *DBEdit5;
	TDBEdit *DBEdit6;
	TDBEdit *DBEdit7;
	TDBEdit *DBEdit8;
	TDBEdit *DBEdInv;
	TDBEdit *DBEdit12;
	TDBEdit *DBEdit11;
	TLabel *Label14;
	void __fastcall PrintBtnClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	virtual __fastcall TEdCustForm(TComponent* Owner);
    void Edit(double CustNo);
};
//---------------------------------------------------------------------------
extern TEdCustForm *EdCustForm;
//---------------------------------------------------------------------------
#endif
