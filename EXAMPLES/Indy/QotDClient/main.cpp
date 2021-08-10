//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmQuoteOfTheDayDemo *frmQuoteOfTheDayDemo;
//---------------------------------------------------------------------------
__fastcall TfrmQuoteOfTheDayDemo::TfrmQuoteOfTheDayDemo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmQuoteOfTheDayDemo::btnQuoteClick(TObject *Sender)
{
     IdQtdDemo->Host = edtQuoteDayServer->Text;
     // Get the quote of the day
     mmoQuoteOfTheDay->Lines->Text = IdQtdDemo->Quote;
}
//---------------------------------------------------------------------------
