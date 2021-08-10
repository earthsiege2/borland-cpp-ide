//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
/* This program works in conjunction with the Monitor.mak project to demonstrate
  advanced Win32 programming topics.  See Monform.cpp for more information */
//--------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//--------------------------------------------------------------------------
#include "clntform.h"

#pragma resource "*.DFM"

TClientForm*  ClientForm;
__fastcall TClientForm::TClientForm(TComponent* Owner) : TForm(Owner)
{
}

void __fastcall TClientForm::FormCreate(TObject* Sender)
{
  int  CNo, VCnt;

  String buf(Application->Title);
  buf += " ";
  buf += (int)GetCurrentProcessId();

  Caption = buf;

  try {
    IPCClient = new TIPCClient(GetCurrentProcessId(), Caption);
    IPCClient->OnConnect = OnConnect;
    IPCClient->OnSignal = OnSignal;
    IPCClient->Activate();
    if (! (IPCClient->State == stConnected))
      OnConnect(NULL, false);
    VCnt = Screen->Height / (Height + 10);
    CNo = IPCClient->ClientCount() - 1;
    Top = (CNo % VCnt) * (Height + 10) + 10;
    Left = (Screen->Width / 2) + (CNo / VCnt) * (Width + 10);
  }
  catch(...){
    Application->Terminate();
  }
}

void __fastcall TClientForm::FormDestroy( TObject* Sender)
{
  IPCClient->Free();
}

void __fastcall TClientForm::OnConnect(TIPCThread* Sender, bool Connecting)
{
  PostMessage(Handle, WM_UPDATESTATUS, WPARAM(Connecting), 0);
}

void __fastcall TClientForm::OnSignal(TIPCThread* Sender, const TEventData &Data)
{
  Flags = Data.Flags;
}

void __fastcall TClientForm::FormMouseMove( TObject* Sender,
                                            TShiftState Shift,
                                            int X, int  Y)
{
  TEventData  EventData;

  if (Flags.Contains(cfMouseMove) == true){
      EventData.X = (short) X;
      EventData.Y = (short) Y;
      EventData.Flag = cfMouseMove;
      IPCClient->SignalMonitor(EventData);
  }
}

void __fastcall TClientForm::FormMouseDown( TObject* Sender,
                                            TMouseButton Button,
                                            TShiftState  Shift,
                                            int X, int Y)
{
  TEventData  EventData;

  if (Flags.Contains(cfMouseMove) == true) {
      EventData.X = (short) X;
      EventData.Y = (short) Y;
      EventData.Flag = cfMouseDown;
      IPCClient->SignalMonitor(EventData);
  }
}

void __fastcall TClientForm::FormResize(TObject* Sender)
{
  TEventData  EventData;

  if (Flags.Contains(cfResize) == true){
      EventData.X = (short) Width;
      EventData.Y = (short) Height;
      EventData.Flag = cfResize;
      IPCClient->SignalMonitor(EventData);
  }
}

void __fastcall TClientForm::FormClick(TObject* Sender)
{
  if (IPCClient->State != stConnected)
      IPCClient->MakeCurrent();
}

void __fastcall TClientForm::UpdateStatusBar(TMessage* Msg)
{
  PChar ConnectStr[2] = {"Not Connected", "Connected"};

  StatusBar->SimpleText = ConnectStr[Msg->WParam];
}

