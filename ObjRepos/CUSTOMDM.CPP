//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CustomDM.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TCustomerData *CustomerData;
//--------------------------------------------------------------------- 
__fastcall TCustomerData::TCustomerData(TComponent* AOwner)
	: TDataModule(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TCustomerData::LineItemsCalcFields(TDataSet *DataSet)
{
	LineItemsExtendedPrice->Value = 
		LineItemsPrice->Value * ((100 - LineItemsDiscount->Value) / 100);

	LineItemsTotal->Value = 
		LineItemsExtendedPrice->Value * LineItemsQty->Value;
}
//--------------------------------------------------------------------- 
