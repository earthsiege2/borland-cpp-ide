//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Main.h"
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
  NMDayTime1->ReportLevel = Status_Basic;
  NMDayTime1->TimeOut = 18000;
  NMDayTime1->Host = Edit1->Text;
  NMDayTime1->Port = StrToInt(Edit2->Text);
  Label3->Caption = "The Current Date and Time is : "+NMDayTime1->DayTimeStr;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMDayTime1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMDayTime1ConnectionFailed(TObject *Sender)
{
ShowMessage("Connection Failed");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMDayTime1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMDayTime1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMDayTime1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    NMDayTime1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMDayTime1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------