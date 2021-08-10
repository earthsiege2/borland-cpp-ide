//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "urlmain.h"
//---------------------------------------------------------------------------
#pragma link "NMURL"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject *Sender)
{
  NMURL1->InputString = Edit1->Text;
  Edit2->Text = NMURL1->Encode;
  Edit3->Text = NMURL1->Decode;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMURL1Error(TObject *Sender, AnsiString Operation,
	AnsiString ErrMsg)
{
  ShowMessage(ErrMsg);	
}
//---------------------------------------------------------------------------