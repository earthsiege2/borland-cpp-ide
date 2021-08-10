//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDH
#define MDH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <Quickrpt.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TMDForm : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *QuickRep;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRBand *ColumnHeaderBand1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRBand *PageFooterBand1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRBand *TitleBand1;
	TQRLabel *QRLabel6;
	TQRSubDetail *QRSubDetail1;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText10;
	TQRBand *GroupFooterBand1;
	TQRExpr *QRExpr1;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel11;
	TQRExpr *QRExpr2;
	TQRChildBand *ChildBand1;
	TTable *Customer;
	TTable *Orders;
	TDataSource *CustomerDS;
private:	// User declarations
public:		// User declarations
	__fastcall TMDForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TMDForm *MDForm;
//---------------------------------------------------------------------------
#endif
