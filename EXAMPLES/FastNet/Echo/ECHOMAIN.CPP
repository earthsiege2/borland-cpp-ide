//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "echomain.h"
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

void __fastcall TFormMain::NMEcho1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";        
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NMEcho1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");        
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NMEcho1ConnectionRequired(bool &handled)
{
  AnsiString BoxCaption;
  AnsiString BoxMsg;
  BoxCaption = "Connection Required";
  BoxMsg = "Connection Required. Connect?";
  if (MessageBox(0, &BoxMsg[1], &BoxCaption[1], MB_YESNO + MB_ICONEXCLAMATION) == IDYES)
  {
    handled = true;
    Button2Click(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  NMEcho1->ReportLevel = Status_Basic;
  NMEcho1->TimeOut = 20000;
  NMEcho1->Host = Edit2->Text;
  NMEcho1->Port = StrToInt(Edit3->Text);
  NMEcho1->Connect();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
  NMEcho1->Disconnect();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject *Sender)
{
  Edit4->Text = NMEcho1->Echo(Edit1->Text);
  Label2->Caption = "Elapsed Time: "+FloatToStr(NMEcho1->ElapsedTime)+" milliseconds";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender)
{
  NMEcho1->Abort();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMEcho1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMEcho1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host resolved";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMEcho1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    NMEcho1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMEcho1Status(TComponent *Sender,
      AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;        
}
//---------------------------------------------------------------------------
