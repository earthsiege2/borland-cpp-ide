//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "strmmain.h"
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
  if (OpenPictureDialog1->Execute())
  {
    TFileStream *MyFStream;
    MyFStream = new TFileStream(OpenPictureDialog1->FileName, fmOpenRead);
    try
    {
      NMStrm1->Host = Edit2->Text;
      NMStrm1->FromName = Edit1->Text;
      NMStrm1->PostIt(MyFStream);
    }
    catch(...)
    {
    }
    MyFStream->Free();
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  Image1->Picture->LoadFromFile(".\\tmp.bmp");        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1MessageSent(TObject *Sender)
{
  ShowMessage("Stream sent");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1PacketSent(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMStrm1->BytesRecvd)+" bytes of "+NMStrm1->BytesTotal+" sent";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1Status(TComponent *Sender,
      AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrm1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    NMStrm1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrmServ1ClientContact(TObject *Sender)
{
  StatusBar1->SimpleText = "Client Contacted";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrmServ1MSG(TComponent *Sender,
      const AnsiString sFrom, TStream *strm)
{
  if (FileExists(".\\tmp.bmp"))
    DeleteFile(".\\tmp.bmp");
  TFileStream *MyFStream;
  MyFStream = new TFileStream(".\\tmp.bmp", fmCreate);
  try
  {
    MyFStream->CopyFrom(strm, strm->Size);
  }
  catch(...)
  {
  }
  MyFStream->Free();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMStrmServ1Status(TComponent *Sender,
      AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------






