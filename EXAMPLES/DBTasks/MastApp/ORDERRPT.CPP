//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "orderrpt.h"
#include "datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TOrdersByDateReport *OrdersByDateReport;
//---------------------------------------------------------------------------
__fastcall TOrdersByDateReport::TOrdersByDateReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
