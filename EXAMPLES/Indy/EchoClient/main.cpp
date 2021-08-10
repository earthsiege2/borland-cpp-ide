//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformEchoTest *formEchoTest;
//---------------------------------------------------------------------------
__fastcall TformEchoTest::TformEchoTest(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformEchoTest::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
     IdEcoTestConnection->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TformEchoTest::btnConnectClick(TObject *Sender)
{
     try
     {
          IdEcoTestConnection->Connect();
          // we can only echo after we connect to the server
          edtSendText->Enabled = True;
          edtSendText->Color = clWhite;
          btnConnect->Enabled = False;
          btnDisconnect->Enabled = True;
     }
     catch(...)
     {
          IdEcoTestConnection->Disconnect();
     } // end try...catch
}
//---------------------------------------------------------------------------

void __fastcall TformEchoTest::btnDisconnectClick(TObject *Sender)
{
     IdEcoTestConnection->Disconnect();
     btnConnect->Enabled = True;
     edtSendText->Enabled = False;
     edtSendText->Color = clSilver;
     btnDisconnect->Enabled = False;
}
//---------------------------------------------------------------------------

void __fastcall TformEchoTest::edtEchoServerChange(TObject *Sender)
{
     IdEcoTestConnection->Host = edtEchoServer->Text;
}
//---------------------------------------------------------------------------

void __fastcall TformEchoTest::Button1Click(TObject *Sender)
{
     // This echoes the text to the server
     lablReceived->Caption = IdEcoTestConnection->Echo(edtSendText->Text);
     // This displays the roundtrip time
     lablTime->Caption = IntToStr(IdEcoTestConnection->EchoTime);
}
//---------------------------------------------------------------------------

