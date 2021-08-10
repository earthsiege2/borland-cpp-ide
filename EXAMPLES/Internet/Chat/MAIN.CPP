//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma link "ScktComp"
#pragma resource "*.dfm"
TChatForm *ChatForm;
//---------------------------------------------------------------------------
__fastcall TChatForm::TChatForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TChatForm::FileListenItemClick(TObject *Sender)
{
  FileListenItem->Checked = !FileListenItem->Checked;
  if (FileListenItem->Checked)
  {
     ClientSocket->Active = false;
     ServerSocket->Active = true;
     StatusBar1->Panels->Items[0]->Text = "Listening...";
  }else
  {
     if (ServerSocket->Active)
     { 
        ServerSocket->Active = false;
     }
     StatusBar1->Panels->Items[0]->Text = "";    
  }          
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::FileConnectItemClick(TObject *Sender)
{
  if (ClientSocket->Active)
  { 
    ClientSocket->Active = false;
  }   
  if (InputQuery("Computer to connect to", "Address Name:", Server))
  {
     if (Server.Length() > 0)
     {
        ClientSocket->Host = Server;
        ClientSocket->Active = true;
        FileListenItem->Checked = false;  
     }
  }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::Exit1Click(TObject *Sender)
{
  ServerSocket->Close();
  ClientSocket->Close();
  Close();   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::Memo1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_RETURN)
  {
     if (IsServer){ServerSocket->Socket->Connections[0]->SendText(
         Memo1->Lines->Strings[Memo1->Lines->Count - 1]); }
     else
     { ClientSocket->Socket->SendText(Memo1->Lines->Strings[
        Memo1->Lines->Count -1]);}
  }   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::FormCreate(TObject *Sender)
{
  FileListenItemClick(NULL);   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ClientSocketConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  StatusBar1->Panels->Items[0]->Text = "Connect to: " + Socket->RemoteHost;   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::Disconnect1Click(TObject *Sender)
{
  ClientSocket->Active = false;
  ServerSocket->Active = true;
  StatusBar1->Panels->Items[0]->Text = "Listening...";
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
  Memo2->Lines->Add(Socket->ReceiveText());  
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ServerSocketClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
  Memo2->Lines->Add(Socket->ReceiveText());  
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ServerSocketAccept(TObject *Sender,
      TCustomWinSocket *Socket)
{
  IsServer = true;
  StatusBar1->Panels->Items[0]->Text = "Connect to: " + Socket->RemoteAddress;   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ServerSocketClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  Memo2->Lines->Clear();   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ClientSocketDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  FileListenItemClick(NULL);   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ClientSocketError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
  Memo2->Lines->Add("Error connecting to:" + Server);   
  ErrorCode = 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChatForm::ServerSocketClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  StatusBar1->Panels->Items[0]->Text = "Listening...";
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------