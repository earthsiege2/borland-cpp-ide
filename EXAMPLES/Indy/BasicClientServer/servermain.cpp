//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmServer *frmServer;
//---------------------------------------------------------------------------
__fastcall TfrmServer::TfrmServer(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmServer::FormCreate(TObject *Sender)
{
     TCPServer->Active = True;        
}
//---------------------------------------------------------------------------
// Any client that makes a connection is sent a simple message, then
// disconnected.
void __fastcall TfrmServer::TCPServerExecute(TIdPeerThread *AThread)
{
     AThread->Connection->WriteLn("Hello from Basic Indy Server server.");
     AThread->Connection->Disconnect();        
}
//---------------------------------------------------------------------------
