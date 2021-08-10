//---------------------------------------------------------------------------
#ifndef invcrptH
#define invcrptH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TInvoiceByOrderNoReport : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *InvoiceByOrderNoRpt;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText1;
	TQRBand *ColumnHeaderBand1;
	TQRLabel *QRLabel4;
	TQRLabel *Description;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel11;
	TQRLabel *QRLabel12;
	TQRBand *TitleBand1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRShape *QRShape1;
	TQRLabel *QRLabel3;
	TQRExpr *QRExpr2;
	TQRDBText *QRDBText2;
	TQRExpr *QRExpr3;
	TQRDBText *QRDBText4;
	TQRBand *SummaryBand1;
	TQRExpr *QRExpr1;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel9;
	TQRShape *QRShape2;
	TQRExpr *QRExpr5;
	TQRDBText *QRDBText15;
	TQRChildBand *ChildBand1;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel13;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel15;
	TQRLabel *QRLabel16;
	TQRLabel *QRLabel17;
	TQRChildBand *ChildBand2;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText11;
	TQRDBText *QRDBText12;
	TQRDBText *QRDBText13;
	TQRDBText *QRDBText14;
	void __fastcall InvoiceByOrderNoRptBeforePrint(TCustomQuickRep *Sender,
      bool &PrintReport);
private:	// User declarations
public:		// User declarations
	__fastcall TInvoiceByOrderNoReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TInvoiceByOrderNoReport *InvoiceByOrderNoReport;
//---------------------------------------------------------------------------
#endif
