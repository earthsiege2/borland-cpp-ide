//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Frmtrigg.h"
#include "DmCSDemo.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrmTriggerDemo *FrmTriggerDemo;
//---------------------------------------------------------------------------
__fastcall TFrmTriggerDemo::TFrmTriggerDemo(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmTriggerDemo::FormShow(TObject *Sender)
{
  DmEmployee->EmployeeTable->Open();
  DmEmployee->SalaryHistoryTable->Open();

}
//---------------------------------------------------------------------