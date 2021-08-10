//---------------------------------------------------------------------------
#ifndef custrptH
#define custrptH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <quickrpt.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TCustomerByInvoiceReport : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *CustomerByInvoiceRpt;
	TQRBand *QRBand1;
	TQRExpr *QRExpr1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText1;
	TQRBand *QRBand2;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRBand *TitleBand1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	void __fastcall QRDBText1Print(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
	__fastcall TCustomerByInvoiceReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TCustomerByInvoiceReport *CustomerByInvoiceReport;
//---------------------------------------------------------------------------
#endif
