//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Event2.h"
#include "Event1.h"
//---------------------------------------------------------------------------
#pragma link "ibreg"
#pragma resource "*.dfm"
TfrmEvents *frmEvents;
//---------------------------------------------------------------------------
__fastcall TfrmEvents::TfrmEvents(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmEvents::FormDestroy(TObject *Sender)
{
   dmEvents->Database1->Close();
   GroupBox2->Enabled = False;
   GroupBox3->Enabled = False;
   GroupBox4->Enabled = False;
   Label1->Enabled = False;
   btnGenerateEvent->Enabled = False;
   btnRegisterEvents->Enabled = False;
   btnClearEvents->Enabled = False;
}
//---------------------------------------------------------------------
void __fastcall TfrmEvents::btnOpenDatabaseClick(TObject *Sender)
{
   dmEvents->Database1->Open();
   GroupBox2->Enabled = True;
   GroupBox3->Enabled = True;
   GroupBox4->Enabled = True;
   Label1->Enabled = True;
   btnGenerateEvent->Enabled = True;
   btnRegisterEvents->Enabled = True;
   btnClearEvents->Enabled = True;
   btnCloseDatabase->Enabled = True;
   btnOpenDatabase->Enabled = False;
}
//---------------------------------------------------------------------
void __fastcall TfrmEvents::btnCloseDatabaseClick(TObject *Sender)
{
   dmEvents->Database1->Open();
   GroupBox2->Enabled = False;
   GroupBox3->Enabled = False;
   GroupBox4->Enabled = False;
   Label1->Enabled = False;
   btnGenerateEvent->Enabled = False;
   btnRegisterEvents->Enabled = False;
   btnClearEvents->Enabled = False;
   btnCloseDatabase->Enabled = False;
   btnOpenDatabase->Enabled = True;
}
//---------------------------------------------------------------------
void __fastcall TfrmEvents::btnGenerateEventClick(TObject *Sender)
{
   dmEvents->Database1->StartTransaction();
   dmEvents->StoredProc1->Prepare();
   dmEvents->StoredProc1->Params->Items[0]->AsString = ebEvent->Text;
   dmEvents->StoredProc1->ExecProc();
   dmEvents->Database1->Commit();
}
//---------------------------------------------------------------------
void __fastcall TfrmEvents::btnRegisterEventsClick(TObject *Sender)
{
   dmEvents->IBEventAlerter1->UnRegisterEvents();
   dmEvents->IBEventAlerter1->Events->Assign(moRegister->Lines);
   dmEvents->IBEventAlerter1->RegisterEvents();
}
//---------------------------------------------------------------------
void __fastcall TfrmEvents::btnClearEventsClick(TObject *Sender)
{
   lbReceived->Clear();  
}
//---------------------------------------------------------------------
