//---------------------------------------------------------------------------
#ifndef orderrptH
#define orderrptH
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
class TOrdersByDateReport : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *OrdersByDateRpt;
	TQRBand *TitleBand1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRLabel *FromToHeading;
	TQRBand *QRBand1;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel11;
	TQRLabel *QRLabel12;
	TQRBand *QRBand2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText2;
private:	// User declarations
public:		// User declarations
	__fastcall TOrdersByDateReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TOrdersByDateReport *OrdersByDateReport;
//---------------------------------------------------------------------------
#endif
