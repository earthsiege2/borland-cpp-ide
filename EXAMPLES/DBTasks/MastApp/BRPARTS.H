//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef brpartsH
#define brpartsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TBrPartsForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDBNavigator *DBNavigator1;
	TButton *EditBtn;
	TSpeedButton *ActivateBtn;
	TPanel *Panel2;
	TButton *CloseBtn;
	TDBGrid *PartsGrid;
	TBevel *Bevel1;
	void __fastcall EditBtnClick(TObject *Sender);
	void __fastcall CloseBtnClick(TObject *Sender);
	void __fastcall ActivateQuery(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    double FPartNo;
    double GetPartNo();
    void SetPartNo(double);
 public:		// User declarations
    __property Double PartNo={read=GetPartNo,write=SetPartNo};
	virtual __fastcall TBrPartsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TBrPartsForm *BrPartsForm;
//---------------------------------------------------------------------------
#endif
