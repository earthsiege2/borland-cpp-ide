//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "timemain.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMTime1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMTime1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMTime1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMTime1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMTime1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMTime1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    //ShowMessage(NewHost);
    NMTime1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject *Sender)
{
  NMTime1->Host = Edit1->Text;
  NMTime1->Port = StrToInt(Edit2->Text);
  Label3->Caption = "The Current Time is : "+NMTime1->TimeStr;
}
//--------------------------------------------------------------------------- 