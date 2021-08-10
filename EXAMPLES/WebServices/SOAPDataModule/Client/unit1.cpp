//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SoapConnection1BeforeExecute(
      const AnsiString MethodName, WideString &SOAPRequest)
{
  Memo1->Text = SOAPRequest;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  ClientDataSet1->Active = CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SoapConnection1AfterExecute(
      const AnsiString MethodName, TStream *SOAPResponse)
{
  sPointer<TStringStream> ss(new TStringStream(""));
  ss->CopyFrom(SOAPResponse, 0);
  // Really big packet cause Memo to lock up...
  if (ss->DataString.Length()  < 0x7FFF)
    Memo2->Text = ss->DataString;
}
//---------------------------------------------------------------------------

