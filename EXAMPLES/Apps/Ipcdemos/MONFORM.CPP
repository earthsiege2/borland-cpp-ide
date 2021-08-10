//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
// Interprocess Communication Demo
//
//  This program along with the Client.dpr project, demonstrate a number
//  of topics in Win32 programming. Threads, Events, Mutexes, and Shared
//  memory are all used to provide communication between this monitor and
//  it's clients, see IPCThrd.pas.
//
//  To Run, compile this project and the Client.cpp project.  Run one
//  instance of the monitor and then run several instances of the client.
//  You can switch between clients by clicking on the Client's window or
//  by selecting it from the Client menu in the monitor.
//
//  Topics Covered:
//
//    Interprocess Communication
//    Threads
//    Events
//    Mutexes
//    Shared Memory
//    Single instance EXE.
//
//---------------------------------------------------------------------------
#include "Monform.h"
#include "TrcView.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TMonitorForm *MonitorForm;
__fastcall  TMonitorForm::TMonitorForm(TComponent *Owner):TForm(Owner)
{
}

/* Private Routines */

void __fastcall TMonitorForm::ClearLabels()
{
  int Index;

  for (Index = cfError; Index <= cfAttach; Index++)
  {
    TraceLabels[Index].YLabel->Caption = 0;
    TraceLabels[Index].XLabel->Caption = 0;
  }
}

void __fastcall TMonitorForm::OnConnect(TIPCThread* Sender, Boolean Connecting)
{
  if (Connecting)
  {
    FStatusText = IPCMonitor->ClientName;
    SignalClientStatus();
  }
  else
    FStatusText = "No Client";
  PostMessage(Handle, WM_UPDATESTATUS, 0, 0);
}

/* When a client starts or stops we need to update the client menu.
  We do this by posting a message to the Monitor Form, which in turn causes
  the UpdateClientMenu method to be invoked.  We use this approach, rather than
  calling UpdateClientMenu directly because this code is not being executed
  by the main thread, but rather by the thread used in the TMonitorThread
  class.  We could also have used the TThread.Synchonize method, but since
  there is no need for the IPC thread to wait for the monitor to update
  the menu, this approach is more effecient. */

void __fastcall TMonitorForm::OnDirectoryUpdate(TIPCThread *Sender)
{
  PostMessage(Handle, WM_UPDATEMENU, 0, 0);
}

/* This event is triggered when the client has new data for us.  As with
  the OnDirectoryUpdate event above, we use PostMessage to get the main
  thread to update the display. */

void __fastcall TMonitorForm::OnSignal(TIPCThread *Sender, const TEventData &Data)
{
  FTraceMsg.X = Data.X;
  FTraceMsg.Y = Data.Y;
  FTraceMsg.Flag = Data.Flag;
  PostMessage(Handle,
              WM_SETTRACEDATA,
              FTraceMsg.X,
              FTraceMsg.Y);
}

void __fastcall TMonitorForm::SignalClientStatus()
{
  if (PauseButton->Down == true){
    TClientFlags NoFlags;
    IPCMonitor->SignalClient(NoFlags);
  }
  else
    IPCMonitor->SignalClient(FClientData.Flags);
}

void __fastcall TMonitorForm::UpdateTraceData(TWMTraceData* Msg)
{
   if (FClientData.Flags.Contains(FTraceMsg.Flag))
    {
      TraceLabels[FTraceMsg.Flag].XLabel->Caption = String((int)Msg->X);
      TraceLabels[FTraceMsg.Flag].YLabel->Caption = String((int)Msg->Y);
    }
}

void __fastcall TMonitorForm::UpdateStatusBar(TMessage* Msg)
{
  StatusBar->SimpleText = FStatusText;
  ClearLabels();
}

void __fastcall TMonitorForm::UpdateClientMenu(TMessage* Msg)
{
  int  I;
  int  ID;
  TStringList* List = new TStringList();
  TMenuItem*  mi;

  IPCMonitor->GetClientNames(List);
  while (miClients->Count > 0) {
    miClients->Delete(0);
  }
  if (List->Count == 0)
    miClients->Add(NewItem("(None)", 0, False, False, NULL, 0, ""));
  else
    for(I=0; I < List->Count; I++)
    {
      ID = (int)List->Objects[I];
      mi = NewItem(List->Strings[I], 0, False, True, ClientMenuClick, 0, "");
      mi->Tag = ID;
      mi->RadioItem = True;
      mi->GroupIndex = 1;
      miClients->Add(mi);
    }
  delete List;
}

/* Event Handlers */

void __fastcall TMonitorForm::SetupLabelArray()
{
    TraceLabels[cfMouseMove].XLabel = MoveX;
    TraceLabels[cfMouseMove].YLabel = MoveY;
    TraceLabels[cfMouseDown].XLabel = DownX;
    TraceLabels[cfMouseDown].YLabel = DownY;
    TraceLabels[cfResize].XLabel = SizeX;
    TraceLabels[cfResize].YLabel = SizeY;
}

void __fastcall TMonitorForm::FormCreate(TObject* Sender)
{
  IPCMonitor = new TIPCMonitor((int)Application->Handle, "Monitor");
  IPCMonitor->OnSignal = OnSignal;
  IPCMonitor->OnConnect = OnConnect;
  IPCMonitor->OnDirectoryUpdate = OnDirectoryUpdate;
  IPCMonitor->Activate();
  OnDirectoryUpdate(NULL);
  OnConnect(NULL, False);
  FClientData.Flags << cfMouseMove << cfMouseDown << cfResize;
  SetupLabelArray();
}

void __fastcall TMonitorForm::FormDestroy( TObject* Sender)
{
  IPCMonitor->Free();
}

void __fastcall TMonitorForm::ClientMenuClick( TObject* Sender)
{
  int  NewID;

  NewID = (int)((TMenuItem*)Sender)->Tag;
  if (NewID != IPCMonitor->ClientID)
    IPCMonitor->ClientID = NewID;
}

void __fastcall TMonitorForm::miClientsClick(TObject* Sender)
{
 int  I;

  if (IPCMonitor->ClientID != 0)
    for(I=0; I < miClients->Count; I++)
      if (miClients->Items[I]->Tag == IPCMonitor->ClientID)
      {
         miClients->Items[I]->Checked = True;
         break;
      }
}

void __fastcall TMonitorForm::SetTraceFlags( TObject* Sender)
{
 TClientFlag  F;

  F = (TClientFlag)((TCheckBox*)Sender)->Tag;
  if (((TCheckBox*)Sender)->Checked)
        FClientData.Flags << F;
  else
        FClientData.Flags >> F;

  SignalClientStatus();
}

void __fastcall TMonitorForm::AutoClientSwitch1Click( TObject* Sender)
{
    ((TMenuItem*)Sender)->Checked = ! ((TMenuItem*)Sender)->Checked;
    IPCMonitor->AutoSwitch = ((TMenuItem*)Sender)->Checked;
}

void __fastcall TMonitorForm::miFileExitClick( TObject* Sender)
{
  Close();
}

void __fastcall TMonitorForm::ShowTraceButtonClick( TObject* Sender)
{
  IPCMonitor->GetDebugInfo(TraceForm->TraceData->Items);
  TraceForm->ShowModal();
}

void __fastcall TMonitorForm::PauseButtonClick( TObject* Sender)
{
  SignalClientStatus();
}

void __fastcall TMonitorForm::ClearButtonClick( TObject* Sender)
{
  IPCMonitor->ClearDebugInfo();
}

void __fastcall TMonitorForm::ExitButtonClick( TObject* Sender)
{
  Close();
}

void __fastcall TMonitorForm::About1Click( TObject* Sender)
{
  ShowAboutBox();
}


