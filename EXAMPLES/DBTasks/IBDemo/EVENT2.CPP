//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Event1.h"
#include "Event2.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma link "ibctrls"
#pragma resource "*.dfm"
TdmEvents *dmEvents;
//---------------------------------------------------------------------------
__fastcall TdmEvents::TdmEvents(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdmEvents::IBEventAlerter1EventAlert(TObject *Sender,
      AnsiString EventName, long EventCount, bool &CancelAlerts)
{
  frmEvents->lbReceived->Items->Add(EventName);  
}
//---------------------------------------------------------------------
void __fastcall TdmEvents::dmEventsCreate(TObject *Sender)
{
   char   szBuffer[500];

   sprintf(szBuffer, "%sEvents.gdb", ExtractFilePath(Application->ExeName).c_str());
   Database1->Params->Values["Server Name"] = szBuffer;

}
//---------------------------------------------------------------------
