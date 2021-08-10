//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClientMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// Any data received from the client is added as a text line in the ListBox
void __fastcall TForm2::btnGoClick(TObject *Sender)
{
     TCPClient->Connect();

     try
     {
          lstMain->Items->Add(TCPClient->ReadLn());
     }
     __finally
     {
          TCPClient->Disconnect();
     }
}
//---------------------------------------------------------------------------
