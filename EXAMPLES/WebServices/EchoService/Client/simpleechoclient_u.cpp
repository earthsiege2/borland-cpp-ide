#include <vcl.h>
#pragma hdrstop

#include "SimpleEchoClient_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

_di_InteropTestPortType TForm1::GetEchoService()
{
  if (!FEchoService)
  {
        HTTPRIO1->QueryInterface(FEchoService);
  }
  return FEchoService;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonEchoIntegerClick(TObject *Sender)
{
    if (EchoService) {
        int sendval = StrToInt( EditSendInteger->Text);
        EditRecvInteger->Text=IntToStr(EchoService->echoInteger(sendval));
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSetRioURLClick(TObject *Sender)
{
  delete HTTPRIO1;
  HTTPRIO1 = new THTTPRIO(this);
  HTTPRIO1->URL = CBServerURL->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoStringClick(TObject *Sender)
{
    if (EchoService) {
        EditRecvString->Text=EchoService->echoString(EditSendString->Text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoBooleanClick(TObject *Sender)
{
    if (EchoService) {
        bool sendval = StrToBool(EditSendBoolean->Text);
        EditRecvBoolean->Text=BoolToStr(EchoService->echoBoolean(sendval), true);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoFloatClick(TObject *Sender)
{
    if (EchoService) {
        float sendval = StrToFloat(EditSendFloat->Text);
        EditRecvFloat->Text=FloatToStr(EchoService->echoFloat(sendval));
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoDateClick(TObject *Sender)
{
    if (EchoService) {
        sPointer<TXSDateTime> sendval(new TXSDateTime());
        sendval->AsDateTime=StrToDate(EditSendDate->Text);
        sPointer<TXSDateTime> retVal(EchoService->echoDate(&sendval));
        EditRecvDate->Text=DateToStr(retVal->AsDateTime);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoHexBinaryClick(TObject *Sender)
{
    if (EchoService) {
        sPointer<TXSHexBinary> sendval(new TXSHexBinary());
        sendval->HexBinaryString = EditSendHexBinary->Text;
        sPointer<TXSHexBinary> retVal(EchoService->echoHexBinary(&sendval));
        EditRecvHexBinary->Text = retVal->HexBinaryString;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoVoidClick(TObject *Sender)
{
    if (EchoService) {
        EchoService->echoVoid();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEchoSimpleClassClick(TObject *Sender)
{
    if (EchoService) {

        sPointer<SOAPStruct> tempSimpleClass(new SOAPStruct);
        tempSimpleClass->varString = EditSendString->Text;
        tempSimpleClass->varInt = StrToInt( EditSendInteger->Text);
        tempSimpleClass->varFloat = StrToFloat(EditSendFloat->Text);

        sPointer<SOAPStruct> recvSimpleClass(EchoService->echoStruct(&tempSimpleClass));
        EditRecvString->Text = recvSimpleClass->varString;
        EditRecvInteger->Text = IntToStr(recvSimpleClass->varInt);
        EditRecvFloat->Text = FloatToStr(recvSimpleClass->varFloat);
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (EchoService) {

        TStringDynArray SendStringArray;
        SendStringArray.Length = 5;
        SendStringArray[0] = EditSendStringArray0->Text;
        SendStringArray[1] = EditSendStringArray1->Text;
        SendStringArray[2] = EditSendStringArray2->Text;
        SendStringArray[3] = EditSendStringArray3->Text;
        SendStringArray[4] = EditSendStringArray4->Text;

        TStringDynArray RecvStringArray;
        RecvStringArray = EchoService->echoStringArray(SendStringArray);
        EditRecvStringArray0->Text = RecvStringArray[0];
        EditRecvStringArray1->Text = RecvStringArray[1];
        EditRecvStringArray2->Text = RecvStringArray[2];
        EditRecvStringArray3->Text = RecvStringArray[3];
        EditRecvStringArray4->Text = RecvStringArray[4];
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SendData1Click(TObject *Sender)
{
  AnsiString resetval = "";
  EditSendString->Text = resetval;
  EditSendBoolean->Text= resetval;
  EditSendDate->Text= resetval;
  EditSendFloat->Text= resetval;
  EditSendHexBinary->Text= resetval;
  EditSendInteger->Text= resetval;
  EditSendStringArray0->Text= resetval;
  EditSendStringArray1->Text= resetval;
  EditSendStringArray2->Text= resetval;
  EditSendStringArray3->Text= resetval;
  EditSendStringArray4->Text= resetval;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RecieveData1Click(TObject *Sender)
{
  AnsiString resetval = "";
  EditRecvString->Text = resetval;
  EditRecvBoolean->Text= resetval;
  EditRecvDate->Text= resetval;
  EditRecvFloat->Text= resetval;
  EditRecvHexBinary->Text= resetval;
  EditRecvInteger->Text= resetval;
  EditRecvStringArray0->Text= resetval;
  EditRecvStringArray1->Text= resetval;
  EditRecvStringArray2->Text= resetval;
  EditRecvStringArray3->Text= resetval;
  EditRecvStringArray4->Text= resetval;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
  /* Clear out interface */
  FEchoService = 0;
}
//---------------------------------------------------------------------------

