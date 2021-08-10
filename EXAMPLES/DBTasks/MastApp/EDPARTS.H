//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef edpartsH
#define edpartsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TEdPartsForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TBevel *Bevel1;
	TDBNavigator *Navigator;
	TSpeedButton *PrintBtn;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *OKButton;
	TButton *CancelButton;
	TDBEdit *DBEdPartNo;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit3;
	TDBEdit *DBEdit4;
	TDBEdit *DBEdit5;
	TDBLookupComboBox *DataComboBox1;
	TDBEdit *DBEdit8;
	TDBEdit *DBEdit7;
	TDataSource *PartsSource1;
	void __fastcall PrintBtnClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	
private:	// User declarations
public:		// User declarations
	virtual __fastcall TEdPartsForm(TComponent* Owner);
void Edit(Double PartNo);

};
//---------------------------------------------------------------------------
extern TEdPartsForm *EdPartsForm;
//---------------------------------------------------------------------------
#endif
