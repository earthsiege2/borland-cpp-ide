//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "fngrmain.h"
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
  NMFinger1->ReportLevel = Status_Basic;
  NMFinger1->TimeOut = 20000;
  NMFinger1->Host = Edit1->Text;
  NMFinger1->Port = StrToInt(Edit2->Text);
  NMFinger1->User = Edit3->Text;
  Memo1->Text = NMFinger1->FingerStr;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFinger1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFinger1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFinger1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFinger1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFinger1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFinger1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    NMFinger1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------