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
void __fastcall TfrmMain::tmrRefreshTimer(TObject *Sender)
{
     if(Slave->Active)
     {
          lblClients->Caption = IntToStr(Slave->NumClients);
     }

     if(Master->Active)
     {
          lblSlaves->Caption = IntToStr(Master->NumSlaves);
          lblServices->Caption = IntToStr(Master->NumServices);
     }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnStartClick(TObject *Sender)
{
     btnStart->Enabled = False;
     btnStop->Enabled = True;
     Master->Active = True;
     Idglobal::Sleep(100);
     Slave->Active = True;
     tmrRefresh->Enabled = True;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnStopClick(TObject *Sender)
{
     tmrRefresh->Enabled = False;
     btnStart->Enabled = True;
     btnStop->Enabled = False;
     Slave->Active = False;
     lblClients->Caption = "0";
     Idglobal::Sleep(100);  // only for Master to realize that something happened before
     // printing to the screen.  It is not needed in real app.

     if(Master->Active)
     {
          lblSlaves->Caption = IntToStr(Master->NumSlaves);
          lblServices->Caption = IntToStr(Master->NumServices);
     }

     Master->Active = False;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
     Master = new TIdTunnelMaster(this);
     Master->MappedHost = "127.0.0.1";
     Master->MappedPort = 80;
     Master->LockDestinationHost = True;
     Master->LockDestinationPort = True;
     Master->DefaultPort = 9000;
     Master->Bindings->Add();

     Slave = new TIdTunnelSlave(this);
     Slave->MasterHost = "127.0.0.1";
     Slave->MasterPort = 9000;
     Slave->Socks4 = False;
     Slave->DefaultPort = 8080;
     Slave->Bindings->Add();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormDestroy(TObject *Sender)
{
     Slave->Active = False;
     Master->Active = False;
     Idglobal::Sleep(100);
     delete Slave;
     delete Master;
}
//---------------------------------------------------------------------------
