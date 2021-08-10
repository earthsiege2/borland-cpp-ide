//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// No code required - TimeServer is functional as is.
void __fastcall TfrmMain::FormActivate(TObject *Sender)
{
     try
     {
          IdTimeServer1->Active = True;
     }
     catch(...)
     {
          ShowMessage("Permission Denied.  Cannot bind reserved port due to security reasons");
          Application->Terminate();
     }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::IdTimeServer1Connect(TIdPeerThread *AThread)
{
     lblStatus->Caption = "[ Client connected ]";        
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::IdTimeServer1Disconnect(TIdPeerThread *AThread)
{
     lblStatus->Caption = "[ idle ]";        
}
//---------------------------------------------------------------------------
