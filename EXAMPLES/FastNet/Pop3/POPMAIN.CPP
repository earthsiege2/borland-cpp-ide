//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "popmain.h"
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
  NMPOP31->AttachFilePath = ".";
  NMPOP31->DeleteOnRead = false;
  NMPOP31->ReportLevel = Status_Basic;
  NMPOP31->TimeOut = 20000;
  NMPOP31->Host = Edit1->Text;
  NMPOP31->Port = StrToInt(Edit2->Text);
  NMPOP31->UserID = Edit3->Text;
  NMPOP31->Password = Edit4->Text;
  NMPOP31->Connect();
  Label10->Caption = "# of Messages: "+IntToStr(NMPOP31->MailCount);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  NMPOP31->Disconnect();	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button5Click(TObject *Sender)
{
  NMPOP31->List();	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender)
{
  Memo3->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button7Click(TObject *Sender)
{
  NMPOP31->DeleteMailMessage(StrToInt(Edit5->Text));	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
  NMPOP31->GetMailMessage(StrToInt(Edit5->Text));
  Edit6->Text = NMPOP31->MailMessage->From;
  Edit7->Text = NMPOP31->MailMessage->Subject;
  Edit9->Text = NMPOP31->MailMessage->MessageId;
  Memo2->Lines->Assign(NMPOP31->MailMessage->Head);
  Memo1->Lines->Assign(NMPOP31->MailMessage->Body);
  if (NMPOP31->MailMessage->Attachments->Text != "")
    ShowMessage("Attachments:\n"+NMPOP31->MailMessage->Attachments->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button6Click(TObject *Sender)
{
  NMPOP31->GetSummary(StrToInt(Edit5->Text));
  Edit6->Text = NMPOP31->Summary->From;
  Edit7->Text = NMPOP31->Summary->Subject;
  Edit8->Text = IntToStr(NMPOP31->Summary->Bytes);
  Edit9->Text = NMPOP31->Summary->MessageId;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31ConnectionRequired(bool &handled)
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
void __fastcall TFormMain::NMPOP31Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31Failure(TObject *Sender)
{
  ShowMessage("Operation failed");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    //ShowMessage(NewHost);
    NMPOP31->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31List(int Msg, int Size)
{
  if (Msg < 2)
  {
    Memo3->Clear();
    Memo3->Lines->Add("Message Number / Message Size");
  }
  Memo3->Lines->Add(IntToStr(Msg)+" / "+IntToStr(Size));
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31PacketRecvd(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMPOP31->BytesRecvd)+" bytes of "+IntToStr(NMPOP31->BytesTotal)+" Received";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31Reset(TObject *Sender)
{
  ShowMessage("Delete Flags Reset");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31RetrieveEnd(TObject *Sender)
{
  Cursor = crDefault;
  StatusBar1->SimpleText = "Retrieval complete";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31RetrieveStart(TObject *Sender)
{
  Cursor = crHourGlass;
  StatusBar1->SimpleText = "Beginning message retrieval";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMPOP31Success(TObject *Sender)
{
  StatusBar1->SimpleText = "Operation Successful";	
}
//---------------------------------------------------------------------------





