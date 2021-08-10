//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "invcrpt.h"
#include "datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TInvoiceByOrderNoReport *InvoiceByOrderNoReport;
//---------------------------------------------------------------------------
__fastcall TInvoiceByOrderNoReport::TInvoiceByOrderNoReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInvoiceByOrderNoReport::InvoiceByOrderNoRptBeforePrint(
      TCustomQuickRep *Sender, bool &PrintReport)
{
	Sender->AllDataSets->Add(MastData->Cust);	
	Sender->AllDataSets->Add(MastData->Orders);	
}
//---------------------------------------------------------------------------
