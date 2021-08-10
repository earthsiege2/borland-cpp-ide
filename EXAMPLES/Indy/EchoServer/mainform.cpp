//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// No coding is required.  Echo server is ready to go by setting Active to True.
void __fastcall TForm1::FormActivate(TObject *Sender)
{
     try
     {
          IdECHOServer1->Active = True;
     }
     catch(...)
     {
          ShowMessage("Permission Denied.  Cannot bind reserved port due to security reasons");
          Application->Terminate();
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnExitClick(TObject *Sender)
{
     if(IdECHOServer1->Active)
     {
          IdECHOServer1->Active = True;
     }
     Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdECHOServer1Connect(TIdPeerThread *AThread)
{
     lblStatus->Caption = "[ Serving client ]";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdECHOServer1Disconnect(TIdPeerThread *AThread)
{
     lblStatus->Caption = "[ idle - waiting next client ]";
}
//---------------------------------------------------------------------------

