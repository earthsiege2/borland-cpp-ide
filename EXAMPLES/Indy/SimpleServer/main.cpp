//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
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
void __fastcall TfrmMain::btnAcceptClick(TObject *Sender)
{
     if(SServ->Listen())
     {
          SServ->WriteLn("Hello");
          SServ->Disconnect();
     }
}
//---------------------------------------------------------------------------
