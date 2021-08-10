//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "menu.h"
#include "list.h"
#include "grplist.h"
#include "md.h"
#include "manygrp.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TMainForm::SetReport(TQuickRep * Value)
{
	FReport = Value;
   Description->Lines->Assign(Report->Description);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
	if (Description->Lines->Count == 0)
        	SimpleListClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SimpleListClick(TObject *Sender)
{
	Report = ListForm->QuickRep;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GroupedListClick(TObject *Sender)
{
	Report = GrpListForm->QuickRep;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MasterDetailClick(TObject *Sender)
{
	Report = MDForm->QuickRep;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SQLMasterDetailClick(TObject *Sender)
{
	Report = ManyGrpForm->QuickRep;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CompositeClick(TObject *Sender)
{
  Report = CompositeReport;	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::QRCompositeReport1AddReports(TObject *Sender)
{
	QRCompositeReport1->Reports->Add(ListForm->QuickRep);	
	QRCompositeReport1->Reports->Add(GrpListForm->QuickRep);	
	QRCompositeReport1->Reports->Add(MDForm->QuickRep);	
	QRCompositeReport1->Reports->Add(ManyGrpForm->QuickRep);	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExitClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintClick(TObject *Sender)
{
	if (Report == CompositeReport)
   	QRCompositeReport1->Print();
   else
   	Report->Print();	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PreviewClick(TObject *Sender)
{
	if (Report == CompositeReport)
   	QRCompositeReport1->Preview();
   else
   	Report->Preview();	
}
//---------------------------------------------------------------------------

