//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef qrycustH
#define qrycustH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TQueryCustDlg : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Msglab;
	TEdit *FromEdit;
	TEdit *ToEdit;
	TButton *OkBtn;
	TButton *CancelBtn;
	TSpeedButton *PopupCalBtnFrom;
	TSpeedButton *PopupCalToBtn;
	void __fastcall OkBtnClick(TObject *Sender);
	
	
	
	void __fastcall PopupCalBtnFromClick(TObject *Sender);
	void __fastcall PopupCalToBtnClick(TObject *Sender);
	
private:	// User declarations
    TDateTime GetFromDate();
    TDateTime GetToDate();
    void SetFromDate(TDateTime NewDate);
    void SetToDate(TDateTime NewDate);
public:		// User declarations
	virtual __fastcall TQueryCustDlg(TComponent* Owner);
    __property TDateTime FromDate={read=GetFromDate,write=SetFromDate};
    __property TDateTime ToDate={read=GetToDate,write=SetToDate};
};
//---------------------------------------------------------------------------
extern TQueryCustDlg *QueryCustDlg;
//---------------------------------------------------------------------------
#endif
