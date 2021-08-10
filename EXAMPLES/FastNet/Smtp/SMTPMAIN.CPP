//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "smtpmain.h"
//---------------------------------------------------------------------------
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
  NMSMTP1->Host = Edit1->Text;
  NMSMTP1->Port = StrToInt(Edit2->Text);
  NMSMTP1->UserID = Edit4->Text;
  NMSMTP1->Connect();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  if (NMSMTP1->Connected) 
    NMSMTP1->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button6Click(TObject *Sender)
{
  NMSMTP1->PostMessage->FromAddress = Edit6->Text;
  NMSMTP1->PostMessage->FromName = Edit5->Text;
  NMSMTP1->PostMessage->Subject = Edit10->Text;
  NMSMTP1->PostMessage->ToAddress->Add(Edit7->Text);
  NMSMTP1->PostMessage->ToBlindCarbonCopy->Add(Edit9->Text);
  NMSMTP1->PostMessage->ToCarbonCopy->Add(Edit8->Text);
  NMSMTP1->PostMessage->Attachments->AddStrings(ListBox1->Items);
  NMSMTP1->PostMessage->Body->Assign(Memo1->Lines);
  NMSMTP1->SendMail();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender)
{
  if (OpenDialog1->Execute())
    ListBox1->Items->Add(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button5Click(TObject *Sender)
{
  ListBox1->Items->Delete(ListBox1->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
  if (NMSMTP1->Verify(Edit3->Text))
    ShowMessage(Edit3->Text+" exists");
  else
    ShowMessage(Edit3->Text+" not verified");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button7Click(TObject *Sender)
{
  NMSMTP1->ExpandList(Edit11->Text);	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1ConnectionRequired(bool &handled)
{
  AnsiString BoxCaption;
  AnsiString BoxMsg;
  BoxCaption = "Connection Required";
  BoxMsg = "Connection Required. Connect?";
  if (MessageBox(0, &BoxMsg[1], &BoxCaption[1], MB_YESNO + MB_ICONEXCLAMATION) == IDYES)
  {
    handled = TRUE;
    Button1Click(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1EncodeEnd(AnsiString Filename)
{
  StatusBar1->SimpleText = "Encoding "+Filename;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1EncodeStart(AnsiString Filename)
{
  StatusBar1->SimpleText = "Decoding "+Filename;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1Failure(TObject *Sender)
{
  ShowMessage("Operation Failed");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    //ShowMessage(NewHost);
    NMSMTP1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1MailListReturn(AnsiString MailAddress)
{
  Memo2->Lines->Add(MailAddress);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1PacketSent(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMSMTP1->BytesSent)+" bytes of "+IntToStr(NMSMTP1->BytesTotal)+" sent";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1RecipientNotFound(AnsiString Recipient)
{
  ShowMessage(Recipient+" not found");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1SendStart(TObject *Sender)
{
  StatusBar1->SimpleText = "Sending message";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMSMTP1Success(TObject *Sender)
{
  StatusBar1->SimpleText = "Message Sent";
}
//---------------------------------------------------------------------------
