//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "msgmain.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Edit1KeyPress(TObject *Sender, char &Key)
{
  if (Key == 13)
  {
    NMMsg1->Host = Edit3->Text;
    NMMsg1->FromName = Edit2->Text;
    NMMsg1->PostIt(Edit1->Text);
  }  
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMSGServ1MSG(TComponent *Sender,
	const AnsiString sFrom, const AnsiString sMsg)
{
  Memo1->Lines->Add(sFrom+"::"+sMsg);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMSGServ1ClientContact(TObject *Sender)
{
  NMMSGServ1->ReportLevel = Status_Basic;
  NMMSGServ1->TimeOut = 90000;
  StatusBar1->SimpleText = "Client connected";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMSGServ1Status(TComponent *Sender, AnsiString Status){
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1MessageSent(TObject *Sender)
{
  ShowMessage("Message Sent");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    //ShowMessage(NewHost);
    NMMsg1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMMsg1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";
}
//---------------------------------------------------------------------------

