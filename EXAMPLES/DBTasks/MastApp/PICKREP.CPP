//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pickrep.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TPickRpt *PickRpt;
//---------------------------------------------------------------------------
__fastcall TPickRpt::TPickRpt(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPickRpt::OKBtnClick(TObject *Sender)
{
  Preview = false;	
}
//---------------------------------------------------------------------------
void __fastcall TPickRpt::ViewBtnClick(TObject *Sender)
{
	Preview = true;	
}
//---------------------------------------------------------------------------
