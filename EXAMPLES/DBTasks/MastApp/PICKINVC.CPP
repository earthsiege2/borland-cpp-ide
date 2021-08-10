//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pickinvc.h"
#include "datamod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TPickOrderNoDlg *PickOrderNoDlg;
//---------------------------------------------------------------------------
__fastcall TPickOrderNoDlg::TPickOrderNoDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPickOrderNoDlg::FormShow(TObject *Sender)
{
	MastData->Orders->Open();	
}
//---------------------------------------------------------------------------
