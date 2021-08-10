//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef listH
#define listH
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
class TListForm : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *QuickRep;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
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
	TTable *Customer;
private:	// User declarations
public:		// User declarations
	__fastcall TListForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TListForm *ListForm;
//---------------------------------------------------------------------------
#endif
