//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "custrpt.h"
#include "datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TCustomerByInvoiceReport *CustomerByInvoiceReport;
//---------------------------------------------------------------------------
__fastcall TCustomerByInvoiceReport::TCustomerByInvoiceReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCustomerByInvoiceReport::QRDBText1Print(TObject *sender,
      AnsiString &Value)
{
  Value = DateToStr(MastData->CustByLastInvQueryLastInvoiceDate->Value);	
}
//---------------------------------------------------------------------------
