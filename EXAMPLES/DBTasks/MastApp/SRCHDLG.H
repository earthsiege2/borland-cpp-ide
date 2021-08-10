//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef srchdlgH
#define srchdlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TSearchDlg : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;               //
	TLabel *Label2;               //
	TComboBox *OrderCombo;        //
	TEdit *SearchEd;              //
	TSpeedButton *SearchButton;   //
	TButton *OKBtn;               //
	TButton *CancelBtn;           //
	TDBGrid *DBGrid1;             //
	TDataSource *DataSource;      //
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall OrderComboChange(TObject *Sender);
	void __fastcall SearchEdKeyPress(TObject *Sender, char &Key);
	void __fastcall SearchEdChange(TObject *Sender);
private:	// User declarations
    TField *SrchFld;
    double GetCustNo();
    void SetCustNo(double NewCustNo);
    double GetPartNo();
    void SetPartNo(double NewPartNo);
public:		// User declarations
	virtual __fastcall TSearchDlg(TComponent* Owner);
    __property double PartNo={read=GetPartNo,write=SetPartNo};
    __property double CustNo={read=GetCustNo,write=SetCustNo};
    int ShowModalCust();
    int ShowModalParts();

};
//---------------------------------------------------------------------------
extern TSearchDlg *SearchDlg;
//---------------------------------------------------------------------------
#endif
