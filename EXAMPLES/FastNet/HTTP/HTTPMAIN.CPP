//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "httpmain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
  NMHTTP1->TimeOut = 5000;
  NMHTTP1->InputFileMode = false;
  NMHTTP1->OutputFileMode = false;
  NMHTTP1->ReportLevel = Status_Basic;
  if (CheckBox1->Checked)
  {
    NMHTTP1->Proxy = Edit11->Text;
    NMHTTP1->ProxyPort = StrToInt(Edit12->Text);
  }
  NMHTTP1->HeaderInfo->Cookie = Edit5->Text;
  NMHTTP1->HeaderInfo->LocalMailAddress = Edit6->Text;
  NMHTTP1->HeaderInfo->LocalProgram = Edit7->Text;
  NMHTTP1->HeaderInfo->Referer = Edit8->Text;
  NMHTTP1->HeaderInfo->UserId = Edit9->Text;
  NMHTTP1->HeaderInfo->Password = Edit10->Text;
  NMHTTP1->Get(Edit1->Text);
  Memo1->Text = NMHTTP1->Body;
  Memo2->Text = NMHTTP1->Header;
  if (NMHTTP1->CookieIn != "")
    ShowMessage("Cookie:\n"+NMHTTP1->CookieIn);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender)
{
  NMHTTP1->Abort();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SpeedButton1Click(TObject *Sender)
{
  Memo1->Clear();
  Memo2->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  NMHTTP1->TimeOut = 5000;
  NMHTTP1->InputFileMode = false;
  NMHTTP1->OutputFileMode = false;
  NMHTTP1->ReportLevel = Status_Basic;
  if (CheckBox1->Checked)
  {
    NMHTTP1->Proxy = Edit11->Text;
    NMHTTP1->ProxyPort = StrToInt(Edit12->Text);
  }
  NMHTTP1->HeaderInfo->Cookie = Edit5->Text;
  NMHTTP1->HeaderInfo->LocalMailAddress = Edit6->Text;
  NMHTTP1->HeaderInfo->LocalProgram = Edit7->Text;
  NMHTTP1->HeaderInfo->Referer = Edit8->Text;
  NMHTTP1->HeaderInfo->UserId = Edit9->Text;
  NMHTTP1->HeaderInfo->Password = Edit10->Text;
  NMHTTP1->Post(Edit2->Text, Edit3->Text);
  Memo3->Text = NMHTTP1->Header;
  Memo4->Text = NMHTTP1->Body;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SpeedButton2Click(TObject *Sender)
{
  Memo3->Clear();
  Memo4->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
  NMHTTP1->TimeOut = 5000;
  NMHTTP1->InputFileMode = false;
  NMHTTP1->OutputFileMode = false;
  NMHTTP1->ReportLevel = Status_Basic;
  if (CheckBox1->Checked)
  {
    NMHTTP1->Proxy = Edit11->Text;
    NMHTTP1->ProxyPort = StrToInt(Edit12->Text);
  }
  NMHTTP1->HeaderInfo->Cookie = Edit5->Text;
  NMHTTP1->HeaderInfo->LocalMailAddress = Edit6->Text;
  NMHTTP1->HeaderInfo->LocalProgram = Edit7->Text;
  NMHTTP1->HeaderInfo->Referer = Edit8->Text;
  NMHTTP1->HeaderInfo->UserId = Edit9->Text;
  NMHTTP1->HeaderInfo->Password = Edit10->Text;
  NMHTTP1->Head(Edit4->Text);
  Memo5->Text = NMHTTP1->Header;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SpeedButton3Click(TObject *Sender)
{
  Memo5->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1Failure(CmdType Cmd)
{
  switch(Cmd)
  {
    case CmdGET: StatusBar1->SimpleText = "Get Failed"; break;
    case CmdOPTIONS: StatusBar1->SimpleText = "Options Failed"; break;
    case CmdHEAD: StatusBar1->SimpleText = "Head Failed"; break;
    case CmdPOST: StatusBar1->SimpleText = "Post Failed"; break;
    case CmdPUT: StatusBar1->SimpleText = "Put Failed"; break;
    case CmdPATCH: StatusBar1->SimpleText = "Patch Failed"; break;
    case CmdCOPY: StatusBar1->SimpleText = "Copy Failed"; break;
    case CmdMOVE: StatusBar1->SimpleText = "Move Failed"; break;
    case CmdDELETE: StatusBar1->SimpleText = "Delete Failed"; break;
    case CmdLINK: StatusBar1->SimpleText = "Link Failed"; break;
    case CmdUNLINK: StatusBar1->SimpleText = "UnLink Failed"; break;
    case CmdTRACE: StatusBar1->SimpleText = "Trace Failed"; break;
    case CmdWRAPPED: StatusBar1->SimpleText = "Wrapped Failed"; break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    NMHTTP1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1PacketRecvd(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMHTTP1->BytesRecvd)+" bytes of "+IntToStr(NMHTTP1->BytesTotal)+" received";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1PacketSent(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMHTTP1->BytesSent)+" bytes of "+IntToStr(NMHTTP1->BytesTotal)+" sent";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1Status(TComponent *Sender,
      AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMHTTP1Success(CmdType Cmd)
{
  switch(Cmd)
  {
    case CmdGET: StatusBar1->SimpleText = "Get Success"; break;
    case CmdOPTIONS: StatusBar1->SimpleText = "Options Success"; break;
    case CmdHEAD: StatusBar1->SimpleText = "Head Success"; break;
    case CmdPOST: StatusBar1->SimpleText = "Post Success"; break;
    case CmdPUT: StatusBar1->SimpleText = "Put Success"; break;
    case CmdPATCH: StatusBar1->SimpleText = "Patch Success"; break;
    case CmdCOPY: StatusBar1->SimpleText = "Copy Success"; break;
    case CmdMOVE: StatusBar1->SimpleText = "Move Success"; break;
    case CmdDELETE: StatusBar1->SimpleText = "Delete Success"; break;
    case CmdLINK: StatusBar1->SimpleText = "Link Success"; break;
    case CmdUNLINK: StatusBar1->SimpleText = "UnLink Success"; break;
    case CmdTRACE: StatusBar1->SimpleText = "Trace Success"; break;
    case CmdWRAPPED: StatusBar1->SimpleText = "Wrapped Success"; break;
  }
}
//---------------------------------------------------------------------------



