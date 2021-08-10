//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef brcstordH
#define brcstordH
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
class TBrCustOrdForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDBNavigator *Navigator;
	TSpeedButton *DefineBtn;
	TSpeedButton *ActivateBtn;
	TPanel *BtnPanel;
	TButton *EditBtn;
	TButton *CloseBtn;
	TBevel *Bevel1;
	TPanel *CustPanel;
	TPanel *OrdersPanel;
	TDBGrid *CustGrid;
	TDBGrid *OrdersGrid;
	void __fastcall CustGridEnter(TObject *Sender);
	void __fastcall SetQuery(TObject *Sender);
	void __fastcall ActivateQuery(TObject *Sender);
	void __fastcall EditBtnClick(TObject *Sender);
	void __fastcall CloseBtnClick(TObject *Sender);
	void __fastcall OrdersGridEnter(TObject *Sender);
	
	void __fastcall FormShow(TObject *Sender);
	
private:	// User declarations
    TDataSource *FActiveSource;
    double FCustNo;
    double FOrderNo;
    double GetCustNo();
    double GetOrderNo();
    void SetActiveSource(TDataSource *DataSource);
    void SetCustNo(double NewCustNo);
    void SetOrderNo(double NewOrderNo);
    __property TDataSource *ActiveSource={read=FActiveSource,write=SetActiveSource};
public:		// User declarations
	virtual __fastcall TBrCustOrdForm(TComponent* Owner);
    __property double CustNo={read=GetCustNo,write=SetCustNo};
    __property double OrderNo={read=GetOrderNo,write=SetOrderNo};
};
//---------------------------------------------------------------------------
extern TBrCustOrdForm *BrCustOrdForm;
//---------------------------------------------------------------------------
#endif
